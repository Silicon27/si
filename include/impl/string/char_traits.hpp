//
// Created by David Yang on 2025-10-11.
//

#ifndef SI_LIB_STRING_CHAR_TRAITS_HPP
#define SI_LIB_STRING_CHAR_TRAITS_HPP

#include <cstring>

#include "../../compat/sconfig.h"
#include "../../si/stddef.hpp"

SI_NAMESPACE_START

template <typename CharT>
struct char_traits {
    using char_type = CharT;
    using int_type = int;
    using pos_type = ptrdiff_t;
    using off_type = ptrdiff_t;
    using state_type = int;

    // write generic traits for all possible char types

    static void assign(char_type& c1, const char_type& c2) noexcept { c1 = c2; }
    static bool eq(const char_type& c1, const char_type& c2) noexcept { return c1 == c2; }
    static bool ne(const char_type& c1, const char_type& c2) noexcept { return c1 != c2; }
    static bool lt(const char_type& c1, const char_type& c2) noexcept { return c1 < c2; }

    static int compare(const char_type* s1, const char_type* s2, const size_t n) noexcept {
        for (size_t i = 0; i < n; ++i) {
            if (s1[i] < s2[i]) return -1;
            if (s1[i] > s2[i]) return 1;
        }
        return 0;
    }

    static size_t length(const char_type* s) noexcept {
        size_t len = 0;
        while (ne(s[len], char_type{})) ++len;
        return len;
    }

    static const char_type* find(const char_type* s, size_t n, const char_type& a) noexcept {
        for (size_t i = 0; i < n; ++i)
            if (eq(s[i], a))
                return s + i;
        return nullptr;
    }

    static void assign(char_type* dest, size_t n, const char_type& c) noexcept {
        for (size_t i = 0; i < n; ++i)
            dest[i] = c;
    }
};

template <>
struct char_traits<char> {
    using char_type = char;
    using int_type = int;
    using pos_type = ptrdiff_t;
    using off_type = ptrdiff_t;
    using state_type = int;

    static void assign(char& c1, const char& c2) noexcept { c1 = c2; }
    static bool eq(const char& c1, const char& c2) noexcept { return c1 == c2; }
    static bool ne(const char& c1, const char& c2) noexcept { return c1 != c2; }
    static bool lt(const char& c1, const char& c2) noexcept { return c1 < c2; }

    static int compare(const char* s1, const char* s2, size_t n) noexcept { return ::memcmp(s1, s2, n); }

    static size_t length(const char* s) noexcept { return ::strlen(s); }

    static const char* find(const char* s, size_t n, const char& a) noexcept {
        for (size_t i = 0; i < n; ++i)
            if (eq(s[i], a))
                return s + i;
        return nullptr;
    }

    static void assign(char* dest, size_t n, const char& a) noexcept { ::memset(dest, static_cast<unsigned char>(a), n); }
};

SI_NAMESPACE_END

#endif //SI_LIB_STRING_CHAR_TRAITS_HPP
