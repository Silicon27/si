//
// Created by David Yang on 2025-05-30.
//

// Vector.hpp
#ifndef SI_VECTOR_HPP
#define SI_VECTOR_HPP

#include <initializer_list>
#include <memory>

namespace si {

    template <typename T>
    class Vector {
    public:
        Vector(std::initializer_list<T> init);
        ~Vector();

        void push_back(std::initializer_list<T> init);
        void reserve(const int new_cap);

        T& operator[](int pos);
        const T& operator[](int pos) const;

        T* begin();
        T* end();

    private:
        T* _begin;
        T* _end;
        int _num_elements;
        int _capacity;
        std::allocator<T> _alloc;
    };

} // namespace si

#include "vector.tpp"  // Include the implementation for template methods

#endif // SI_VECTOR_HPP