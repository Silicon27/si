//
// Created by David Yang on 2026-05-02.
//

#ifndef SI_LIB_MEMORY_BUMP_POINTER_ALLOCATOR_HPP
#define SI_LIB_MEMORY_BUMP_POINTER_ALLOCATOR_HPP

#include "../../compat/sconfig.h"
#include "../../si/stddef.hpp"
#include <deque>
#include <vector>
#include <algorithm>
#include <memory>
#include <cstring>
#include <new>
#include <support/global_constants.hpp>

SI_NAMESPACE_START

struct Slab {
    char *buffer;
    char *current;
    size_t capacity;

    explicit Slab(size_t size) {
        const size_t alloc_size = (size + CACHE_LINE_SIZE - 1) & ~(CACHE_LINE_SIZE - 1);
        buffer = new (std::nothrow) char[alloc_size];
        if (!buffer) {
            std::abort();
        }
        current = buffer;
        capacity = size;
    }

    ~Slab() {
        delete[] buffer;
    }

    Slab(Slab &&other) noexcept
        : buffer(other.buffer), current(other.current), capacity(other.capacity) {
        other.buffer = nullptr;
        other.current = nullptr;
        other.capacity = 0;
    }

    Slab &operator=(Slab &&other) noexcept {
        if (this != &other) {
            delete[] buffer;
            buffer = other.buffer;
            current = other.current;
            capacity = other.capacity;
            other.buffer = nullptr;
            other.current = nullptr;
            other.capacity = 0;
        }
        return *this;
    }

    Slab(const Slab &) = delete;
    Slab &operator=(const Slab &) = delete;

    [[nodiscard]] bool is_full(size_t size = 0, size_t align = alignof(std::max_align_t)) const {
        const auto curr_addr = reinterpret_cast<uintptr_t>(current);
        const size_t padding = (align - (curr_addr % align)) % align;
        return (capacity - (current - buffer)) < (size + padding);
    }

    [[nodiscard]] size_t get_remaining_capacity() const {
        return capacity - (current - buffer);
    }

    void *allocate(size_t size, size_t align = alignof(std::max_align_t)) {
        size_t space_left = capacity - (current - buffer);
        void* ptr = current;
        void* align_ptr = std::align(align, size, ptr, space_left);
        if (!align_ptr) return nullptr;

        current = static_cast<char*>(align_ptr) + size;
        return align_ptr;
    }

    void reset() {
        current = buffer;
    }
};

template<typename VecAlloc = std::allocator<Slab>>
class bump_ptr_allocator {
    std::deque<Slab, VecAlloc> slabs;
    std::vector<size_t> partially_used_slabs;
    size_t current_slab_idx{};
    size_t slab_size;

public:
    explicit bump_ptr_allocator(size_t initial_slab_size = 1024 * 1024)
        : slab_size(initial_slab_size) {
        slabs.emplace_back(slab_size);
    }

    void *allocate(size_t size, size_t alignment = alignof(std::max_align_t),
                   size_t size_of_new_slab = 0, bool reuse_free_slab = true) {
        if (reuse_free_slab && !partially_used_slabs.empty()) {
            for (auto it = partially_used_slabs.begin(); it != partially_used_slabs.end();) {
                Slab &slab = slabs[*it];
                if (void *result = slab.allocate(size, alignment)) {
                    if (slab.get_remaining_capacity() == 0) {
                        it = partially_used_slabs.erase(it);
                    }
                    return result;
                }
                ++it;
            }
        }

        if (void *result = slabs[current_slab_idx].allocate(size, alignment)) {
            return result;
        }

        if (slabs[current_slab_idx].get_remaining_capacity() > 0) {
            partially_used_slabs.push_back(current_slab_idx);
        }

        if (size_of_new_slab == 0 && size >= slab_size) {
            slabs.emplace_back(size + alignment);
            return slabs.back().allocate(size, alignment);
        }

        const size_t new_slab_size = size_of_new_slab > 0 ? size_of_new_slab : slab_size;
        slabs.emplace_back(new_slab_size);
        current_slab_idx = slabs.size() - 1;

        if (size_of_new_slab == 0 && slab_size < 128 * 1024 * 1024) {
            slab_size *= 2;
        }

        return slabs[current_slab_idx].allocate(size, alignment);
    }

    void reset_slab(size_t idx) {
        Slab &slab = slabs[idx];
        slab.reset();

        auto it = std::find(partially_used_slabs.begin(), partially_used_slabs.end(), idx);
        if (it != partially_used_slabs.end()) {
            partially_used_slabs.erase(it);
        }
        partially_used_slabs.insert(partially_used_slabs.begin(), idx);
    }

    [[nodiscard]] int current_slab_index() const { return static_cast<int>(current_slab_idx); }
    [[nodiscard]] size_t num_slabs() const { return slabs.size(); }
    [[nodiscard]] size_t num_partially_used_slabs() const { return partially_used_slabs.size(); }

    [[nodiscard]] size_t num_allocated_bytes() const {
        size_t total = 0;
        for (const auto &slab: slabs) {
            total += slab.capacity;
        }
        return total;
    }

    [[nodiscard]] size_t num_allocated_bytes_used() const {
        size_t total = 0;
        for (const auto &slab: slabs) {
            total += slab.current - slab.buffer;
        }
        return total;
    }

    [[nodiscard]] size_t slab_sizes() const { return slab_size; }
};

SI_NAMESPACE_END

#endif //SI_LIB_MEMORY_BUMP_POINTER_ALLOCATOR_HPP
