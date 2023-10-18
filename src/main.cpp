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


void print_vector(std::vector<double> v) {
    std::cout << "[";
    for (auto& item : v) {
        std::cout << item << " ";
    }
    std::cout << "]\n";
}

void testa_passos() {
    std::vector<Passos::Passo> passos;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> double_dist(1.0, 1000.0);

    for (int i = 0; i < 10; i++) {
        double a3 = double_dist(gen);
        double a2 = double_dist(gen);
        double lambda = double_dist(gen);
        double epsilon = double_dist(gen);

        for(int metodo = 0; metodo < 3; metodo++) {
            std::string metodoStr;
            if (metodo == 0) {
                metodoStr = "original";
            } else if (metodo == 1) {
                metodoStr = "FL";
            } else if (metodo == 2) {
                metodoStr = "derivada";
            }

            Passos::exibirPassos(metodoStr, a3, a2, lambda, epsilon, 100);
        }
    }
}


int main() {
    // Polinomio p = Polinomio({ 1.0, 0, -9.0, 3.0 }); // x³ - 9x + 3 ----> Derivada = 3x^2 - 9
    // std::cout << p.get_grau() << std::endl;
    // std::cout << p.get_valor_funcao(10.0) << std::endl;

    // print_vector(p.get_funcao_derivada().coeficientes);

    // NewtonRaphsonComDerivadaNumerica numerica(1000, 0.001, p);
    // NewtonRaphsonFL fl(1000, 0.001, p, 0.05);

    // numerica.calcula_raiz(0.5);
    // fl.calcula_raiz(0.5);

    // print_vector(numerica.get_iteracoes_de_x());
    // print_vector(fl.get_iteracoes_de_x());

    //Testa passos
    testa_passos();
    
    return 0;
}
