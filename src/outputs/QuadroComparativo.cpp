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

            int largura_padrao = 12;

            bool negativos[5] = {false, false, false, false, false};

            for (auto& metodo : metodos) {
                Polinomio funcao = metodo->get_funcao();

                metodo->calcula_raizes(); 
                std::vector<double> raizes = metodo->get_raizes();

                int precisao = std::log10(metodo->get_erro()) * (-1);
                int iteracoes =  metodo->get_max_iteracoes();
                if (precisao > precisao_max) {
                    precisao_max = precisao;
                }

                if (iteracoes > iter_max) iter_max = iteracoes;

                if (funcao[0] < 0) negativos[0] = true;
                if (funcao[2] < 0) negativos[1] = true;

                for (int i=0; i < raizes.size(); i++) {
                    if (raizes[i] < 0) negativos[2+i] = true;
                }
            }

            if (precisao_max > 5) precisao_max = 5;

            std::vector<int> larguras;

            // Cálculo do tamanho da coluna de k 
            std::string maior_k = std::to_string(k_max);
            int largura_k = maior_k.size() + 5;
            larguras.push_back(largura_k);

            // Método
            int largura_metodo = 6;
            

            // a3
            int largura_a3 = 6;
            if (negativos[0]) largura_a3++;
            

            // a2
            int largura_a2 = 6;
            if (negativos[1]) largura_a2++;
            

            // lambda
            int largura_lambda = 6;
            

            // iter_total min: 10
            int largura_iter_media = 13;
            int largura_iter_total = largura_iter_media;
            
            

            // quebra?
            int largura_quebra = 8;
            

            // r1
            int largura_r1 = precisao_max + 8;
            if (negativos[2]) largura_r1++;
            

            // r2
            int largura_r2 = precisao_max + 8;
            if (negativos[3]) largura_r2++;
            

            // r3
            int largura_r3 = precisao_max + 8;
            if (negativos[4]) largura_r3++;
            


            int largura_total_tabela = 11 * largura_padrao + largura_k;

            std::string quadro = "Quadro Comparativo";

            std::cout << std::left << quadro << std::endl;
            metodos_numericos1::outputs::Tabela::exibir_tampa_tabela(largura_total_tabela);

            std::cout << "|";
            metodos_numericos1::outputs::Tabela::formata_palavra("k", largura_k);
            metodos_numericos1::outputs::Tabela::formata_palavra("Método", largura_padrao);
            metodos_numericos1::outputs::Tabela::formata_palavra("a3", largura_padrao);
            metodos_numericos1::outputs::Tabela::formata_palavra("a2", largura_padrao);
            metodos_numericos1::outputs::Tabela::formata_palavra("lambda", largura_padrao);
            metodos_numericos1::outputs::Tabela::formata_palavra("r1", largura_padrao);
            metodos_numericos1::outputs::Tabela::formata_palavra("r2", largura_padrao);
            metodos_numericos1::outputs::Tabela::formata_palavra("r3", largura_padrao);
            metodos_numericos1::outputs::Tabela::formata_palavra("iter-total", largura_padrao);
            metodos_numericos1::outputs::Tabela::formata_palavra("iter-média", largura_padrao);
            metodos_numericos1::outputs::Tabela::formata_palavra("quebra?", largura_padrao);
            std::cout << std::endl;
            metodos_numericos1::outputs::Tabela::exibir_tampa_tabela(largura_total_tabela);

            int k = 1;
            for (auto& metodo : metodos) {
                Polinomio p = metodo->get_funcao();
                std::vector<double> raizes = metodo->get_raizes();
                
                std::cout << "|";
                metodos_numericos1::outputs::Tabela::formata_numero(k, largura_k);
                metodos_numericos1::outputs::Tabela::formata_palavra(metodo->get_nome_abreviado(), largura_padrao);
                metodos_numericos1::outputs::Tabela::formata_numero(p[0], largura_padrao);
                metodos_numericos1::outputs::Tabela::formata_numero(p[2]/9, largura_padrao);
                metodos_numericos1::outputs::Tabela::formata_numero(metodo->get_lambda(), largura_padrao);

                for (int i=0; i < 3; i++) {
                    if (i < raizes.size()) {
                        metodos_numericos1::outputs::Tabela::formata_numero_cientifico(raizes[i], precisao_max, largura_padrao);
                    } else {
                        metodos_numericos1::outputs::Tabela::formata_palavra("null", largura_padrao);
                    }
                } 

                metodos_numericos1::outputs::Tabela::formata_numero(metodo->get_total_iteracoes(), largura_padrao);
                metodos_numericos1::outputs::Tabela::formata_numero(metodo->get_media_iteracoes(), largura_padrao);
                metodos_numericos1::outputs::Tabela::formata_palavra(metodo->get_quebra(), largura_padrao);
                std::cout << std::endl;
                k++;
            }
            metodos_numericos1::outputs::Tabela::exibir_tampa_tabela(largura_total_tabela);

        }
}