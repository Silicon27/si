//
// Created by David Yang on 2025-05-30.
//
#include <iostream>
#include <initializer_list>
#include "../include/si/vector.hpp"
#include "../include/si/type_traits.hpp"
#include "../include/si/memory.hpp"

int main() {
    si::allocator<int> alloc;

    auto my_block = alloc.allocate(10);
    for (int i = 0; i < 10; ++i) {
        std::allocator_traits<si::allocator<int>>::construct(alloc, my_block + i, i);
    }

    return 0;
}
