#ifndef NEWTONRAPHSONCOMDERIVADANUMERICA_HPP
#define NEWTONRAPHSONCOMDERIVADANUMERICA_HPP

#include "Polinomio.hpp"
#include "NewtonRaphson.hpp"
#include "Derivacao.hpp"

class NewtonRaphsonComDerivadaNumerica:public NewtonRaphson{ 
    public:
        NewtonRaphsonComDerivadaNumerica(int max_passos, double erro, Polinomio funcao): NewtonRaphson(max_passos,erro, funcao) {}
        Derivacao derivador;

        void calcula_raiz(double x0);
};
#endif