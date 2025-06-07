//
// Created by David Yang on 2025-06-05.
//

#ifndef SI_LIB_STDDEF_PTRDIFF_T_H
#define SI_LIB_STDDEF_PTRDIFF_T_H

#include "../../compat/sconfig.h"

SI_NAMESPACE_START
#ifdef _WIN64
    using ptrdiff_t = long long;  // 64-bit Windows
#elif defined(_WIN32)
    using ptrdiff_t = int;        // 32-bit Windows
#elif defined(__x86_64__) || defined(__aarch64__)
    using ptrdiff_t = long;       // 64-bit Linux/macOS
#else
    using ptrdiff_t = int;        // 32-bit Linux/macOS
#endif
SI_NAMESPACE_END

#endif //SI_LIB_STDDEF_PTRDIFF_T_H
