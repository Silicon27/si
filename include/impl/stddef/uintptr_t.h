//
// Created by David Yang on 2026-02-20.
//

#ifndef SI_LIB_STDDEF_UINTPTR_T_HPP
#define SI_LIB_STDDEF_UINTPTR_T_HPP

#include "../../compat/sconfig.h"
#include "size_t.h"
SI_NAMESPACE_START

#if defined(__UINTPTR_TYPE__)
using uintptr_t = __UINTPTR_TYPE__;
#elif defined(SI_ARCH_BITS)
#   if SI_ARCH_BITS == 64
using uintptr_t = unsigned long long;
#   elif SI_ARCH_BITS == 32
using uintptr_t = unsigned int;
#   elif SI_ARCH_BITS == 16
using uintptr_t = unsigned short;
#   else
using uintptr_t = unsigned int;
#   endif
#else
using uintptr_t = unsigned int;
#endif

SI_NAMESPACE_END

#endif //SI_LIB_STDDEF_UINTPTR_T_HPP