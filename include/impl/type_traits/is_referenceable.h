//
// Created by Junie on 2026-01-13.
//

#ifndef SI_LIB_TYPE_TRAITS_IS_REFERENCEABLE_H
#define SI_LIB_TYPE_TRAITS_IS_REFERENCEABLE_H

#include "../../compat/sconfig.h"

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

#endif //SI_LIB_TYPE_TRAITS_IS_REFERENCEABLE_H
