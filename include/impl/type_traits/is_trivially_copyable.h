//
// Created by Junie on 2026-01-13.
//

#ifndef SI_LIB_TYPE_TRAITS_IS_TRIVIALLY_COPYABLE_H
#define SI_LIB_TYPE_TRAITS_IS_TRIVIALLY_COPYABLE_H

#include "../../compat/sconfig.h"
#include "../../impl/stddef/size_t.h"
#include "integral_constant.h"

SI_NAMESPACE_START

#if SI_HAS_FEATURE(__is_trivially_copyable)

    template <typename T> struct is_trivially_copyable : integral_constant<bool, __is_trivially_copyable(T)> {};

#else

    template <typename T> struct is_trivially_copyable : false_type {};
    template <typename T> struct is_trivially_copyable<const T> : is_trivially_copyable<T> {};
    template <typename T> struct is_trivially_copyable<volatile T> : is_trivially_copyable<T> {};
    template <typename T> struct is_trivially_copyable<const volatile T> : is_trivially_copyable<T> {};
    template <typename T> struct is_trivially_copyable<T*> : true_type {};
    template <typename T, size_t N> struct is_trivially_copyable<T[N]> : is_trivially_copyable<T> {};
    template <> struct is_trivially_copyable<bool> : true_type {};
    template <> struct is_trivially_copyable<char> : true_type {};
    template <> struct is_trivially_copyable<signed char> : true_type {};
    template <> struct is_trivially_copyable<unsigned char> : true_type {};
    template <> struct is_trivially_copyable<wchar_t> : true_type {};
    template <> struct is_trivially_copyable<char16_t> : true_type {};
    template <> struct is_trivially_copyable<char32_t> : true_type {};
    template <> struct is_trivially_copyable<short> : true_type {};
    template <> struct is_trivially_copyable<unsigned short> : true_type {};
    template <> struct is_trivially_copyable<int> : true_type {};
    template <> struct is_trivially_copyable<unsigned int> : true_type {};
    template <> struct is_trivially_copyable<long> : true_type {};
    template <> struct is_trivially_copyable<unsigned long> : true_type {};
    template <> struct is_trivially_copyable<long long> : true_type {};
    template <> struct is_trivially_copyable<unsigned long long> : true_type {};
    template <> struct is_trivially_copyable<float> : true_type {};
    template <> struct is_trivially_copyable<double> : true_type {};
    template <> struct is_trivially_copyable<long double> : true_type {};

#endif

    template <typename T> constexpr bool is_trivially_copyable_v = is_trivially_copyable<T>::value;

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_IS_TRIVIALLY_COPYABLE_H
