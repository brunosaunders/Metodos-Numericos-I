#ifndef METODOS_NUMERICOS1_INCLUDE_UTILS_HPP
#define METODOS_NUMERICOS1_INCLUDE_UTILS_HPP

#include <vector> 

namespace metodos_numericos1::outputs { 
    class Imprimir {
        public:
            static void matriz(std::vector<std::vector<double>> matriz);
            static void vetor(std::vector<double> v);
    };
}; 
#endif
