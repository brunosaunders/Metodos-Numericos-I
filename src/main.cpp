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
    Polinomio p = Polinomio({ 4.0, 3.0, 0.0, 0.0, 3.0 });

    std::pair<double, double> intervalo = p.intervalo_max();
    int qtd_raizes = p.numero_raizes_reais(intervalo.first, intervalo.second);
    p.encontra_intervalos(intervalo.first, intervalo.second, qtd_raizes);

    for (const auto& root : p.intervalos) {
        std::cout << "Raiz no intervalo [" << root.first << ", " << root.second << "]\n";
    }    
}

int main() {
    testa_polinomios();
    return 0;
}

