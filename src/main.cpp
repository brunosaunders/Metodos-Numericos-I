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
#include "QuadroComparativo.hpp"

using namespace std;

void testa_passos() {
    Pendulo p(1, 1);
    NewtonRaphson* nr = new NewtonRaphson(100, 0.001, p);
    NewtonRaphson* nr_d = new NewtonRaphsonComDerivadaNumerica(100, 0.00001, p);
    std::vector<double> x0s({5, 0, 2});

    metodos_numericos1::outputs::Passos::exibir_passos_todas_raizes(nr);
    metodos_numericos1::outputs::Passos::exibir_passos_todas_raizes(nr_d);    
}


void testa_quadro_comparativo() {
    std::vector<NewtonRaphson*> metodos;

    Polinomio p = Pendulo(1.3332, 1);
    Polinomio p2 = Pendulo(-9, 2);
    Polinomio p3 = Pendulo(5, 2);
    metodos.push_back(new NewtonRaphson(100, 0.001, p));
    metodos.push_back(new NewtonRaphsonFL(100, 0.001, p, 0.5));
    metodos.push_back(new NewtonRaphsonComDerivadaNumerica(100, 0.001, p));

    metodos.push_back(new NewtonRaphson(100, 0.001, p2));
    metodos.push_back(new NewtonRaphsonFL(100, 0.001, p2, 0.5));
    metodos.push_back(new NewtonRaphsonComDerivadaNumerica(100, 0.001, p2));

    metodos.push_back(new NewtonRaphson(100, 0.001, p3));
    metodos.push_back(new NewtonRaphsonFL(100, 0.001, p3, 0.5));
    metodos.push_back(new NewtonRaphsonComDerivadaNumerica(100, 0.001, p3));

    double intervalo[2] {0, 10};
    metodos_numericos1::outputs::QuadroComparativo::exibir_quadro(metodos);

}

int main() {
    testa_quadro_comparativo();
    // std::string a = "Sim";
    // std::string b = "Não";
    // cout << a.size() << endl << b.size();
    return 0;
}

