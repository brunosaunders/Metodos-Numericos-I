#include <iostream>

#include "Utils.hpp"


void Utils::print_vector(std::vector<double> v) {
    std::cout << "[";
    for (auto& item : v) {
        std::cout << item << " ";
    }
    std::cout << "]\n";
}
