#include <iostream>
#include "Polinomio.hpp"
#include "Vizualizador.hpp"
#include <vector> 
#include <iterator> 
#include "NewtonRaphson.hpp"
#include "Pendulo.hpp"
#include <iomanip>
#include <cmath>
#include <random>
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
// std::vector<vizualizador::EntradasLinhaQuadroComparativo> entradas {
//     {2, 4123.4124, 1245.2133002, 123.2, 999.3939},
//     {0, 10.9, 22.0, 72.2},
//     {1, 10.9, 22.0, 72.2},
//     {0, 5.6, 11.0, 41.3},
//     {1, 7.8, 16.5, 63.7},
//     {2, 15.2, 31.4, 121.9},
//     {0, 3.2, 7.0, 31.6},
//     {1, 12.5, 28.8, 112.4},
//     {2, 21.7, 42.3, 167.8},
//     {0, 6.1, 13.7, 55.9}
// };
vizualizador::print_quadro_comparativo(entradas, 2);
}
int main() {
    
    teste_vizualizador(); 
    return 0;
}

