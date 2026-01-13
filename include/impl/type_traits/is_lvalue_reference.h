//
// Created by Junie on 2026-01-13.
//

#ifndef SI_LIB_TYPE_TRAITS_IS_LVALUE_REFERENCE_H
#define SI_LIB_TYPE_TRAITS_IS_LVALUE_REFERENCE_H

#include "../../compat/sconfig.h"
#include "integral_constant.h"

SI_NAMESPACE_START

    template <typename T> struct is_lvalue_reference : false_type {};
    template <typename T> struct is_lvalue_reference<T&> : true_type {};
    template <typename T> constexpr bool is_lvalue_reference_v = is_lvalue_reference<T>::value;

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_IS_LVALUE_REFERENCE_H
