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


void print_vector(std::vector<double> v, int precisao) {
    std::cout << std::fixed << std::setprecision(precisao);
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
    //Testa passos
    testa_passos();
    return 0;
}
