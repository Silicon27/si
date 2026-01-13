//
// Created by Junie on 2026-01-13.
//

#ifndef SI_LIB_TYPE_TRAITS_IS_ARITHMETIC_H
#define SI_LIB_TYPE_TRAITS_IS_ARITHMETIC_H

#include "../../compat/sconfig.h"
#include "is_integral.h"
#include "is_floating_point.h"

SI_NAMESPACE_START

    template <typename T> struct is_arithmetic : false_type {};
    template <typename T> struct is_arithmetic<is_integral<T>> : true_type {};
    template <typename T> struct is_arithmetic<is_floating_point<T>> : true_type {};
    template <typename T> constexpr bool is_arithmetic_v = is_arithmetic<T>::value;

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_IS_ARITHMETIC_H
