#include <iostream>
#include "Painel.hpp"
#include "Polinomio.hpp"
#include "NewtonRaphsonComDerivadaNumerica.hpp"
#include "NewtonRaphsonFL.hpp"
#include "NewtonRaphson.hpp"
#include "Pendulo.hpp"
#include <vector> 
#include <iterator>
#include <iomanip>
#include <cmath>
#include <random>

int main() {
    // Inicializa painel da aplicação;
    metodos_numericos1::include::Painel painel;
    std::vector<NewtonRaphson*> funcoes;
    painel.init(funcoes);
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

