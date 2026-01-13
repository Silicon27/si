//
// Created by Junie on 2026-01-13.
//

#ifndef SI_LIB_TYPE_TRAITS_ADD_VOLATILE_H
#define SI_LIB_TYPE_TRAITS_ADD_VOLATILE_H

#include "../../compat/sconfig.h"

SI_NAMESPACE_START

    template <typename T> struct add_volatile {typedef volatile T type;};
    template <typename T> using add_volatile_t = typename add_volatile<T>::type;

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_ADD_VOLATILE_H
