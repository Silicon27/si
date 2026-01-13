//
// Created by Junie on 2026-01-13.
//

#ifndef SI_LIB_TYPE_TRAITS_IS_MEMBER_OBJECT_POINTER_H
#define SI_LIB_TYPE_TRAITS_IS_MEMBER_OBJECT_POINTER_H

#include "../../compat/sconfig.h"
#include "integral_constant.h"
#include "is_function.h"

SI_NAMESPACE_START

    template <typename T> struct is_member_object_pointer : false_type {};
    template <typename T, typename U> struct is_member_object_pointer<T U::*> : integral_constant<bool, !is_function_v<T>> {};
    template <typename T> constexpr bool is_member_object_pointer_v = is_member_object_pointer<T>::value;

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_IS_MEMBER_OBJECT_POINTER_H
