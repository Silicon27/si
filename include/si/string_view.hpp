//
// Created by David Yang on 2026-05-02.
//

#ifndef SI_LIB_STRING_VIEW_HPP
#define SI_LIB_STRING_VIEW_HPP

#include "../compat/sconfig.h"
#include "stddef.hpp"

SI_NAMESPACE_START

// Forward declaration of bump_ptr_allocator if needed
template<typename VecAlloc>
class bump_ptr_allocator;

template <typename CharT>
class basic_string_view {
public:
    using value_type = CharT;
    using pointer = CharT*;
    using const_pointer = const CharT*;
    using reference = CharT&;
    using const_reference = const CharT&;
    using const_iterator = const CharT*;
    using iterator = const_iterator;
    using size_type = size_t;
    using difference_type = ptrdiff_t;

    static constexpr size_type npos = size_type(-1);

private:
    const_pointer m_data;
    size_type m_size;

public:
    constexpr basic_string_view() noexcept : m_data(nullptr), m_size(0) {}
    constexpr basic_string_view(const basic_string_view&) noexcept = default;
    constexpr basic_string_view& operator=(const basic_string_view&) noexcept = default;

    constexpr basic_string_view(const CharT* s, size_type count) : m_data(s), m_size(count) {}
    constexpr basic_string_view(const CharT* s) : m_data(s), m_size(0) {
        if (s) {
            while (s[m_size]) ++m_size;
        }
    }

    // Specialization-like constructor/overload for bump_ptr_allocator as requested
    template<typename VecAlloc>
    basic_string_view(bump_ptr_allocator<VecAlloc>& alloc, const CharT* s, size_type count) {
        void* storage = alloc.allocate(sizeof(CharT) * (count + 1), alignof(CharT));
        CharT* data = static_cast<CharT*>(storage);
        for (size_type i = 0; i < count; ++i) data[i] = s[i];
        data[count] = CharT(0);
        m_data = data;
        m_size = count;
    }

    template<typename VecAlloc>
    basic_string_view(bump_ptr_allocator<VecAlloc>& alloc, const CharT* s) : basic_string_view() {
        if (!s) return;
        size_type count = 0;
        while (s[count]) ++count;
        *this = basic_string_view(alloc, s, count);
    }

    constexpr const_iterator begin() const noexcept { return m_data; }
    constexpr const_iterator end() const noexcept { return m_data + m_size; }
    constexpr const_iterator cbegin() const noexcept { return m_data; }
    constexpr const_iterator cend() const noexcept { return m_data + m_size; }

    constexpr size_type size() const noexcept { return m_size; }
    constexpr size_type length() const noexcept { return m_size; }
    constexpr bool empty() const noexcept { return m_size == 0; }

    constexpr const_reference operator[](size_type pos) const { return m_data[pos]; }
    constexpr const_reference at(size_type pos) const { return m_data[pos]; }

    constexpr const_reference front() const { return m_data[0]; }
    constexpr const_reference back() const { return m_data[m_size - 1]; }

    constexpr const_pointer data() const noexcept { return m_data; }

    constexpr void remove_prefix(size_type n) { m_data += n; m_size -= n; }
    constexpr void remove_suffix(size_type n) { m_size -= n; }

    constexpr basic_string_view substr(size_type pos = 0, size_type count = npos) const {
        return basic_string_view(m_data + pos, count == npos ? m_size - pos : count);
    }

    constexpr bool operator==(const basic_string_view& other) const noexcept {
        if (m_size != other.m_size) return false;
        for (size_type i = 0; i < m_size; ++i) {
            if (m_data[i] != other.m_data[i]) return false;
        }
        return true;
    }

    constexpr bool operator!=(const basic_string_view& other) const noexcept {
        return !(*this == other);
    }
};

using string_view = basic_string_view<char>;

SI_NAMESPACE_END

#endif //SI_LIB_STRING_VIEW_HPP
