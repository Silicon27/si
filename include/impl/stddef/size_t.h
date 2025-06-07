//
// Created by David Yang on 2025-06-04.
//

#ifndef SI_LIB_STDDEF_SIZE_T_H
#define SI_LIB_STDDEF_SIZE_T_H
#include "../../compat/sconfig.h"

SI_NAMESPACE_START

#if defined(__SIZE_TYPE__)
    using size_t = __SIZE_TYPE__;
#elif defined(SI_MSVC)
    #if defined(_WIN64)
        using size_t = unsigned __int64; // 64-bit Windows
    #elif defined(_WIN32)
        using size_t = unsigned int;     // 32-bit Windows
    #else
        using size_t = unsigned long;    // 32-bit Linux/macOS
    #endif
#else
    using size_t = unsigned long; // Default to unsigned long for other platforms
#endif

SI_NAMESPACE_END

#endif //SI_LIB_STDDEF_SIZE_T_H
