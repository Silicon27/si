//
// Created by David Yang on 2025-05-30.
//

#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP
// if any cpp verison below c++20, define this

#if !defined(__cpp_concepts) || (__cpp_concepts < 201907)
#define SI_NO_CONCEPTS
#endif

#ifdef SI_NO_CONCEPTS
namespace si::type_traits {
    template <typename T, typename = void> struct is_referenceable {static constexpr bool value = false;};
    template <typename T> struct is_referenceable<T, decltype((void)static_cast<T&(*)()>(0))> {static constexpr bool value = true;};
}
#else

namespace si::concepts {
    template <typename T> struct type_identity { using type = T; };

    template <typename T>
    concept referenceable = requires {
        typename type_identity<T&>::type;
    };
}
#endif // SI_NO_CONCEPTS

namespace si {

    template <typename...> using void_t = void;
    typedef nullptr_t decltype(nullptr);

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

    template <typename T> struct remove_extent {using type = T;};
    template <typename T> struct remove_extent<T[]> {using type = T;};
    template <typename T, size_t N> struct remove_extent<T[N]> {using type = T;};

    template <typename T> using remove_extent_t = typename remove_extent<T>::type;

    template <typename T> struct add_const {typedef const T type;};
    template <typename T> using add_const_t = typename add_const<T>::type;

    template <typename T> struct add_volatile {typedef volatile T type;};
    template <typename T> using add_volatile_t = typename add_volatile<T>::type;

#ifdef SI_NO_CONCEPTS
    template <typename T, bool = type_traits::is_referenceable<T>::value> struct add_lvalue_reference { using type = T; };
    template <typename T> struct add_lvalue_reference<T, true> {typedef T& type;};
    template <typename T> using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;

    template <typename T, bool = type_traits::is_referenceable<T>::value> struct add_rvalue_reference { using type = T; };
    template <typename T> struct add_rvalue_reference<T, true> {typedef T&& type;};
    template <typename T> using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;
#else
    template <typename T>
    struct add_lvalue_reference { using type = T; };

    template <typename T> requires concepts::referenceable<T>
    struct add_lvalue_reference<T> { using type = T&; };

    template <typename T>
    struct add_rvalue_reference { using type = T; };

    template <typename T> requires concepts::referenceable<T>
    struct add_rvalue_reference<T> { using type = T&&; };

#endif

    template <typename T> struct add_pointer { using type = T*; };
    template <typename T> struct add_pointer<T&> { using type = T*; };
    template <typename T> struct add_pointer<T&&> { using type = T*; };
    template <typename T> using add_pointer_t = typename add_pointer<T>::type;

    template <bool Cond , typename T, typename F> struct conditional { using type = T; };
    template <typename T, typename F> struct conditional<false, T, F> { using type = F; };
    template <bool Cond, typename T, typename F> using conditional_t = typename conditional<Cond, T, F>::type;

    template <bool Cond, typename T = void> struct enable_if { };
    template <typename T> struct enable_if<true, T> { using type = T; };
    template <bool Cond, typename T = void> using enable_if_t = typename enable_if<Cond, T>::type;

    template <typename T, T v>
    struct integral_constant {
        static constexpr T value = v;
        using value_type = T;
        using type = integral_constant<T, v>;

        constexpr explicit operator value_type() const noexcept { return value; }
        constexpr value_type operator()() const noexcept { return value; }
    };

    using true_type = integral_constant<bool, true>;
    using false_type = integral_constant<bool, false>;

    template<typename T>
    struct is_integral : false_type {};

    template <> struct is_integral<int> : true_type {};
    template <> struct is_integral<char> : true_type {};
    template <> struct is_integral<short> : true_type {};
    template <> struct is_integral<long> : true_type {};
    template <> struct is_integral<long long> : true_type {};
    template <> struct is_integral<unsigned int> : true_type {};
    template <> struct is_integral<unsigned char> : true_type {};
    template <> struct is_integral<unsigned short> : true_type {};
    template <> struct is_integral<unsigned long> : true_type {};
    template <> struct is_integral<unsigned long long> : true_type {};
    template <typename T> struct is_integral<const T> : is_integral<T> {};
    template <typename T> struct is_integral<volatile T> : is_integral<T> {};
    template <typename T> struct is_integral<const volatile T> : is_integral<T> {};
    template <typename T> constexpr bool is_integral_v = is_integral<T>::value;

    template <typename T> struct is_array : false_type {};
    template <typename T> struct is_array<T[]> : true_type {};
    template <typename T, size_t N> struct is_array<T[N]> : true_type {};
    template <typename T> constexpr bool is_array_v = is_array<T>::value;

    template <typename T, typename U> struct is_same : false_type {};
    template <typename T> struct is_same<T, T> : true_type {};
    template <typename T, typename U> constexpr bool is_same_v = is_same<T, U>::value;

    template <typename T> struct is_const : false_type {};
    template <typename T> struct is_const<const T> : true_type {};
    template <typename T> constexpr bool is_const_v = is_const<T>::value;

    template <typename T> struct is_reference : false_type {};
    template <typename T> struct is_reference<T&> : true_type {};
    template <typename T> struct is_reference<T&&> : true_type {};
    template <typename T> constexpr bool is_reference_v = is_reference<T>::value;

    template <typename T> struct is_function : false_type {};
    template <typename Ret, typename... Args> struct is_function<Ret(Args...)> : true_type {};
    template <typename Ret, typename... Args> struct is_function<Ret(Args..., ...)> : true_type {};
    template <typename T> constexpr bool is_function_v = is_function<T>::value;

    template <typename T> struct is_void : false_type {};
    template <> struct is_void<void> : true_type {};
    template <typename T> constexpr bool is_void_v = is_void<T>::value;

    template <typename T> struct is_null_pointer : false_type {};
    template <> struct is_null_pointer<nullptr_t> : true_type {};
    template <typename T> constexpr bool is_null_pointer_v = is_null_pointer<T>::value;

    template <typename T> struct is_floating_point : false_type {};
    template <> struct is_floating_point<float> : true_type {};
    template <> struct is_floating_point<double> : true_type {};
    template <> struct is_floating_point<long double> : true_type {};
    template <typename T> constexpr bool is_floating_point_v = is_floating_point<T>::value;

    template <typename T> struct is_arithmetic : false_type {};
    template <typename T> struct is_arithmetic<is_integral<T>> : true_type {};
    template <typename T> struct is_arithmetic<is_floating_point<T>> : true_type {};
    template <typename T> constexpr bool is_arithmetic_v = is_arithmetic<T>::value;

#ifdef __has_feature(__is_enum)
    template <typename T> struct is_enum : false_type {};
    template <typename T> struct is_enum<T> : integral_constant<bool, __is_enum(T)> {};
#else
    #include <type_traits>
    template <typename T> struct is_enum : integral_constant<bool, std::is_enum_v<T>> {};
#endif
    template <typename T> constexpr bool is_enum_v = is_enum<T>::value;

#ifdef __has_feature(__is_union)
    template <typename T> struct is_union : false_type {};
    template <typename T> struct is_union<T> : integral_constant<bool, __is_union(T)> {};
#else
    #include <type_traits>
    template <typename T> struct is_union : integral_constant<bool, std::is_union_v<T>> {};
#endif
    template <typename T> constexpr bool is_union_v = is_union<T>::value;

#ifdef __has_feature(__is_class)
    template <typename T> struct is_class : false_type {};
    template <typename T> struct is_class<T> : integral_constant<bool, __is_class(T)> {};
#else
    #include <type_traits>
    template <typename T> struct is_class : integral_constant<bool, std::is_class_v<T>> {};
#endif
    template <typename T> constexpr bool is_class_v = is_class<T>::value;

    template <typename T> struct is_pointer : false_type {};
    template <typename T> struct is_pointer<T*> : true_type {};
    template <typename T> struct is_pointer<T* const> : true_type {};
    template <typename T> struct is_pointer<T* volatile> : true_type {};
    template <typename T> struct is_pointer<T* const volatile> : true_type {};
    template <typename T> constexpr bool is_pointer_v = is_pointer<T>::value;

    template <typename T> struct is_member_pointer : false_type {};
    template <typename T, typename U> struct is_member_pointer<T U::*> : true_type {};
    template <typename T> constexpr bool is_member_pointer_v = is_member_pointer<T>::value;

    template<typename T>
    struct decay {
    private:
        using U = remove_reference_t<T>;
    public:
        using type = typename conditional<
            is_array_v<U>,
            remove_extent_t<U>*,
            typename conditional<
                is_function_v<U>,
                add_pointer_t<U>,
                remove_cv_t<U>
            >::type
        >::type;
    };

    template <typename T> using decay_t = typename decay<T>::type;




}

#endif //TYPE_TRAITS_HPP
