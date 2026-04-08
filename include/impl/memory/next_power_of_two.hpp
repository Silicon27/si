//
// Created by David Yang on 2026-04-08.
//

#ifndef SI_LIB_MEMORY_NEXT_POWER_OF_TWO_HPP
#define SI_LIB_MEMORY_NEXT_POWER_OF_TWO_HPP

#include "../../compat/sconfig.h"
#include "si/type_traits.hpp"
#include "si/limits.hpp"

namespace si {
    template<typename T>
    constexpr T next_power_of_two(T x) {
        static_assert(si::is_unsigned_v<T>, "T must be unsigned");

        if (x <= 1) return 1;

        --x; // critical to handle exact powers of two

        for (si::size_t i = 1; i < si::numeric_limits<T>::digits; i <<= 1) {
            x |= x >> i;
        }

        return x + 1;
    }
}

#endif //SI_LIB_MEMORY_NEXT_POWER_OF_TWO_HPP
