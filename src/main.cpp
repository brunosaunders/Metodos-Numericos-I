#include <iostream>
#include "Polinomio.hpp"

void print_vector(std::vector<double> v) {
    std::cout << "[";
    for (auto &item : v) {
        std::cout << item << " ";
    }
    std::cout << "]\n";
}

int main() {
    Polinomio p = Polinomio({1.0, 0, -3.0, 2.0}); // x³ - 3x + 2
    std::cout << p.get_grau() << std::endl;
    std::cout << p.get_valor_funcao(10.0) << std::endl;
    
    print_vector(p.get_funcao_derivada().coeficientes);
}
