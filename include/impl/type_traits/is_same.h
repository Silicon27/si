//
// Created by Junie on 2026-01-13.
//

#ifndef SI_LIB_TYPE_TRAITS_IS_SAME_H
#define SI_LIB_TYPE_TRAITS_IS_SAME_H

#include "../../compat/sconfig.h"
#include "integral_constant.h"

SI_NAMESPACE_START

    template <typename T, typename U> struct is_same : false_type {};
    template <typename T> struct is_same<T, T> : true_type {};
    template <typename T, typename U> constexpr bool is_same_v = is_same<T, U>::value;

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_IS_SAME_H
