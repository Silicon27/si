//
// Created by David Yang on 2025-05-30.
//

#ifndef MEMORY_HPP
#define MEMORY_HPP

namespace si {
    using size_t = unsigned long;

    template <typename T>
    class allocator {
    public:
        using value_type = T;
        allocator() = default;

        template <typename U>
        explicit allocator(const allocator<U>&) {}

        T* allocate(size_t n) {
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
}

// for allocator_traits
namespace si {
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
            ::new((void*)p) T(std::forward<Args>(args)...);
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
}

#endif //MEMORY_HPP
