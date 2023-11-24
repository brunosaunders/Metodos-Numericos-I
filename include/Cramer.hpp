#ifndef METODOS_NUMERICOS1_INCLUDE_CRAMER_HPP_
#define METODOS_NUMERICOS1_INCLUDE_CRAMER_HPP_

#include <vector>
#include <string>

namespace metodos_numericos1::metodos {
    class Cramer {
        private:
            double a;
            double amplitude_limite;
            std::vector<double> vetor_v;
            std::vector<std::vector<double>> matriz_c;
            std::vector<double> vetor_d_deslocamentos;

        public:
            Cramer(std::vector<std::vector<double>> matriz_c,
                std::vector<double> vetor_v, 
                double a, double amp_limite=3.0) : a(a),
                vetor_v(vetor_v), matriz_c(matriz_c), amplitude_limite(amp_limite) {}

            void resolve_sistema_linear();
            std::vector<double> get_vetor_d_deslocamentos();
            std::vector<double> get_vetor_amplitudes();
            std::string get_balanco_quebra();
    };
}

#endif