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
#include "Vizualizador.hpp"


void testa_passos() {
    Pendulo p(1, 1);
    NewtonRaphson* nr = new NewtonRaphson(100, 0.001, p);
    NewtonRaphson* nr_d = new NewtonRaphsonComDerivadaNumerica(100, 0.00001, p);
    metodos_numericos1::outputs::Passos::exibir_passos(nr);
    metodos_numericos1::outputs::Passos::exibir_passos(nr_d);    
}


void teste_vizualizador() {
    std::vector<vizualizador::EntradasLinhaQuadroComparativo> entradas;

    // for (int i=1; i < 10; i++) {
    //     for (int j=1; j < 10; j++) {
    //         double a3 = j;
    //         double a2 = i;
    //         double epsilon = 0.0001;

    //         entradas.push_back(vizualizador::EntradasLinhaQuadroComparativo{1, a3, a2, 0.5, epsilon});
    //     }
    // }

    entradas.push_back(vizualizador::EntradasLinhaQuadroComparativo{0, 1, 1, 0, 0.0001});
    entradas.push_back(vizualizador::EntradasLinhaQuadroComparativo{0, 1, -1, 0, 0.0001});

    double intervalo[2] {0, 10};
    vizualizador::print_quadro_comparativo(entradas, 4, 100, intervalo);
}

int main() {
    // int precisao = 6;
    // std::vector<double> coef = {-2, 1, 1}; 
    // Polinomio p(coef); 
    // NewtonRaphson nr(100, 0.001, p); 
    // NewtonRaphsonFL nr_fl(100, 0.001, p, 0.5);
    // NewtonRaphsonComDerivadaNumerica nr_d(100, 0.001, p);

    // nr.calcula_raiz(1.5); 
    // nr_fl.calcula_raiz(1.5);
    // nr_d.calcula_raiz(1.5);

    teste_vizualizador();

    //Testa passos
    testa_passos();
    return 0;
}

