//
// Created by David Yang on 2026-02-20.
//

#ifndef SI_LIB_MEMORY_OFFSET_TO_ALIGNMENT_H
#define SI_LIB_MEMORY_OFFSET_TO_ALIGNMENT_H

#include "../../compat/sconfig.h"
#include "../../si/stddef.hpp"

SI_NAMESPACE_START

inline size_t offset_to_alignment(const size_t offset, const size_t alignment) {
    const size_t misalignment = offset % alignment;
    if (misalignment == 0) {
        return 0;
    }
    return alignment - misalignment;
}

SI_NAMESPACE_END

#endif //SI_LIB_MEMORY_OFFSET_TO_ALIGNMENT_H