//
// Created by David Yang on 2025-06-07.
//

#ifndef SI_LIB_UTILITY_FORWARD_H
#define SI_LIB_UTILITY_FORWARD_H

#include "../../compat/sconfig.h"
#include "../../si/type_traits.hpp"

SI_NAMESPACE_START

template <typename T>
constexpr T&& forward(typename remove_reference<T>::type& t) noexcept {
    return static_cast<T&&>(t);
}

template <typename T>
constexpr T&& forward(typename remove_reference<T>::type&& t) noexcept {
    static_assert(!is_lvalue_reference<T>::value,
                  "Can't forward an rvalue as an lvalue!");
    return static_cast<T&&>(t);
}


SI_NAMESPACE_END

#endif //SI_LIB_UTILITY_FORWARD_H
