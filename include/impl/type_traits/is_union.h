//
// Created by Junie on 2026-01-13.
//

#ifndef SI_LIB_TYPE_TRAITS_IS_UNION_H
#define SI_LIB_TYPE_TRAITS_IS_UNION_H

#include "../../compat/sconfig.h"
#include "integral_constant.h"

SI_NAMESPACE_START

#if SI_HAS_BUILTIN(__is_union)
    template <typename T> struct is_union : integral_constant<bool, __is_union(T)> {};
#else
    #include <type_traits>
    template <typename T> struct is_union : integral_constant<bool, std::is_union_v<T>> {};
#endif
    template <typename T> constexpr bool is_union_v = is_union<T>::value;

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_IS_UNION_H
