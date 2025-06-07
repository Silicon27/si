//
// Created by David Yang on 2025-05-30.
//

// Vector.hpp
#ifndef SI_VECTOR_HPP
#define SI_VECTOR_HPP

#include <initializer_list>
#include "memory.hpp"
#include "utility.hpp"

namespace si {

    template <typename T>
    class vector {
    public:
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

#endif // SI_VECTOR_HPP