//
// Created by David Yang on 2025-06-04.
//

#ifndef SI_LIB_STDDEF_NULLPTR_T_H
#define SI_LIB_STDDEF_NULLPTR_T_H

#include "../../compat/sconfig.h"

SI_NAMESPACE_START
    // Define nullptr_t as the type of the null pointer literal
    using nullptr_t = decltype(nullptr);
SI_NAMESPACE_END

#endif //SI_LIB_STDDEF_NULLPTR_T_H
