//
// Created by David Yang on 2025-06-02.
//

#ifndef SI_LIB_COMPAT_SCONFIG_H
#define SI_LIB_COMPAT_SCONFIG_H

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

#if defined(__SIZEOF_POINTER__)
#   if __SIZEOF_POINTER__ == 8
#       define SI_ARCH_BITS 64
#   elif __SIZEOF_POINTER__ == 4
#       define SI_ARCH_BITS 32
#   elif __SIZEOF_POINTER__ == 2
#       define SI_ARCH_BITS 16
#   endif
#endif

#ifndef SI_ARCH_BITS
#   if defined(__LP64__) || defined(_LP64) || defined(__x86_64__) || defined(__aarch64__) || defined(_M_X64) || defined(_M_AMD64) || defined(_M_ARM64) || defined(_WIN64)
#       define SI_ARCH_BITS 64
#   elif defined(__i386__) || defined(_M_IX86) || defined(_WIN32)
#       define SI_ARCH_BITS 32
#   else
#       define SI_ARCH_BITS 32
#   endif
#endif

#endif //SI_LIB_COMPAT_SCONFIG_H
