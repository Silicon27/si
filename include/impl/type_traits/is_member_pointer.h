//
// Created by Junie on 2026-01-13.
//

#ifndef SI_LIB_TYPE_TRAITS_IS_MEMBER_POINTER_H
#define SI_LIB_TYPE_TRAITS_IS_MEMBER_POINTER_H

#include "../../compat/sconfig.h"
#include "integral_constant.h"

SI_NAMESPACE_START

    template <typename T> struct is_member_pointer : false_type {};
    template <typename T, typename U> struct is_member_pointer<T U::*> : true_type {};
    template <typename T> constexpr bool is_member_pointer_v = is_member_pointer<T>::value;

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_IS_MEMBER_POINTER_H
