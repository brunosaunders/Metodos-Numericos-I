#ifndef METODOS_NUMERICOS1_INCLUDE_METODO_HPP_
#define METODOS_NUMERICOS1_INCLUDE_METODO_HPP_

#include <vector>
#include <string>

namespace metodos_numericos1::metodos {

    class Metodo {

        protected:
            double a;
            double amplitude_limite;
            std::vector<double> vetor_v;
            std::vector<std::vector<double>> matriz_c;
            std::vector<double> vetor_d_deslocamentos;

            /* Não faremos operações com essas variáveis. Serão utilizadas para imprimir o estado inicial do sistema linear. */
            std::vector<double> vetor_v_inicial;
            std::vector<std::vector<double>> matriz_c_inicial;

        public:
            Metodo(std::vector<std::vector<double>> matriz_c,
                std::vector<double> vetor_v, 
                double a, double amp_limite=3.0) : a(a), vetor_v(vetor_v), matriz_c(matriz_c), amplitude_limite(amp_limite), matriz_c_inicial(matriz_c), vetor_v_inicial(vetor_v) {}

            virtual void resolve_sistema_linear() = 0;

            double get_a();
            std::vector<std::vector<double>> get_matriz_c();
            std::vector<double> get_vetor_v();
            std::vector<double> get_vetor_d_deslocamentos();
            std::vector<double> get_vetor_amplitudes();
            std::string get_balanco_quebra();
            virtual std::string get_nome_abreviado() = 0;

            std::vector<double> get_vetor_v_inicial();
            std::vector<std::vector<double>> get_matriz_c_inicial();

            void set_vetor_v(std::vector<double> v);
            void set_vetor_d_deslocamentos(std::vector<double> vetor_d_deslocamentos);
            void set_matriz_c(std::vector<std::vector<double>> c);

    };

}

#endif