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
    return 0;
}

