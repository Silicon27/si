//
// Created by David Yang on 2025-06-02.
//

#ifndef COMPILER_FEATURES_HPP
#define COMPILER_FEATURES_HPP

#include "preprocessor_features.h"

#if !defined(__cpp_concepts) || (__cpp_concepts < 201907)
#define SI_NO_CONCEPTS
#endif // !defined(__cpp_concepts) || (__cpp_concepts < 201907)

#if defined(__clang__)
#   define SI_CLANG 1
#   define SI_CLANG_VERSION (__clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__)
#   define SI_HAS_FEATURE_TYPE_TRAITS (SI_CLANG_VERSION >= 40000) // Clang 4.0 and above
#else // if defined(__clang__)
#   define SI_CLANG 0
#   define SI_HAS_FEATURE_TYPE_TRAITS 0
#endif // defined(__clang__)

#if defined(__GNUC__) || defined(__GNUG__) && !defined(__clang__)
#   define SI_GCC 1
#   define SI_GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#   define SI_HAS_FEATURE_TYPE_TRAITS (SI_GCC_VERSION >= 50000) // GCC 5.0 and above
#else // if (defined(__GNUC__) || defined(__GNUG__)) && !defined(__clang__)
#   define SI_GCC 0
#   define SI_HAS_FEATURE_TYPE_TRAITS 0
#endif //COMPILER_FEATURES_HPP

#if defined(_MSC_VER)
#   define SI_MSVC 1
#   define SI_MSVC_VERSION _MSC_VER
#   define SI_HAS_FEATURE_TYPE_TRAITS (_MSC_VER >= 1900) // MSVC 2015 and above
#else // if defined(_MSC_VER)
#   define SI_MSVC 0
#   define SI_HAS_FEATURE_TYPE_TRAITS 0
#endif // defined(_MSC_VER)


#if SI_HAS_BUILTIN(__is_enum)
#   define SI_IS_ENUM(T) __is_enum(T)
#else
#   include <type_traits>
#   define SI_IS_ENUM(T) std::is_enum_v<T>
#endif

#if SI_HAS_BUILTIN(__is_union)
#   define SI_IS_UNION(T) __is_union(T)
#else
#   include <type_traits>
#   define SI_IS_UNION(T) std::is_union_v<T>
#endif

#if SI_HAS_BUILTIN(__is_class)
#   define SI_IS_CLASS(T) __is_class(T)
#else
#   include <type_traits>
#   define SI_IS_CLASS(T) std::is_class_v<T>
#endif

#if SI_HAS_BUILTIN(__is_trivially_copyable)
#   define SI_IS_TRIVIALLY_COPYABLE(T) __is_trivially_copyable(T)
#else
#   include <type_traits>
#   define SI_IS_TRIVIALLY_COPYABLE(T) std::is_trivially_copyable_v<T>
#endif

#if SI_HAS_BUILTIN(__is_trivially_constructible)
#   define SI_IS_TRIVIALLY_CONSTRUCTIBLE(T) __is_trivially_constructible(T)
#else
#   include <type_traits>
#   define SI_IS_TRIVIALLY_CONSTRUCTIBLE(T) std::is_trivially_constructible_v<T>
#endif

#if SI_HAS_BUILTIN(__is_trivially_destructible)
#   define SI_IS_TRIVIALLY_DESTRUCTIBLE(T) __is_trivially_destructible(T)
#else
#   include <type_traits>
#   define SI_IS_TRIVIALLY_DESTRUCTIBLE(T) std::is_trivially_destructible_v<T>
#endif

#if SI_HAS_BUILTIN(__is_final)
#   define SI_IS_FINAL(T) __is_final(T)
#else
#   include <type_traits>
#   define SI_IS_FINAL(T) std::is_final_v<T>
#endif

#if SI_HAS_BUILTIN(__remove_reference_t)
#   define SI_REMOVE_REFERENCE(T) __remove_reference_t(T)
#else
#   include <type_traits>
#   define SI_REMOVE_REFERENCE(T) std::remove_reference_t<T>
#endif

#if SI_HAS_BUILTIN(__remove_const)
#   define SI_REMOVE_CONST(T) __remove_const(T)
#else
#   include <type_traits>
#   define SI_REMOVE_CONST(T) std::remove_const_t<T>
#endif

#if SI_HAS_BUILTIN(__remove_volatile)
#   define SI_REMOVE_VOLATILE(T) __remove_volatile(T)
#else
#   include <type_traits>
#   define SI_REMOVE_VOLATILE(T) std::remove_volatile_t<T>
#endif

#if SI_HAS_BUILTIN(__remove_cv)
#   define SI_REMOVE_CV(T) __remove_cv(T)
#else
#   include <type_traits>
#   define SI_REMOVE_CV(T) std::remove_cv_t<T>
#endif

#if SI_HAS_BUILTIN(__remove_extent)
#   define SI_REMOVE_EXTENT(T) __remove_extent(T)
#else
#   include <type_traits>
#   define SI_REMOVE_EXTENT(T) std::remove_extent_t<T>
#endif


#endif // COMPILER_FEATURES_HPP
