//
// Created by David Yang on 2025-05-30.
//
#include <iostream>
#include "../include/si/vector.hpp"

int main() {
    si::Vector vec = {1, 2, 3, 4, 5};

    std::cout << vec[2] << std::endl;

    vec[2] = 10;

    std::cout << vec[2] << std::endl;

    vec.push_back({6, 7, 8});

    for (int & it : vec) {
        std::cout << it << " ";
    }

    return 0;
}
