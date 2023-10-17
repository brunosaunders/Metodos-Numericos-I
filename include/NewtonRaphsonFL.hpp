#ifndef NewtonRaphsonFL_HPP
#define NewtonRaphsonFL_HPP
#include "Polinomio.hpp"
#include "NewtonRaphson.hpp"
#include "Derivacao.hpp"

class NewtonRaphsonFL: public NewtonRaphson{ 
    public:
        NewtonRaphsonFL(int max_passos, double erro, Polinomio funcao, double lambda);
        double lambda;

        void calcula_raiz(double x0);

};
#endif