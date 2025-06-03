//
// Created by David Yang on 2025-06-02.
//

#ifndef SI_LIB_TYPE_TRAITS_REMOVE_REFERENCE_H
#define SI_LIB_TYPE_TRAITS_REMOVE_REFERENCE_H

#include "../../compat/sconfig.h"

SI_NAMESPACE_START

#if SI_HAS_BUILTIN(__remove_reference_t)
    template <typename T> struct remove_reference { using type = SI_REMOVE_REFERENCE(T); };
#else
    template <typename T> struct remove_reference {typedef T type;};
    template <typename T> struct remove_reference<T&> {typedef T type;};
    template <typename T> struct remove_reference<T&&> {typedef T type;};
#endif

#if __cplusplus >= 201402L
    template <typename T> using remove_reference_t = typename remove_reference<T>::type;
#endif

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_REMOVE_REFERENCE_H
