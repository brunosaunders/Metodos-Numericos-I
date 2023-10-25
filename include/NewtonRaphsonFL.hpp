#ifndef NewtonRaphsonFL_HPP
#define NewtonRaphsonFL_HPP
#include "Polinomio.hpp"
#include "NewtonRaphson.hpp"
#include "Derivacao.hpp"

class NewtonRaphsonFL: public NewtonRaphson{ 
    private:
        double lambda;

    public:
        NewtonRaphsonFL(int max_passos, double erro, Polinomio& funcao, double lambda);

        void set_lambda(double l);

        double get_lambda();

        void calcula_raiz(double x0);

        std::string get_nome();
        std::string get_nome_abreviado();
        std::string get_classe(int precision);
};
#endif