#ifndef NewtonRaphsonFL_HPP
#define NewtonRaphsonFL_HPP
#include "Polinomio.hpp"
#include "NewtonRaphson.hpp"
#include "Derivacao.hpp"

class NewtonRaphsonFL: public NewtonRaphson{ 
    private:
        double lambda;

    public:
        NewtonRaphsonFL(int max_passos, double erro, Polinomio funcao, double lambda);

        double get_lambda() const;
        void set_lambda(double l);

        void calcula_raiz(double x0);

};
#endif