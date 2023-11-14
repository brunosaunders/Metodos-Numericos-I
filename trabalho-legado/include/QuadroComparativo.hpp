#ifndef METODOS_NUMERICOS1_INCLUDE_QUADRO_COMPARATIVO_HPP
#define METODOS_NUMERICOS1_INCLUDE_QUADRO_COMPARATIVO_HPP 

#include <vector>
#include <iostream>

#include "Polinomio.hpp"
#include "NewtonRaphson.hpp"

using namespace metodos_numericos1::metodos;

namespace metodos_numericos1::outputs
{
    class QuadroComparativo {
        public:
            static void exibir_quadro(std::vector<NewtonRaphson*> metodos);
    };
}
#endif
