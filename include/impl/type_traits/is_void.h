//
// Created by Junie on 2026-01-13.
//

#ifndef SI_LIB_TYPE_TRAITS_IS_VOID_H
#define SI_LIB_TYPE_TRAITS_IS_VOID_H

#include "../../compat/sconfig.h"
#include "integral_constant.h"

SI_NAMESPACE_START

    template <typename T> struct is_void : false_type {};
    template <> struct is_void<void> : true_type {};
    template <typename T> constexpr bool is_void_v = is_void<T>::value;

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_IS_VOID_H
