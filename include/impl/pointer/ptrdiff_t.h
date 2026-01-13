//
// Created by David Yang on 2025-06-09.
//

#ifndef SI_LIB_POINTER_PTRDIFF_T_H
#define SI_LIB_POINTER_PTRDIFF_T_H

#include "../../compat/sconfig.h"

SI_NAMESPACE_START

#ifdef __PTRDIFF_TYPE__
    typedef __PTRDIFF_TYPE__ ptrdiff_t;

#elif defined(_WIN64)
    typedef __int64 ptrdiff_t;

#elif defined(_WIN32)
    typedef int ptrdiff_t;

#elif defined(__x86_64__)
    typedef long ptrdiff_t;

#elif defined(__i386__)
    typedef int ptrdiff_t;

#elif defined(__aarch64__)
    typedef long ptrdiff_t;

#elif defined(__arm__)
    typedef int ptrdiff_t;

#elif defined(__mips__)
    typedef long ptrdiff_t;

#else
    typedef long ptrdiff_t;

#endif

SI_NAMESPACE_END


#endif //SI_LIB_POINTER_PTRDIFF_T_H
