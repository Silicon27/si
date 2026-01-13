//
// Created by Junie on 2026-01-13.
//

#ifndef SI_LIB_TYPE_TRAITS_CONDITIONAL_H
#define SI_LIB_TYPE_TRAITS_CONDITIONAL_H

#include "../../compat/sconfig.h"

SI_NAMESPACE_START

    template <bool Cond , typename T, typename F> struct conditional { using type = T; };
    template <typename T, typename F> struct conditional<false, T, F> { using type = F; };
    template <bool Cond, typename T, typename F> using conditional_t = typename conditional<Cond, T, F>::type;

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_CONDITIONAL_H
