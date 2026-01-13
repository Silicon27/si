# Intricacies of the Allocator

For the past week, I've indulged myself in the world of remaking the STL. It is not necessarily a fun thing to do, considering the timing, as my finals are approaching. I could have also used the time more wisely than redoing some 30-34 years' worth of work. Through this process, I learned a great deal, most notably about the allocator. The allocator is a crucial part of the STL, and it is often overlooked. It is the unsung hero of the STL, providing memory management for all the containers.

Let's take a look at the signature of the allocator:

```cpp
template <typename T>
class allocator {
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using void_pointer = void*;
    using const_void_pointer = const void*;
    using size_type = size_t;
    using difference_type = ptrdiff_t;

    allocator() noexcept = default;

    template <typename U>
    explicit allocator(const allocator<U>&);

    [[nodiscard]] T* allocate(size_t n);
    void deallocate(value_type* p, size_t n) noexcept;

    template <typename U>
    struct rebind;
};
```

`allocator` contains mainly the contructor, an `allocate` function, a `deallocate` function, and a `rebind` struct. The `allocate` function is used to allocate memory for the container, while the `deallocate` function is used to deallocate memory. The `rebind` struct is used to rebind the allocator to a different type.

Let's see how `allocate` works:

```cpp
template <typname T>
[[nodicard]] T* allocator<T>::allocate(size_t n) {
    if (n > std::numeric_limits<size_t>::max() / sizeof(T)) {
        throw std::bad_alloc();
    }
    if (n == 0) {
        return nullptr;
    }
    T* p = static_cast<T*>(::operator new(n * sizeof(T)));
    return p;
}
```



