//
// Created by Junie on 2026-01-13.
//

#ifndef SI_LIB_TYPE_TRAITS_IS_NULL_POINTER_H
#define SI_LIB_TYPE_TRAITS_IS_NULL_POINTER_H

#include "../../compat/sconfig.h"
#include "../../impl/stddef/nullptr_t.h"
#include "integral_constant.h"

SI_NAMESPACE_START

    template <typename T> struct is_null_pointer : false_type {};
    template <> struct is_null_pointer<nullptr_t> : true_type {};
    template <typename T> constexpr bool is_null_pointer_v = is_null_pointer<T>::value;

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_IS_NULL_POINTER_H
