//
// Created by David Yang on 2025-10-11.
//

#ifndef CHAR_TRAITS_HPP
#define CHAR_TRAITS_HPP

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
};

template <>
struct char_traits<char> {
    using char_type = char;
    using int_type = int;
    using pos_type = ptrdiff_t;
    using off_type = ptrdiff_t;
    using state_type = int;

    static void assign(char& c1, const char& c2) { c1 = c2; }
    static bool eq(const char& c1, const char& c2) { return c1 == c2; }
    static bool ne(const char& c1, const char& c2) { return c1 != c2; }
    static bool lt(const char& c1, const char& c2) { return c1 < c2; }
    static int compare(const char* s1, const char* s2, size_t n) { return ::memcmp(s1, s2, n); }
    static size_t length(const char* s) { return ::strlen(s); }
    static const char* find(const char* s, size_t n, const char& a) { return ::strchr(s, a); }
};

SI_NAMESPACE_END

#endif //CHAR_TRAITS_HPP
