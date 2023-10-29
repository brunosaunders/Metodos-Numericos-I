#ifndef METODOS_NUMERICOS1_INCLUDE_PASSOS
#define METODOS_NUMERICOS1_INCLUDE_PASSOS

#include <vector>
#include <string>

#include "NewtonRaphson.hpp"

using namespace metodos_numericos1::metodos;

namespace metodos_numericos1::outputs {
    class Passos {
        public:
            static void exibir_passos_todas_raizes(NewtonRaphson* metodo);
        private:
            static void exibir_passos_raiz(NewtonRaphson* metodo, int index);
    };
}

#endif