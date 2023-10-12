#include <iostream>
#include "Polinomio.hpp"
#include "Vizualizador.hpp"
#include <vector> 
#include <iterator> 
#include "NewtonRaphson.hpp"
#include "Pendulo.hpp"
#include <iomanip>

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
    Polinomio p = Polinomio({1.0, -3.0, 2.0}); // x² - 3x + 2
    //std::cout << p.get_grau() << std::endl;
    teste_vizualizador();
    return 0;
}

