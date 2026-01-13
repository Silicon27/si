//
// Created by David Yang on 2025-05-30.
//

// Vector.hpp
#ifndef SI_LIB_VECTOR_HPP
#define SI_LIB_VECTOR_HPP

#include <initializer_list>
#include "memory.hpp"
#include "utility.hpp"
#include "pointer.hpp"

namespace si {

    template <typename T>
    class vector {
    public:
        // member types
        using value_type = T;
        using allocator_type = si::allocator<T>;
        using size_type = si::size_t;
        using difference_type = ptrdiff_t;
        using reference = T&;
        using const_reference = const T&;
        using pointer = typename si::allocator_traits<allocator_type>::pointer;
        using const_pointer = typename si::allocator_traits<allocator_type>::const_pointer;
        using iterator = value_type*;


        vector(std::initializer_list<T> init);
        ~vector();

        void append(std::initializer_list<T> init);
        void push_back(const T& value);
        void reserve(const int new_cap);

        T& operator[](int pos);
        const T& operator[](int pos) const;

        T* begin();
        T* end();

        [[nodiscard]] size_t capacity() const noexcept;
        [[nodiscard]] size_t size() const noexcept;

    private:
        T* _begin;
        T* _end;
        size_t _num_elements;
        size_t _capacity;
        si::allocator<T> _alloc;
    };

} // namespace si

#include "vector.tpp"  // Include the implementation for template methods

#endif // SI_LIB_VECTOR_HPP