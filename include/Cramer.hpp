#ifndef METODOS_NUMERICOS1_INCLUDE_CRAMER_HPP_
#define METODOS_NUMERICOS1_INCLUDE_CRAMER_HPP_

#include "Metodo.hpp"

namespace metodos_numericos1::metodos {
    class Cramer : public Metodo {

        public:
            Cramer(std::vector<std::vector<double>> matriz_c,
                std::vector<double> vetor_v, 
                double a, double amp_limite=3.0) : Metodo(matriz_c, vetor_v, a, amp_limite) {}

            void resolve_sistema_linear() override;

            std::string get_nome_abreviado() override;

    };
}

#endif