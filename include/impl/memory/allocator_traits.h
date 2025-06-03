//
// Created by David Yang on 2025-06-03.
//

#ifndef SI_LIB_MEMORY_ALLOCATOR_TRAITS_H
#define SI_LIB_MEMORY_ALLOCATOR_TRAITS_H

#include "../../compat/sconfig.h"

SI_NAMESPACE_START

template <typename Alloc>
    struct allocator_traits {
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
    using rebind_traits = allocator_traits<rebind_alloc<T>>;

    static pointer allocate(allocator_type& alloc, size_type n) {
        return alloc.allocate(n);
    }

    static void deallocate(Alloc& a, pointer p, size_type n) {
        a.deallocate(p, n);
    }

    template <typename T, typename... Args>
    static void construct(Alloc& a, T* p, Args&&... args) {
        ::new(static_cast<void *>(p)) T(std::forward<Args>(args)...);
    }

    template <typename T>
    static void destroy(Alloc& a, T* p) {
        p->~T();
    }

    static size_type max_size(const Alloc& a) noexcept {
        return a.max_size();
    }

    static Alloc select_on_container_copy_construction(const Alloc& a) {
        return a;
    }
};

SI_NAMESPACE_END

#endif //SI_LIB_MEMORY_ALLOCATOR_TRAITS_H
