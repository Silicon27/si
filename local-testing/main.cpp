//
// Created by David Yang on 2025-05-30.
//
#include <iostream>
#include "../include/si/vector.hpp"
#include "../include/si/type_traits.hpp"

int main() {
    si::Vector vec = {1, 2, 3, 4, 5};

    std::cout << vec[2] << std::endl;

    vec[2] = 10;

    std::cout << vec[2] << std::endl;

    vec.push_back({6, 7, 8});

    for (int & it : vec) {
        std::cout << it << " ";
    }

    si::add_rvalue_reference_t<int> a = 10;
    // Check if a is an rvalue reference

    if (si::is_reference_v<decltype(a)>) {
        std::cout << "\n'a' is a reference type." << std::endl;
    } else {
        std::cout << "\n'a' is not a reference type." << std::endl;
    }

    if (si::is_same_v<si::remove_reference_t<decltype(a)>, int>) {
        std::cout << "'a' is of type int." << std::endl << "it is of type: " << typeid(decltype(a)).name() << std::endl;
    } else {
        std::cout << "'a' is not of type int." << std::endl << "it is of type: " << typeid(a).name() << std::endl;
    }

    return 0;
}
