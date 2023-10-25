#include <iostream>
#include <iomanip>
#include "Polinomio.hpp"
#include "NewtonRaphsonComDerivadaNumerica.hpp"
#include "NewtonRaphsonFL.hpp"
#include "NewtonRaphson.hpp"
#include "Vizualizador.hpp"
#include <vector> 
#include <iterator> 
#include "Pendulo.hpp"
#include <iomanip>
#include <cmath>
#include <random>

void print_vector(std::vector<double> v, int precisao) {
    std::cout << std::fixed << std::setprecision(precisao);
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
    Polinomio polinomio = Polinomio({1.0, -3.0, 2});
    std::pair<double, double> p = polinomio.intervalo_max();
    std::cout << polinomio.numero_raizes(p.first, p.second) << std::endl;  
    std::cout << p.first << p.second << std::endl;
    return 0;
}

