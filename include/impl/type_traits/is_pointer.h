//
// Created by Junie on 2026-01-13.
//

#ifndef SI_LIB_TYPE_TRAITS_IS_POINTER_H
#define SI_LIB_TYPE_TRAITS_IS_POINTER_H

#include "../../compat/sconfig.h"
#include "integral_constant.h"

SI_NAMESPACE_START

    template <typename T> struct is_pointer : false_type {};
    template <typename T> struct is_pointer<T*> : true_type {};
    template <typename T> struct is_pointer<T* const> : true_type {};
    template <typename T> struct is_pointer<T* volatile> : true_type {};
    template <typename T> struct is_pointer<T* const volatile> : true_type {};
    template <typename T> constexpr bool is_pointer_v = is_pointer<T>::value;

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_IS_POINTER_H
