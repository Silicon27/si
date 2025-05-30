//
// Created by David Yang on 2025-05-30.
//

#ifndef VECTOR_TPP
#define VECTOR_TPP

// Vector.tpp
namespace si {

    template <typename T>
    Vector<T>::Vector(std::initializer_list<T> init)
        : _num_elements(static_cast<int>(init.size())),
          _capacity(static_cast<int>(init.size()) + 10),
          _alloc() {
        _begin = _alloc.allocate(_capacity);
        T* it = _begin;
        for (const auto &item : init) {
            std::allocator_traits<std::allocator<T>>::construct(_alloc, it, item);
            ++it;
        }
        _end = _begin + _num_elements;
    }

    template <typename T>
    Vector<T>::~Vector() {
        for (T* p = _begin; p < _end; ++p) {
            std::allocator_traits<std::allocator<T>>::destroy(_alloc, p);
        }
        _alloc.deallocate(_begin, _capacity);
    }

    template <typename T>
    void Vector<T>::push_back(std::initializer_list<T> init) {
        if (static_cast<int>(init.size()) + _num_elements > _capacity) {
            reserve((_num_elements + static_cast<int>(init.size())) * 2);
        }
        for (const auto &item : init) {
            std::allocator_traits<std::allocator<T>>::construct(_alloc, _end, item);
            ++_end;
            ++_num_elements;
        }
    }

    template <typename T>
    void Vector<T>::reserve(const int new_cap) {
        if (new_cap <= _capacity)
            return;
        T* new_block = _alloc.allocate(new_cap);

        for (int i = 0; i < _num_elements; ++i) {
            std::allocator_traits<std::allocator<T>>::construct(
                _alloc, new_block + i, std::move(_begin[i]));
            std::allocator_traits<std::allocator<T>>::destroy(_alloc, _begin + i);
        }
        _alloc.deallocate(_begin, _capacity);
        _begin = new_block;
        _end = _begin + _num_elements;
        _capacity = new_cap;
    }

    template <typename T>
    T& Vector<T>::operator[](int pos) {
        if (pos < 0 || pos >= _num_elements)
            throw std::out_of_range("Index out of range");
        return *(_begin + pos);
    }

    template <typename T>
    const T& Vector<T>::operator[](int pos) const {
        if (pos < 0 || pos >= _num_elements)
            throw std::out_of_range("Index out of range");
        return *(_begin + pos);
    }

    template <typename T>
    T* Vector<T>::begin() { return _begin; }

    template <typename T>
    T* Vector<T>::end() { return _end; }

} // namespace si

#endif //VECTOR_TPP
