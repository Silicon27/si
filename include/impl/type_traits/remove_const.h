//
// Created by David Yang on 2025-06-02.
//

#ifndef SI_LIB_TYPE_TRAITS_REMOVE_CONST_H
#define SI_LIB_TYPE_TRAITS_REMOVE_CONST_H

#include "../../compat/sconfig.h"

SI_NAMESPACE_START

#if SI_HAS_BUILTIN(__remove_const)
    template <typename T> struct remove_const { using type = SI_REMOVE_CONST(T); };
#else
    template <typename T> struct remove_const { typedef T type; };
    template <typename T> struct remove_const<const T> { typedef T type; };
#endif

#if __cplusplus >= 201402L
    template <typename T> using remove_const_t = typename remove_const<T>::type;
#endif

SI_NAMESPACE_END

#endif //REMOVE_CONST_H
