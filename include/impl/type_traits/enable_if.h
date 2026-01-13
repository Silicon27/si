//
// Created by Junie on 2026-01-13.
//

#ifndef SI_LIB_TYPE_TRAITS_ENABLE_IF_H
#define SI_LIB_TYPE_TRAITS_ENABLE_IF_H

#include "../../compat/sconfig.h"

SI_NAMESPACE_START

    template <bool Cond, typename T = void> struct enable_if { };
    template <typename T> struct enable_if<true, T> { using type = T; };
    template <bool Cond, typename T = void> using enable_if_t = typename enable_if<Cond, T>::type;

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_ENABLE_IF_H
