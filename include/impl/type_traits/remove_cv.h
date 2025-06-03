//
// Created by David Yang on 2025-06-04.
//

#ifndef SI_LIB_TYPE_TRAITS_REMOVE_CV_H
#define SI_LIB_TYPE_TRAITS_REMOVE_CV_H

#include "../../compat/sconfig.h"

SI_NAMESPACE_START

#if SI_HAS_BUILTIN(__remove_cv)
    template <typename T> struct remove_cv { using type = SI_REMOVE_CV(T); };
#else
    template <typename T> struct remove_cv {typedef T type;};
    template <typename T> struct remove_cv<const T> {typedef T type;};
    template <typename T> struct remove_cv<volatile T> {typedef T type;};
    template <typename T> struct remove_cv<const volatile T> {typedef T type;};
#endif

#if __cplusplus >= 201402L
    template <typename T> using remove_cv_t = typename remove_cv<T>::type;
#endif

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_REMOVE_CV_H
