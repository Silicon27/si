//
// Created by Junie on 2026-01-13.
//

#ifndef SI_LIB_TYPE_TRAITS_IS_CLASS_H
#define SI_LIB_TYPE_TRAITS_IS_CLASS_H

#include "../../compat/sconfig.h"
#include "integral_constant.h"

SI_NAMESPACE_START

#if SI_HAS_BUILTIN(__is_class)
    template <typename T> struct is_class : integral_constant<bool, __is_class(T)> {};
#else
    #include <type_traits>
    template <typename T> struct is_class : integral_constant<bool, std::is_class_v<T>> {};
#endif
    template <typename T> constexpr bool is_class_v = is_class<T>::value;

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_IS_CLASS_H
