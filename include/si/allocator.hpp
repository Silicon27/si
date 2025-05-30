//
// Created by David Yang on 2025-05-30.
//

#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP



namespace si {
    using size_t = unsigned long;

    template <typename T>
    class Allocator {
    public:
        using value_type = T;
        Allocator() = default;

        template <typename U>
        explicit Allocator(const Allocator<U>&) {}

        T* allocate(size_t n) {
            return static_cast<T*>(::operator new(n * sizeof(T)));
        }
        void deallocate(value_type* p, size_t n) noexcept {
            ::operator delete(p, n * sizeof(T));
        }

        template <typename U>
        struct rebind {
            using other = Allocator<U>;
        };
    };

    template <typename T, typename U>
    inline bool operator==(const Allocator<T>&, const Allocator<U>&) {
            return true;
    }

    template <typename T, typename U>
    inline bool operator!=(const Allocator<T>&, const Allocator<U>&) {
        return false;
    }
}

#endif //ALLOCATOR_HPP
