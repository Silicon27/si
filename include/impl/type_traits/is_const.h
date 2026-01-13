//
// Created by Junie on 2026-01-13.
//

#ifndef SI_LIB_TYPE_TRAITS_IS_CONST_H
#define SI_LIB_TYPE_TRAITS_IS_CONST_H

#include "../../compat/sconfig.h"
#include "integral_constant.h"

SI_NAMESPACE_START

    template <typename T> struct is_const : false_type {};
    template <typename T> struct is_const<const T> : true_type {};
    template <typename T> constexpr bool is_const_v = is_const<T>::value;

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_IS_CONST_H
