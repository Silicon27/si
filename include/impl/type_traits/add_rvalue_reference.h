//
// Created by Junie on 2026-01-13.
//

#ifndef SI_LIB_TYPE_TRAITS_ADD_RVALUE_REFERENCE_H
#define SI_LIB_TYPE_TRAITS_ADD_RVALUE_REFERENCE_H

#include "../../compat/sconfig.h"
#include "is_referenceable.h"

SI_NAMESPACE_START

#ifdef SI_NO_CONCEPTS
    template <typename T, bool = type_traits::is_referenceable<T>::value> struct add_rvalue_reference { using type = T; };
    template <typename T> struct add_rvalue_reference<T, true> {typedef T&& type;};
    template <typename T> using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;
#else
    template <typename T>
    struct add_rvalue_reference { using type = T; };

    template <typename T> requires concepts::referenceable<T>
    struct add_rvalue_reference<T> { using type = T&&; };
#endif

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_ADD_RVALUE_REFERENCE_H
