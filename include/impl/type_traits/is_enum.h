//
// Created by Junie on 2026-01-13.
//

#ifndef SI_LIB_TYPE_TRAITS_IS_ENUM_H
#define SI_LIB_TYPE_TRAITS_IS_ENUM_H

#include "../../compat/sconfig.h"
#include "integral_constant.h"

SI_NAMESPACE_START

#if SI_HAS_BUILTIN(__is_enum)
    template <typename T> struct is_enum : integral_constant<bool, __is_enum(T)> {};
#else
    #include <type_traits>
    template <typename T> struct is_enum : integral_constant<bool, std::is_enum_v<T>> {};
#endif
    template <typename T> constexpr bool is_enum_v = is_enum<T>::value;

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_IS_ENUM_H
