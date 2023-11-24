#ifndef METODOS_NUMERICOS1_INCLUDE_GAUSS_HPP_
#define METODOS_NUMERICOS1_INCLUDE_GAUSS_HPP_

#include <vector>

namespace metodos_numericos1::metodos
{
        class Gauss
        {
        private:
            double a;
            double amplitude_limite;
            std::vector<double> vetor_v;
            std::vector<std::vector<double>> matriz_c;
            std::vector<double> vetor_d_deslocamentos;

            /* Não faremos operações com essas variáveis. Serão utilizadas para imprimir o estado inicial do sistema linear. */
            std::vector<double> vetor_v_inicial;
            std::vector<std::vector<double>> matriz_c_inicial;

        public:
            Gauss(std::vector<std::vector<double>> matriz_c,
                std::vector<double> vetor_v, 
                double a, double amp_limite=3.0) : a(a), matriz_c_inicial(matriz_c), vetor_v_inicial(vetor_v),
                vetor_v(vetor_v), matriz_c(matriz_c), amplitude_limite(amp_limite) {}

            virtual void resolve_sistema_linear();

            bool get_balanco_quebra();

            double get_a();
            std::vector<double> get_vetor_v_inicial();
            std::vector<std::vector<double>> get_matriz_c_inicial();

            std::vector<double> get_vetor_v();
            std::vector<double> get_vetor_amplitudes();
            std::vector<std::vector<double>> get_matriz_c();
            std::vector<double> get_vetor_d_deslocamentos();

            void set_vetor_v(std::vector<double> v);
            void set_vetor_d_deslocamentos(std::vector<double> vetor_d_deslocamentos);
            void set_matriz_c(std::vector<std::vector<double>> c);
    };
}

#endif