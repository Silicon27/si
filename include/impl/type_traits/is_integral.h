//
// Created by Junie on 2026-01-13.
//

#ifndef SI_LIB_TYPE_TRAITS_IS_INTEGRAL_H
#define SI_LIB_TYPE_TRAITS_IS_INTEGRAL_H

#include "../../compat/sconfig.h"
#include "integral_constant.h"

SI_NAMESPACE_START

    template<typename T>
    struct is_integral : false_type {}; // base case, always false unless specified below

    template <> struct is_integral<int> : true_type {};
    template <> struct is_integral<char> : true_type {};
    template <> struct is_integral<short> : true_type {};
    template <> struct is_integral<long> : true_type {};
    template <> struct is_integral<long long> : true_type {};
    template <> struct is_integral<unsigned int> : true_type {};
    template <> struct is_integral<unsigned char> : true_type {};
    template <> struct is_integral<unsigned short> : true_type {};
    template <> struct is_integral<unsigned long> : true_type {};
    template <> struct is_integral<unsigned long long> : true_type {};
    // these three cases are for if the type is cv-qualified
    template <typename T> struct is_integral<const T> : is_integral<T> {};
    template <typename T> struct is_integral<volatile T> : is_integral<T> {};
    template <typename T> struct is_integral<const volatile T> : is_integral<T> {};
    template <typename T> constexpr bool is_integral_v = is_integral<T>::value;

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_IS_INTEGRAL_H
