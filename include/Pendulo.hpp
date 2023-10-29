#ifndef PENDULO_HPP
#define PENDULO_HPP

#include "Polinomio.hpp"

using namespace metodos_numericos1::funcoes;

namespace metodos_numericos1::funcoes {

    /**
     * Representação do polinômio que modela a oscilação de um pêndulo: 
     * f(d) = a_3d^3 – 9a_2d + 3 
    */
    class Pendulo:public Polinomio { 
        public:
            /* P(d) = a3 d³ - 9*a2 d² + 3 */
            Pendulo (double a3,double a2) : Polinomio({a3, 0, 9*a2, 3}){}
    }; 
}
#endif