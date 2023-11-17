#ifndef METODOS_NUMERICOS1_INCLUDE_GAUSSJORDAN_HPP_
#define METODOS_NUMERICOS1_INCLUDE_GAUSSJORDAN_HPP_

#include <vector>
#include "Gauss.hpp"

namespace metodos_numericos1::metodos {

    class GaussJordan : public Gauss {
        public:
            void resolve_sistema_linear() override;
    };
}

#endif