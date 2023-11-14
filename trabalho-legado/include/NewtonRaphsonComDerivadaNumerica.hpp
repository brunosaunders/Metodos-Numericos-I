#ifndef METODOS_NUMERICOS1_INCLUDE_NEWTONRAPHSONCOMDERIVADANUMERICA_HPP
#define METODOS_NUMERICOS1_INCLUDE_NEWTONRAPHSONCOMDERIVADANUMERICA_HPP

#include <string>

#include "Polinomio.hpp"
#include "NewtonRaphson.hpp"
#include "Derivacao.hpp"

using namespace metodos_numericos1::funcoes;

namespace metodos_numericos1::metodos {

    class NewtonRaphsonComDerivadaNumerica : public NewtonRaphson
    {
    public:
        NewtonRaphsonComDerivadaNumerica(int max_passos, double erro,
                                        Polinomio &funcao) : NewtonRaphson(max_passos, erro, funcao) {}
        
        Derivacao derivador;

        std::string get_nome();
        std::string get_nome_abreviado();
        std::string get_classe(int precision);

        void calcula_raiz(double x0);
    };
}
#endif