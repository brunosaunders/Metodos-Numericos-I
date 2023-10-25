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


void test_quadro_comparativo() {
    // std::vector<vizualizador::EntradasLinhaQuadroComparativo> entradas;
    std::vector<NewtonRaphson*> metodos;

    // for (int i=1; i < 10; i++) {
    //     for (int j=1; j < 10; j++) {
    //         double a3 = j;
    //         double a2 = i;
    //         double epsilon = 0.0001;

    //         entradas.push_back(vizualizador::EntradasLinhaQuadroComparativo{1, a3, a2, 0.5, epsilon});
    //     }
    // }

    // entradas.push_back(vizualizador::EntradasLinhaQuadroComparativo{0, 1, 1, 0, 0.0001});
    // entradas.push_back(vizualizador::EntradasLinhaQuadroComparativo{0, 1, -1, 0, 0.0001});

    Polinomio p = Pendulo(1, 1);
    metodos.push_back(new NewtonRaphson(100, 0.001, p));
    metodos.push_back(new NewtonRaphsonFL(100, 0.001, p, 0.5));

    double intervalo[2] {0, 10};
    // vizualizador::print_quadro_comparativo(entradas, 4, 100, intervalo);
    metodos_numericos1::outputs::QuadroComparativo::exibir_quadro(metodos);

}

int main() {
    // test_quadro_comparativo();

    //Testa passos
    testa_passos();
    return 0;
}

