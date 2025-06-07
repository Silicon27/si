//
// Created by David Yang on 2025-05-30.
//
#include <iostream>
#include "../include/si/vector.hpp"
#include "../include/si/type_traits.hpp"
#include "../include/si/memory.hpp"

int main() {

    si::vector vec = {1, 2, 3, 4, 5};
    vec.append({6, 7, 8});
    std::cout << "Vector size: " << vec.size() << std::endl;
    std::cout << "Vector capacity: " << vec.capacity() << std::endl;
    vec.reserve(static_cast<int>(vec.capacity()) * 2);
    std::cout << "Vector size after reserve: " << vec.size() << std::endl;
    std::cout << "Vector capacity after reserve: " << vec.capacity() << std::endl;
    vec.append({9, 10});
    std::cout << "Vector contents: ";
    for (int & i : vec) {
        std::cout << i << " ";
    }

    vec.operator[](2) = 100; // Modify the third element

    return 0;
}
