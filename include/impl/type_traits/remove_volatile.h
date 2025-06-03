//
// Created by David Yang on 2025-06-02.
//

#ifndef SI_LIB_TYPE_TRAITS_REMOVE_VOLATILE_H
#define SI_LIB_TYPE_TRAITS_REMOVE_VOLATILE_H

#include "../../compat/sconfig.h"

SI_NAMESPACE_START

#if SI_HAS_BUILTIN(__remove_volatile)
    template <typename T> struct remove_volatile { using type = SI_REMOVE_VOLATILE(T); };
#else
    template <typename T> struct remove_volatile { typedef T type; };
    template <typename T> struct remove_volatile<volatile T> { typedef T type; };
#endif

#if __cplusplus >= 201402L
    template <typename T> using remove_volatile_t = typename remove_volatile<T>::type;
#endif

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_REMOVE_VOLATILE_H
