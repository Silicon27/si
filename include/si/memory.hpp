//
// Created by David Yang on 2025-05-30.
//

#ifndef MEMORY_HPP
#define MEMORY_HPP

// Types and const definitions
SI_NAMESPACE_START
    using size_t = unsigned long;

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

#include "../impl/memory/allocator.h""
#include "../impl/memory/allocator_traits.h"

#endif //MEMORY_HPP
