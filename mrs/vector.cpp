#include <iostream>
#include <memory>

namespace mrs { // MyRandomShit
template <typename T> class Vector {
public:
  Vector(std::initializer_list<T> init)
      : _alloc(), _num_elements(init.size()), _capacity(init.size() + 10) {
    _begin = _alloc.allocate(_capacity);
    T *it = _begin;
    for (const auto &item : init) {
      std::allocator_traits<std::allocator<T>>::construct(_alloc, it, item);
      ++it;
    }
    _end = _begin + _num_elements;
  }

  ~Vector() {
    for (T *p = _begin; p < _end; ++p) {
      std::allocator_traits<std::allocator<T>>::destroy(_alloc, p);
    }
    _alloc.deallocate(_begin, _capacity);
  }

  void push_back(std::initializer_list<T> init) {
    if (init.size() + _num_elements > _capacity) {
      reserve((_num_elements + init.size()) * 2);
    }
    for (const auto &item : init) {
      std::allocator_traits<std::allocator<T>>::construct(_alloc, _end, item);
      ++_end;
      ++_num_elements;
    }
  }

  void reserve(const int new_cap) {
    if (new_cap <= _capacity)
      return;
    T *new_block = _alloc.allocate(new_cap);

    for (int i = 0; i < _num_elements; ++i) {
      std::allocator_traits<std::allocator<T>>::construct(
          _alloc, new_block + i, std::move(this->_begin[i]));
      std::allocator_traits<std::allocator<T>>::destroy(_alloc,
                                                        this->_begin + i);
    }
    _alloc.deallocate(_begin, _capacity);
    _begin = new_block;
    _end = _begin + _num_elements;
    _capacity = new_cap;
  }

  T &operator[](int pos) {
    if (pos < 0)
      throw std::out_of_range("Index out of range");
    if (pos > _num_elements)
      throw std::out_of_range("Index out of range");
    return *(this->_begin + pos);
  }

  const T &operator[](int pos) const {
    if (pos < 0 || pos >= _num_elements)
      throw std::out_of_range("Index out of range");
    return *(_begin + pos);
  }

  T *begin() { return _begin; }
  T *end() { return _end; }

  // overload the >> as the move operator to move some value in the vector

private:
  T *_begin;
  T *_end;
  int _num_elements;
  int _capacity;
  std::allocator<T> _alloc;
};
} // namespace mrs

int main() {
  mrs::Vector<int> vec = {1, 2, 3, 4, 5};

  std::cout << vec[2] << std::endl;

  vec[2] = 10;

  std::cout << vec[2] << std::endl;

  vec.push_back({6, 7, 8});

  for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";
  }

  return 0;
}
