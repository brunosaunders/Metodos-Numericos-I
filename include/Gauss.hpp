#ifndef METODOS_NUMERICOS1_INCLUDE_GAUSS_HPP_
#define METODOS_NUMERICOS1_INCLUDE_GAUSS_HPP_

#include <vector>
#include <string>

#include "Metodo.hpp"

namespace metodos_numericos1::metodos
{
        class Gauss : public Metodo
        {
        private:
            int trocas_de_linha;

        public:
            Gauss(std::vector<std::vector<double>> matriz_c,
                std::vector<double> vetor_v, 
                double a, double amp_limite=3.0) : Metodo(matriz_c, vetor_v, a, amp_limite), trocas_de_linha(0) {}

            void resolve_sistema_linear() override;

            double get_determinante_matriz_c();

            std::string get_nome_abreviado() override;
            int get_trocas_de_linha();

            void set_trocas_de_linha(int trocas_de_linha); 
    };
}

#endif