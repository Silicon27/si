//
// Created by David Yang on 2025-05-30.
//

#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

namespace si::type_traits {
    template <typename T, typename = void> struct is_referenceable {static constexpr bool value = false;};
    template <typename T> struct is_referenceable<T, decltype((void)static_cast<T&(*)()>(0))> {static constexpr bool value = true;};
}

namespace si {
    template <typename T> struct remove_reference {typedef T type;};
    template <typename T> struct remove_reference<T&> {typedef T type;};
    template <typename T> struct remove_reference<T&&> {typedef T type;};

    template <typename T> using remove_reference_t = typename remove_reference<T>::type;

    template <typename T> struct remove_const {typedef T type;};
    template <typename T> struct remove_const<const T> {typedef T type;};

    template <typename T> using remove_const_t = typename remove_const<T>::type;

    template <typename T> struct remove_volatile {typedef T type;};
    template <typename T> struct remove_volatile<volatile T> {typedef T type;};

    template <typename T> using remove_volatile_t = typename remove_volatile<T>::type;

    template <typename T> struct remove_cv {typedef T type;};
    template <typename T> struct remove_cv<const T> {typedef T type;};
    template <typename T> struct remove_cv<volatile T> {typedef T type;};
    template <typename T> struct remove_cv<const volatile T> {typedef T type;};

    template <typename T> using remove_cv_t = typename remove_cv<T>::type;

    template <typename T, typename U> struct is_same {static constexpr bool value = false;};
    template <typename T> struct is_same<T, T> {static constexpr bool value = true;};

    template <typename T, typename U> constexpr bool is_same_v = is_same<T, U>::value;

    template <typename T> struct is_const {static constexpr bool value = false;};
    template <typename T> struct is_const<const T> {static constexpr bool value = true;};

    template <typename T> constexpr bool is_const_v = is_const<T>::value;

    template <typename T> struct is_reference {static constexpr bool value = false;};
    template <typename T> struct is_reference<T&> {static constexpr bool value = true;};
    template <typename T> struct is_reference<T&&> {static constexpr bool value = true;};

    template <typename T> constexpr bool is_reference_v = is_reference<T>::value;

    template <typename T> struct add_const {typedef const T type;};
    template <typename T> using add_const_t = typename add_const<T>::type;

    template <typename T> struct add_volatile {typedef volatile T type;};
    template <typename T> using add_volatile_t = typename add_volatile<T>::type;

    template <typename T, bool = type_traits::is_referenceable<T>::value> struct add_lvalue_reference { using type = T; };
    template <typename T> struct add_lvalue_reference<T, true> {typedef T& type;};
    template <typename T> using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;

    template <typename T, bool = type_traits::is_referenceable<T>::value> struct add_rvalue_reference { using type = T; };
    template <typename T> struct add_rvalue_reference<T, true> {typedef T&& type;};
    template <typename T> using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;

    template <bool Cond , typename T, typename F> struct conditional { using type = T; };
    template <typename T, typename F> struct conditional<false, T, F> { using type = F; };
    template <bool Cond, typename T, typename F> using conditional_t = typename conditional<Cond, T, F>::type;

    template <bool Cond, typename T = void> struct enable_if { };
    template <typename T> struct enable_if<true, T> { using type = T; };
    template <bool Cond, typename T = void> using enable_if_t = typename enable_if<Cond, T>::type;
}

#endif //TYPE_TRAITS_HPP
