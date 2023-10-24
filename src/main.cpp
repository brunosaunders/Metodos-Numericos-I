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

void testa_passos() {
    Pendulo p(1, -1);
    NewtonRaphson* nr = new NewtonRaphson(100, 0.001, p);
    NewtonRaphson* nr_d = new NewtonRaphsonComDerivadaNumerica(100, 0.00001, p);
    Passos::exibir_passos(nr);
    Passos::exibir_passos(nr_d);    
}


int main() {
    //Testa passos
    testa_passos();
    return 0;
}
