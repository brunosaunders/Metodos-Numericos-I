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
    Pendulo p(1, -1);
    NewtonRaphson* nr = new NewtonRaphson(100, 0.001, p);
    NewtonRaphson* nr_d = new NewtonRaphsonComDerivadaNumerica(100, 0.00001, p);
    Passos::exibir_passos(nr);
    Passos::exibir_passos(nr_d);    
}


void teste_vizualizador() {
    std::vector<vizualizador::EntradasLinhaQuadroComparativo> entradas;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> double_dist(1.0, 1000.0);

    for (int i = 0; i < 100; i++) {
        int metodo = i % 3;  // Alternar entre os três métodos (0, 1, 2)
        double a3 = double_dist(gen);
        double a2 = double_dist(gen);
        double lambda = double_dist(gen);
        double epsilon = double_dist(gen);

        entradas.push_back(vizualizador::EntradasLinhaQuadroComparativo{metodo, a3, a2, lambda,epsilon});
    }
    double intervalo[2] {1.23,34.9};
    vizualizador::print_quadro_comparativo(entradas, 6,10,intervalo);
}

int main() {
    int precisao = 6;
    std::vector<double> coef = {-2, 1, 1}; 
    Polinomio p(coef); 
    NewtonRaphson nr(100, 0.001, p); 
    NewtonRaphsonFL nr_fl(100, 0.001, p, 0.5);
    NewtonRaphsonComDerivadaNumerica nr_d(100, 0.001, p);

    nr.calcula_raiz(1.5); 
    nr_fl.calcula_raiz(1.5);
    nr_d.calcula_raiz(1.5);

    teste_vizualizador();

    //Testa passos
    testa_passos();
    return 0;
}

