#include <iostream>
#include "Polinomio.hpp"
#include "NewtonRaphsonComDerivadaNumerica.hpp"
#include "NewtonRaphsonFL.hpp"

void print_vector(std::vector<double> v) {
    std::cout << "[";
    for (auto& item : v) {
        std::cout << item << " ";
    }
    std::cout << "]\n";
}

void testa_polinomios() {
    Polinomio p = Polinomio({ 1.0, 0, -3, 2 });

    std::pair<double, double> intervalo = p.intervalo_max();
    std::cout << "[" << intervalo.first << " " << intervalo.second << "]\n";
    p.encontra_intervalos(intervalo.first, intervalo.second, 1);

    for (const auto& root : p.intervalos) {
        std::cout << "Raiz no intervalo [" << root.first << ", " << root.second << "]\n";
    }    
}

int main() {
    // Polinomio p = Polinomio({ 1.0, 0, -9.0, 3.0 }); // x³ - 9x + 3 ----> Derivada = 3x^2 - 9
    // std::cout << p.get_grau() << std::endl;
    // std::cout << p.get_valor_funcao(10.0) << std::endl;
    
    // std::pair<double, double> interval = p.intervalo_max(p.coeficientes);
    // p.encontra_intervalos(interval.first, interval.second);

    // for (const auto& root : p.intervalos) {
    //     std::cout << "Raiz no intervalo [" << root.first << ", " << root.second << "]\n";
    // }    

    testa_polinomios();



    return 0;
}
