//
// Created by David Yang on 2025-06-04.
//

#ifndef SI_LIB_TYPE_TRAITS_REMOVE_EXTENT_H
#define SI_LIB_TYPE_TRAITS_REMOVE_EXTENT_H

#include "../../compat/sconfig.h"

SI_NAMESPACE_START

#if SI_HAS_BUILTIN(__remove_extent)
    template <typename T> struct remove_extent { using type = SI_REMOVE_EXTENT(T); };
#else
    template <typename T> struct remove_extent { using type = T; };
    template <typename T> struct remove_extent<T[]> { using type = T; };
    template <typename T, size_t N> struct remove_extent<T[N]> { using type = T; };
#endif

#if __cplusplus >= 201402L
    template <typename T> using remove_extent_t = typename remove_extent<T>::type;
#endif

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_REMOVE_EXTENT_H
