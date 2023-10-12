#ifndef VIZUALIZADOR_HPP
#define VIZUALIZADOR_HPP 

#include "Metodo.hpp"
#include "Polinomio.hpp"
#include <vector>

class Vizualizador { 
public: 
        Vizualizador (); 
        void print_quadro_coeficientes_fixos(Polinomio,std::vector<Metodo*>,int);
}; 

#endif