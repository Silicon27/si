//
// Created by David Yang on 2026-02-20.
//

#ifndef SI_LIB_MEMORY_ALIGN_H
#define SI_LIB_MEMORY_ALIGN_H

#include "../../compat/sconfig.h"
#include <si/stddef.hpp>

SI_NAMESPACE_START

inline void* align(const size_t alignment,
             const size_t size,
             void*& ptr,
             size_t& space ) {
    const uintptr_t     p           = reinterpret_cast<uintptr_t>(ptr);
    const uintptr_t     aligned     = (p + alignment - 1) & ~(alignment - 1);
    const size_t        adjustment  = aligned - p;

    if (adjustment + size > space) {
        return nullptr;
    }

    space   -= adjustment;
    ptr      = reinterpret_cast<void*>(aligned);
    return ptr;
}

SI_NAMESPACE_END

#endif //SI_LIB_MEMORY_ALIGN_H