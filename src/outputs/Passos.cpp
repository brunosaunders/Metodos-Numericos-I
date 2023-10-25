#include <iostream>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <typeinfo>

#include "Passos.hpp"
#include "NewtonRaphson.hpp"
#include "NewtonRaphsonFL.hpp"
#include "Derivacao.hpp"
#include "NewtonRaphsonComDerivadaNumerica.hpp"
#include "Pendulo.hpp"
#include "Tabela.hpp"


namespace metodos_numericos1 {
    namespace outputs {
        void Passos::exibir_passos_todas_raizes(NewtonRaphson* metodo) {
            std::cout << std::endl;
            
            int precisao_fx_xk = std::log10(metodo->get_erro()) * (-1);

            metodo->calcula_raizes();
            std::cout << "Método: " << metodo->get_classe(precisao_fx_xk) << std::endl;
            
            for(int i=0; i < metodo->get_iteracoes_de_x_todas_raizes().size(); i++) {
                Passos::exibir_passos_raiz(metodo, i);
            }
        }


        void Passos::exibir_passos_raiz(NewtonRaphson* metodo, int index) {
            // std::cout << std::endl;


            Polinomio p = metodo->get_funcao();
            int max_iteracoes = metodo->get_iteracoes_de_x(index).size();

            int precisao_fx_xk = std::log10(metodo->get_erro()) * (-1);

            // Definir largura de cada coluna dependendo da precisão dos valores
            int largura_numeros = precisao_fx_xk + 5;
            int padding = 3;
            int largura_total_coluna = largura_numeros + 2*padding;

            // Cálculo do tamanho da coluna de k 
            std::string maior_k = std::to_string(max_iteracoes);
            int largura_k = maior_k.size() + 2*padding;

            int largura_total_tabela = largura_k + largura_total_coluna * 6 + 1;


            // Imprimir cabeçalho
            std::cout << index+1 << "a raiz\n";
            std::cout << "Intervalo: TODO\n";

            
            metodos_numericos1::outputs::Tabela::exibir_tampa_tabela(largura_total_tabela);

            std::cout << "|";
            metodos_numericos1::outputs::Tabela::formata_cabecalho("k", largura_k);
            metodos_numericos1::outputs::Tabela::formata_cabecalho("xk", largura_total_coluna);
            metodos_numericos1::outputs::Tabela::formata_cabecalho("xk-1", largura_total_coluna);
            metodos_numericos1::outputs::Tabela::formata_cabecalho("f(xk)", largura_total_coluna);
            metodos_numericos1::outputs::Tabela::formata_cabecalho("f'(xk)", largura_total_coluna);
            metodos_numericos1::outputs::Tabela::formata_cabecalho("e1", largura_total_coluna);
            metodos_numericos1::outputs::Tabela::formata_cabecalho("e2", largura_total_coluna);
            std::cout << std::endl;

            double xk_1 = metodo->get_iteracoes_de_x(index)[0];
            Polinomio f_derivada = metodo->get_funcao().get_funcao_derivada();
            Derivacao* derivacao = new Derivacao();

            for (int k = 1; k < metodo->get_iteracoes_de_x(index).size(); k++) {
                double xk = metodo->get_iteracoes_de_x(index)[k];
                double fxk = p.get_valor_funcao(xk);
                double e1 = std::abs(xk - xk_1);
                double e2 = std::abs(fxk);
                double f_derivada_xk;

                // Dependendo do método, o cálculo da derivada é diferente
                if (typeid(*metodo) == typeid(NewtonRaphsonComDerivadaNumerica)) {
                    f_derivada_xk = derivacao->derivar(metodo->get_funcao(), xk);
                } else {
                    f_derivada_xk = f_derivada.get_valor_funcao(xk);
                }

                // Configurar alinhamento
                // std::cout << std::scientific << std::setprecision(precisao_fx_xk) << std::setw(3) << std::to_string(k+1) << "|";
                std::cout << "|";
                metodos_numericos1::outputs::Tabela::formata_numero_normal(k, largura_k, padding);
                metodos_numericos1::outputs::Tabela::formata_numero_cientifico(xk, precisao_fx_xk, largura_total_coluna, padding);
                metodos_numericos1::outputs::Tabela::formata_numero_cientifico(xk_1, precisao_fx_xk, largura_total_coluna, padding);
                metodos_numericos1::outputs::Tabela::formata_numero_cientifico(fxk, precisao_fx_xk, largura_total_coluna, padding);
                metodos_numericos1::outputs::Tabela::formata_numero_cientifico(f_derivada_xk, precisao_fx_xk, largura_total_coluna, padding);
                metodos_numericos1::outputs::Tabela::formata_numero_cientifico(e1, precisao_fx_xk, largura_total_coluna, padding);
                metodos_numericos1::outputs::Tabela::formata_numero_cientifico(e2, precisao_fx_xk, largura_total_coluna, padding);
                std::cout << std::endl;

                xk_1 = xk;
            }

            metodos_numericos1::outputs::Tabela::exibir_tampa_tabela(largura_total_tabela);
        }
    }
}