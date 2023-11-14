#ifndef NewtonRaphsonFL_HPP
#define NewtonRaphsonFL_HPP
#include "Polinomio.hpp"
#include "NewtonRaphson.hpp"
#include "Derivacao.hpp"

using namespace metodos_numericos1::funcoes;

namespace metodos_numericos1::metodos {

    class NewtonRaphsonFL: public NewtonRaphson{ 
        private:
            double lambda;

        public:
            NewtonRaphsonFL(int max_passos, double erro, Polinomio& funcao, double lambda);

            double get_lambda();
            std::string get_nome();
            std::string get_nome_abreviado();
            std::string get_classe(int precision);

            void calcula_raiz(double x0);
    };
}
#endif
