//
// Created by David Yang on 2025-05-30.
//

#ifndef SI_LIB_VECTOR_TPP
#define SI_LIB_VECTOR_TPP

// Vector.tpp
namespace si {

    template <typename T>
    vector<T>::vector(std::initializer_list<T> init)
        : _num_elements(static_cast<int>(init.size())),
          _capacity(static_cast<int>(init.size()) + 10),
          _alloc() {
        _begin = _alloc.allocate(_capacity);
        T* it = _begin;
        for (const auto &item : init) {
            si::allocator_traits<si::allocator<T>>::construct(_alloc, it, item);
            ++it;
        }
        _end = _begin + _num_elements;
    }

    template <typename T>
    vector<T>::~vector() {
        for (T* p = _begin; p < _end; ++p) {
            si::allocator_traits<si::allocator<T>>::destroy(_alloc, p);
        }
        _alloc.deallocate(_begin, _capacity);
    }

    template <typename T>
    void vector<T>::append(std::initializer_list<T> init) {
        if (static_cast<int>(init.size()) + _num_elements > _capacity) {
            reserve((_num_elements + static_cast<int>(init.size())) * 2);
        }
        for (const auto &item : init) {
            si::allocator_traits<si::allocator<T>>::construct(_alloc, _end, item);
            ++_end;
            ++_num_elements;
        }
    }

    template <typename T>
    void vector<T>::push_back(const T& value) {
        if (_num_elements + 1 > _capacity) {
            reserve(_capacity * 2);
        }
        si::allocator_traits<si::allocator<T>>::construct(_alloc, _end, value);
        ++_end;
    }

    template <typename T>
    void vector<T>::reserve(const int new_cap) {
        if (new_cap <= _capacity)
            return;
        T* new_block = _alloc.allocate(new_cap);

        for (int i = 0; i < _num_elements; ++i) {
            si::allocator_traits<si::allocator<T>>::construct(
                _alloc, new_block + i, si::move(_begin[i]));
            si::allocator_traits<si::allocator<T>>::destroy(_alloc, _begin + i);
        }
        _alloc.deallocate(_begin, _capacity);
        _begin = new_block;
        _end = _begin + _num_elements;
        _capacity = new_cap;
    }

    template <typename T>
    T& vector<T>::operator[](int pos) {
        if (pos < 0 || pos >= _num_elements)
            throw std::out_of_range("Index out of range");
        return *(_begin + pos);
    }

    template <typename T>
    const T& vector<T>::operator[](int pos) const {
        if (pos < 0 || pos >= _num_elements)
            throw std::out_of_range("Index out of range");
        return *(_begin + pos);
    }

    template <typename T>
    T* vector<T>::begin() { return _begin; }

    template <typename T>
    T* vector<T>::end() { return _end; }

    template <typename T>
    [[nodiscard]] size_t vector<T>::capacity() const noexcept {
        return _capacity;
    }

    template <typename T>
    [[nodiscard]] size_t vector<T>::size() const noexcept {
        return _num_elements;
    }
} // namespace si

#endif //SI_LIB_VECTOR_TPP
