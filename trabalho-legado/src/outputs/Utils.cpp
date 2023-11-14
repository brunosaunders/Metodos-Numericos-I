#include <iostream>

#include "Utils.hpp"


namespace metodos_numericos1::outputs {
    void print_vector(std::vector<double> v)
    {
        std::cout << "[";
        for (auto& item : v) {
            std::cout << item << " ";
        }
        std::cout << "]\n";
    }
}
