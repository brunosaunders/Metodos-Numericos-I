#include <iostream>
#include <iomanip>
#include <cmath>
#include <random>
#include <vector> 
#include <iterator> 

#include "Polinomio.hpp"
#include "NewtonRaphsonComDerivadaNumerica.hpp"
#include "NewtonRaphsonFL.hpp"
#include "Passos.hpp"
#include "NewtonRaphson.hpp"
#include "Pendulo.hpp"
#include "Utils.hpp"
// #include "Vizualizador.hpp"
#include "QuadroComparativo.hpp"


void testa_passos() {
    Pendulo p(1, 1);
    NewtonRaphson* nr = new NewtonRaphson(100, 0.001, p);
    NewtonRaphson* nr_d = new NewtonRaphsonComDerivadaNumerica(100, 0.00001, p);
    std::vector<double> x0s({5, 0, 2});

    metodos_numericos1::outputs::Passos::exibir_passos_todas_raizes(nr);
    metodos_numericos1::outputs::Passos::exibir_passos_todas_raizes(nr_d);    
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

