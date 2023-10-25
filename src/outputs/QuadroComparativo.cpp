#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>


#include "QuadroComparativo.hpp"
#include "Tabela.hpp"
#include "NewtonRaphson.hpp"


namespace metodos_numericos1::outputs {
        void QuadroComparativo::exibir_quadro(std::vector<NewtonRaphson*> metodos) {
            
            int precisao_max = -1000;
            int k_max = metodos.size();
            int iter_max = -1000;

            for (auto& metodo : metodos) {
                metodo->calcula_raizes(); 
                int precisao = std::log10(metodo->get_erro()) * (-1);
                int iteracoes =  metodo->get_max_iteracoes();
                if (precisao > precisao_max) {
                    precisao_max = precisao;
                }

                if (iteracoes > iter_max) iter_max = iteracoes;
            }
            if (precisao_max > 5) precisao_max = 5;

            std::cout << precisao_max << std::endl;

            std::vector<int> larguras;

            int padding = 3;

            // Cálculo do tamanho da coluna de k 
            std::string maior_k = std::to_string(k_max);
            int largura_k = maior_k.size() + 2*padding;
            larguras.push_back(largura_k);

            // Método
            int largura_metodo = 5 + 2 * padding;
            larguras.push_back(largura_metodo);

            // a3, a2 e lambda
            int largura_a3 = 4 + 2 * padding;
            int largura_a2 = largura_a3;
            int largura_lambda = largura_a3;
            larguras.push_back(largura_a3);
            larguras.push_back(largura_a2);
            larguras.push_back(largura_lambda);

            // iter_total min: 10
            int largura_iter_min = 11 + 2 * padding;
            int largura_iter_total = (std::to_string(iter_max*3)).size() + 2 * padding;
            if (largura_iter_total < largura_iter_min) largura_iter_total = largura_iter_min;
            larguras.push_back(largura_iter_total);


            // iter_media min: 10
            int largura_iter = (std::to_string(iter_max)).size() + 2 * padding;
            if (largura_iter < largura_iter_min) largura_iter = largura_iter_min;
            larguras.push_back(largura_iter);

            // quebra?
            int largura_quebra = 7 + 2 * padding;
            larguras.push_back(largura_quebra);

            // r1, r2 e r3
            int largura_raizes = precisao_max + 5 + 2 * padding;
            larguras.push_back(largura_raizes * 3);

            int largura_total_tabela = 0;
            for (auto& item : larguras) {
                largura_total_tabela += item;
            }

            std::string quadro = "Quadro Comparativo";
            int padding_quadro = (largura_total_tabela ) / 2;

            metodos_numericos1::outputs::Tabela::exibir_tampa_tabela(largura_total_tabela -1);
            std::cout << std::setw(padding_quadro) << quadro << std::endl;
            metodos_numericos1::outputs::Tabela::exibir_tampa_tabela(largura_total_tabela -1);

            std::cout << "|";
            metodos_numericos1::outputs::Tabela::formata_cabecalho("k", largura_k);
            metodos_numericos1::outputs::Tabela::formata_cabecalho("Método", largura_metodo);
            metodos_numericos1::outputs::Tabela::formata_cabecalho("a3", largura_a3);
            metodos_numericos1::outputs::Tabela::formata_cabecalho("a2", largura_a2);
            metodos_numericos1::outputs::Tabela::formata_cabecalho("lambda", largura_lambda);
            metodos_numericos1::outputs::Tabela::formata_cabecalho("r1", largura_raizes);
            metodos_numericos1::outputs::Tabela::formata_cabecalho("r2", largura_raizes);
            metodos_numericos1::outputs::Tabela::formata_cabecalho("r3", largura_raizes);
            metodos_numericos1::outputs::Tabela::formata_cabecalho("iter-total", largura_iter_total);
            metodos_numericos1::outputs::Tabela::formata_cabecalho("iter-média", largura_iter);
            metodos_numericos1::outputs::Tabela::formata_cabecalho("quebra?", largura_quebra);
            std::cout << std::endl;


        }
}