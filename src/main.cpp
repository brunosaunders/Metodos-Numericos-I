#include <iostream>
#include "Painel.hpp"
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

    Polinomio p = Polinomio({ 1.0, 0, -9.0, 3.0 }); // x³ - 9x + 3 ----> Derivada = 3x^2 - 9
    std::cout << p.get_grau() << std::endl;
    std::cout << p.get_valor_funcao(10.0) << std::endl;

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
    // Inicializa painel da aplicação;
    metodos_numericos1::include::Painel painel;
    painel.init();
    //int precisao = 6;
    //std::vector<double> coef = {-2, 1, 1}; 
    //Polinomio p(coef); 
    //NewtonRaphson nr(100, 0.001, p); 
    //NewtonRaphsonFL nr_fl(100, 0.001, p, 0.5);
    //NewtonRaphsonComDerivadaNumerica nr_d(100, 0.001, p);

    //nr.calcula_raiz(1.5); 
    //nr_fl.calcula_raiz(1.5);
    //nr_d.calcula_raiz(1.5);

    //print_vector(nr.get_iteracoes_de_x(), precisao);
    //print_vector(nr_fl.get_iteracoes_de_x(), precisao);
    //print_vector(nr_d.get_iteracoes_de_x(), precisao);
    //teste_vizualizador();
    return 0;
}

