//
// Created by David Yang on 2026-01-14.
//

#ifndef SI_LIB_IOS_BASIC_IOS_HPP
#define SI_LIB_IOS_BASIC_IOS_HPP
#include "compat/compiler_features.hpp"
#include "compat/sconfig.h"

#include "ios_base.h"
#include "../string/char_traits.hpp"

SI_NAMESPACE_START

template <typename CharT, typename Traits = char_traits<CharT>>
struct basic_ios : ios_base {
    using char_type = CharT;
    using traits_type = Traits;

    basic_ios() noexcept = default;
    ~basic_ios() noexcept override = default;


};

SI_NAMESPACE_END

#endif //SI_LIB_IOS_BASIC_IOS_HPP