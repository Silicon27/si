//
// Created by David Yang on 2025-06-02.
//

#ifndef SCONFIG_H
#define SCONFIG_H

#include "compiler_features.hpp"

#define SI_LIB_VER 2025
#define SI_VERSION_MAJOR 1
#define SI_VERSION_MINOR 0
#define SI_VERSION_PATCH 0

#define SI_NAMESPACE_START namespace si {
#define SI_NAMESPACE_END }

#if defined(__cpp_attributes) && __cpp_attributes >= 200809L
#   define SI_LIB_DEPRECATED [[deprecated]]
#   define SI_LIB_DEPRECATED_MSG(msg) [[deprecated(msg)]]
#else
#   define SI_LIB_ATTR_UNSUPPORTED true
#   define SI_LIB_DEPRECATED
#   define SI_LIB_DEPRECATED_MSG(msg)
#endif // defined(__cpp_attributes) && __cpp_attributes >= 200809L

#ifdef __has_builtin
#   define SI_COMPILER_INTRINSIC___has_builtin(x) __has_builtin(x)
#endif

#ifdef __has_attribute
#   define SI_COMPILER_INTRINSIC___has_attribute(x) __has_attribute(x)
#endif


#endif //SCONFIG_H
