//
// Created by Junie on 2026-01-13.
//

#ifndef SI_LIB_TYPE_TRAITS_ADD_CONST_H
#define SI_LIB_TYPE_TRAITS_ADD_CONST_H

#include "../../compat/sconfig.h"

SI_NAMESPACE_START

    template <typename T> struct add_const {typedef const T type;};
    template <typename T> using add_const_t = typename add_const<T>::type;

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_ADD_CONST_H
