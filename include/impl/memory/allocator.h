//
// Created by David Yang on 2025-06-02.
//

#ifndef SI_LIB_MEMORY_ALLOCATOR_H
#define SI_LIB_MEMORY_ALLOCATOR_H

#include "../../compat/sconfig.h"

SI_NAMESPACE_START

template <typename T>
class allocator {
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using void_pointer = void*;
    using const_void_pointer = const void*;
    using size_type = size_t;
    using difference_type = ptrdiff_t;

    allocator() noexcept = default;

    template <typename U>
    explicit allocator(const allocator<U>&) {}

    [[nodiscard]] T* allocate(size_t n) {
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }
    void deallocate(value_type* p, size_t n) noexcept {
        ::operator delete(p, n * sizeof(T));
    }

    template <typename U>
    struct rebind {
        using other = allocator<U>;
    };
};

template <typename T, typename U>
bool operator==(const allocator<T>&, const allocator<U>&) {
    return true;
}

template <typename T, typename U>
bool operator!=(const allocator<T>&, const allocator<U>&) {
    return false;
}

SI_NAMESPACE_END


#endif //SI_LIB_MEMORY_ALLOCATOR_H
