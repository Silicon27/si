//
// Created by Junie on 2026-01-13.
//

#ifndef SI_LIB_TYPE_TRAITS_IS_ARITHMETIC_H
#define SI_LIB_TYPE_TRAITS_IS_ARITHMETIC_H

#include "../../compat/sconfig.h"
#include "is_integral.h"
#include "is_floating_point.h"

SI_NAMESPACE_START

    template <typename T>
    struct is_arithmetic : integral_constant<bool, is_integral<T>::value || is_floating_point<T>::value> {};

    template <typename T> constexpr bool is_arithmetic_v = is_arithmetic<T>::value;

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_IS_ARITHMETIC_H
