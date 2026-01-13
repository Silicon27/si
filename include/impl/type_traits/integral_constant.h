//
// Created by Junie on 2026-01-13.
//

#ifndef SI_LIB_TYPE_TRAITS_INTEGRAL_CONSTANT_H
#define SI_LIB_TYPE_TRAITS_INTEGRAL_CONSTANT_H

#include "../../compat/sconfig.h"

SI_NAMESPACE_START

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

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_INTEGRAL_CONSTANT_H
