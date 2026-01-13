//
// Created by Junie on 2026-01-13.
//

#ifndef SI_LIB_TYPE_TRAITS_ADD_POINTER_H
#define SI_LIB_TYPE_TRAITS_ADD_POINTER_H

#include "../../compat/sconfig.h"

SI_NAMESPACE_START

    template <typename T> struct add_pointer { using type = T*; };
    template <typename T> struct add_pointer<T&> { using type = T*; };
    template <typename T> struct add_pointer<T&&> { using type = T*; };
    template <typename T> using add_pointer_t = typename add_pointer<T>::type;

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_ADD_POINTER_H
