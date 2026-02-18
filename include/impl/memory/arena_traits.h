//
// Created by David Yang on 2026-02-18.
//

#ifndef SI_LIB_MEMORY_ARENA_TRAITS_H
#define SI_LIB_MEMORY_ARENA_TRAITS_H

#include "../../compat/sconfig.h"

SI_NAMESPACE_START

template <typename Alloc>
class arena_traits {
    using allocator_type = Alloc;
    using value_type = typename Alloc::value_type;

    using pointer            = typename Alloc::pointer;
    using const_pointer      = typename Alloc::const_pointer;
    using void_pointer       = typename Alloc::void_pointer;
    using const_void_pointer = typename Alloc::const_void_pointer;

    using difference_type    = typename Alloc::difference_type;
    using size_type          = typename Alloc::size_type;

    template <typename T>
    using rebind_alloc = typename Alloc::template rebind<T>::other;

    template <typename T>
    using rebind_traits = arena_traits<rebind_alloc<T>>;

    static pointer allocate(allocator_type& alloc, size_type n) {
        return alloc.allocate(n);
    }

    // arenas do not have a fixed deallocation plan, more or less chunk deallocation

};

SI_NAMESPACE_END


#endif //SI_LIB_MEMORY_ARENA_TRAITS_H