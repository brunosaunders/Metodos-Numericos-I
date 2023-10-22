#include <iostream>
#include "Polinomio.hpp"
#include "NewtonRaphsonComDerivadaNumerica.hpp"
#include "NewtonRaphsonFL.hpp"
#include "Vizualizador.hpp"
#include <vector> 
#include <iterator> 
#include "NewtonRaphson.hpp"
#include "Pendulo.hpp"
#include <iomanip>
#include <cmath>
#include <random>

void print_vector(std::vector<double> v) {
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
    vizualizador::print_quadro_comparativo(entradas, 6,10);
}

int main() {
    Polinomio p = Polinomio({ 1.0, 0, -9.0, 3.0 }); // x³ - 9x + 3 ----> Derivada = 3x^2 - 9
    std::cout << p.get_grau() << std::endl;
    std::cout << p.get_valor_funcao(10.0) << std::endl;

    print_vector(p.get_funcao_derivada().coeficientes);

    NewtonRaphsonComDerivadaNumerica numerica(1000, 0.001, p);
    NewtonRaphsonFL fl(1000, 0.001, p, 0.05);

    numerica.calcula_raiz(0.5);
    fl.calcula_raiz(0.5);

    print_vector(numerica.get_iteracoes_de_x());
    print_vector(fl.get_iteracoes_de_x());


    //Teste tabela    
    teste_vizualizador(); 
    return 0;
}

