#ifndef METODOS_NUMERICOS1_INCLUDE_GAUSSJORDAN_HPP_
#define METODOS_NUMERICOS1_INCLUDE_GAUSSJORDAN_HPP_

#include <vector>
#include "Gauss.hpp"

namespace metodos_numericos1::metodos {

    class GaussJordan : public Gauss {
        public:
            GaussJordan(std::vector<std::vector<double>> matriz_c, std::vector<double> vetor_v, double a): Gauss(matriz_c, vetor_v, a) {}
            void resolve_sistema_linear() override;
    };
}

#endif