//
// Created by David Yang on 2025-06-07.
//

#ifndef SI_LIB_UTILITY_MOVE_H
#define SI_LIB_UTILITY_MOVE_H

#include "../../compat/sconfig.h"
#include "../../si/type_traits.hpp"

SI_NAMESPACE_START

template <typename T>
constexpr typename remove_reference<T>::type&& move (T&& t) noexcept {
    return static_cast<typename remove_reference<T>::type&&>(t);
}

SI_NAMESPACE_END

#endif //SI_LIB_UTILITY_MOVE_H
