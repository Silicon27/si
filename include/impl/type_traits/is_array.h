//
// Created by Junie on 2026-01-13.
//

#ifndef SI_LIB_TYPE_TRAITS_IS_ARRAY_H
#define SI_LIB_TYPE_TRAITS_IS_ARRAY_H

#include "../../compat/sconfig.h"
#include "../../impl/stddef/size_t.h"
#include "integral_constant.h"

SI_NAMESPACE_START

    template <typename T> struct is_array : false_type {};
    template <typename T> struct is_array<T[]> : true_type {};
    template <typename T, size_t N> struct is_array<T[N]> : true_type {};
    template <typename T> constexpr bool is_array_v = is_array<T>::value;

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_IS_ARRAY_H
