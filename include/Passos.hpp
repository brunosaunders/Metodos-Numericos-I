#ifndef METODOS_NUMERICOS1_OUTPUTS_PASSOS
#define METODOS_NUMERICOS1_OUTPUTS_PASSOS

#include <vector>
#include <string>

#include "NewtonRaphson.hpp"

namespace metodos_numericos1 {
    namespace outputs {
        class Passos {
            public:
                static void exibir_passos(NewtonRaphson* metodo);
        };
    }
}

#endif