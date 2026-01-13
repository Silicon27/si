//
// Created by Junie on 2026-01-13.
//

#ifndef SI_LIB_TYPE_TRAITS_IS_FUNCTION_H
#define SI_LIB_TYPE_TRAITS_IS_FUNCTION_H

#include "../../compat/sconfig.h"
#include "integral_constant.h"
#include <initializer_list>

SI_NAMESPACE_START

    template <typename T> struct is_function : false_type {};
    template <typename Ret, typename... Args> struct is_function<Ret(Args...)> : true_type {};
    template <typename Ret, typename... Args> struct is_function<Ret(Args..., ...)> : true_type {};
    template <typename Ret, typename... Args> struct is_function<Ret(Args...) const> : true_type {};
    template <typename Ret, typename... Args> struct is_function<Ret(Args..., ...) const> : true_type {};
    template <typename Ret, typename... Args> struct is_function<Ret(Args...) volatile> : true_type {};
    template <typename Ret, typename... Args> struct is_function<Ret(Args..., ...) volatile> : true_type {};
    template <typename Ret, typename... Args> struct is_function<Ret(Args...) const volatile> : true_type {};
    template <typename Ret, typename... Args> struct is_function<Ret(Args..., ...) const volatile> : true_type {};
    template <typename Ret, typename T> struct is_function<Ret(std::initializer_list<T>)> : true_type {};
    template <typename Ret, typename T > struct is_function<Ret(std::initializer_list<T>, ...)> : true_type {};

    template <typename T> constexpr bool is_function_v = is_function<T>::value;

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_IS_FUNCTION_H
