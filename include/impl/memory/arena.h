//
// Created by David Yang on 2026-02-18.
//

#ifndef SI_LIB_MEMORY_ARENA_H
#define SI_LIB_MEMORY_ARENA_H

#include "../../compat/sconfig.h"
#include <si/stddef.hpp>
#include <impl/memory/align.hpp>
#include <impl/memory/offset_to_alignment.hpp>
#include <impl/iterator/reverse_iterator.hpp>


SI_NAMESPACE_START

template <typename T>
class arena {
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using void_pointer = void*;
    using const_void_pointer = const void*;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using iterator = pointer;
    using const_iterator = const_pointer;
    using reverse_iterator = si::reverse_iterator<iterator>;

    explicit arena(size_t size) {
        const size_t alloc_size = offset_to_alignment(size, sizeof(value_type));
        this->size = alloc_size;
        data = static_cast<value_type>(::operator new(alloc_size));
    }
    ~arena() {
        ::operator delete(data);
    }
private:
    size_t size;
    char* data;
};

SI_NAMESPACE_END

#endif //SI_LIB_MEMORY_ARENA_H