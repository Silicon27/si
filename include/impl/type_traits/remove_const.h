//
// Created by David Yang on 2025-06-02.
//

#ifndef SI_LIB_TYPE_TRAITS_REMOVE_CONST_H
#define SI_LIB_TYPE_TRAITS_REMOVE_CONST_H

#include "../../compat/sconfig.h"

SI_NAMESPACE_START

#if SI_HAS_FEATURE_TYPE_TRAITS
    template <typename T> struct remove_const { using type = SI_REMOVE_CONST(T); };
    template <typename T> using remove_const_t = SI_REMOVE_CONST(T);
#else
    template <typename T> struct remove_const { typedef T type; };
    template <typename T> struct remove_const<const T> { typedef T type; };

    template <typename T> using remove_const_t = typename remove_const<T>::type;
#endif

SI_NAMESPACE_END

#endif //REMOVE_CONST_H
