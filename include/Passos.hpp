#ifndef METODOS_NUMERICOS1_INCLUDE_PASSOS
#define METODOS_NUMERICOS1_INCLUDE_PASSOS

#include <vector>
#include <string>

namespace metodos_numericos1::outputs {
    class Passos {
        public:
            static void exibir_passos_todas_raizes(int metodo);
        private:
            static void exibir_passos_raiz(int metodo, int index);
    };
}

#endif