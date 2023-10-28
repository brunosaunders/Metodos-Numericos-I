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
    Polinomio p = Pendulo(1,-1);

    std::pair<double, double> intervalo = p.intervalo_max();
    int qtd_raizes = p.numero_raizes_reais(intervalo.first, intervalo.second);
    p.encontra_intervalos(intervalo.first, intervalo.second, qtd_raizes);

    for (const auto& root : p.intervalos) {
        std::cout << "Raiz no intervalo [" << root.first << ", " << root.second << "]\n";
    }    
    std::cout << "eae\n";
}

void testa_divisao() {
    Polinomio p = Pendulo(1, -1);
    Polinomio p_deriv = p.get_funcao_derivada();
    p.print();
    p_deriv.print();

    Polinomio p_div = p.divide(p_deriv);
    p_div.print();

    Polinomio p_div2 = p_deriv.divide(p_div);
    p_div2.print();
}

void testa_isolamento() {
    Polinomio p = Pendulo(1,-1);
    std::cout << p.numero_raizes_reais(-3.16, 2.82);
}

int main() {
    testa_polinomios();
    
    // testa_isolamento();
    // testa_divisao();
    return 0;
}

