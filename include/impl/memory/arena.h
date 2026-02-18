//
// Created by David Yang on 2026-02-18.
//

#ifndef SI_LIB_MEMORY_ARENA_H
#define SI_LIB_MEMORY_ARENA_H

#include "../../compat/sconfig.h"
#include <si/utility.hpp>


SI_NAMESPACE_START

class arena {
public:
    explicit arena(size_t size);
    ~arena();
private:
    char* data;
};

SI_NAMESPACE_END

#endif //SI_LIB_MEMORY_ARENA_H