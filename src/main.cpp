#include <iostream>
#include <iomanip>
#include "Polinomio.hpp"
#include "NewtonRaphsonComDerivadaNumerica.hpp"
#include "NewtonRaphsonFL.hpp"
#include "NewtonRaphson.hpp"

void print_vector(std::vector<double> v, int precisao) {
    std::cout << std::fixed << std::setprecision(precisao);
    std::cout << "[";
    for (auto& item : v) {
        std::cout << item << " ";
    }
    std::cout << "]\n";
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
    
    print_vector(nr.get_iteracoes_de_x(), precisao);
    print_vector(nr_fl.get_iteracoes_de_x(), precisao);
    print_vector(nr_d.get_iteracoes_de_x(), precisao);
    return 0;
}
