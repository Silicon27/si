//
// Created by GitHub Copilot on 2026-04-08.
//

#ifndef SI_LIB_TYPE_TRAITS_IS_UNSIGNED_H
#define SI_LIB_TYPE_TRAITS_IS_UNSIGNED_H

#include "../../compat/sconfig.h"
#include "integral_constant.h"

SI_NAMESPACE_START

    template<typename T>
    struct is_unsigned : false_type {};

    template <> struct is_unsigned<unsigned int> : true_type {};
    template <> struct is_unsigned<unsigned char> : true_type {};
    template <> struct is_unsigned<unsigned short> : true_type {};
    template <> struct is_unsigned<unsigned long> : true_type {};
    template <> struct is_unsigned<unsigned long long> : true_type {};

    // cv-qualified variants
    template <typename T> struct is_unsigned<const T> : is_unsigned<T> {};
    template <typename T> struct is_unsigned<volatile T> : is_unsigned<T> {};
    template <typename T> struct is_unsigned<const volatile T> : is_unsigned<T> {};

    template <typename T> constexpr bool is_unsigned_v = is_unsigned<T>::value;

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_IS_UNSIGNED_H

