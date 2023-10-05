#include <iostream>
#include "../include/Polinomio.hpp"


int main() {
    Polinomio p = Polinomio({1.0, -3.0, 2.0}); // x² - 3x + 2
    std::cout << p.get_grau() << std::endl;
}