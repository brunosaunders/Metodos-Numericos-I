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

void print_vector(std::vector<double> v, int precisao) {
    std::cout << std::fixed << std::setprecision(precisao);
    std::cout << "[";
    for (auto& item : v) {
        std::cout << item << " ";
    }
    std::cout << "]\n";
}

void teste_vizualizador(){ 
    Vizualizador v; 
    std::vector<Polinomio> polinomios{Polinomio({1.0,-3.0,2.0}),Pendulo(10,1), Polinomio({77.0,29.0,38.0,21.0,57.0,66.99})} ; 

    // Teste de vizualização 
    NewtonRaphson nr(23,0.9);  
    nr.original(polinomios[1]);
    NewtonRaphson nr2(10,0.1);  
    nr2.original(polinomios[1]);
    v.print_quadro_coeficientes_fixos(polinomios[1],{&nr,&nr2},8); 

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
    teste_vizualizador();
    return 0;
}

