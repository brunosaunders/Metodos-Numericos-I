#include <iostream>
#include <iomanip>
#include "Vizualizador.hpp"
#include <string>
#include <cmath>
#include "NewtonRaphson.hpp"
#include "Pendulo.hpp"
#include "NewtonRaphsonFL.hpp"
#include "NewtonRaphsonComDerivadaNumerica.hpp"

namespace  vizualizador { 
    const int NUM_BLOCOS = 9; 
    const std::string METODOS_ALIAS[3] {"original","FL","derivada"};
    enum Num_Metodo {ORIGINAL,FL,DERIVADA};
    const int TAM_TAB = 8;
    const std::string tab(TAM_TAB,' ');

    inline std::string EntradasLinhaQuadroComparativo::get_nome_metodo() {return METODOS_ALIAS[metodo];}

    /**
    * Calcula tamanho de blocos "padrao": cada bloco é: TAB<palavra_do_bloco>TAB, com exceção do primeiro bloco.
    * */
    void calcula_tamanho_blocos(int *tamanhos_blocos) { 
        tamanhos_blocos[0] =8;
        tamanhos_blocos[1] = TAM_TAB + 6 + TAM_TAB ; 
        tamanhos_blocos[2] = 2*TAM_TAB + 2 ;
        tamanhos_blocos[3] = 2*TAM_TAB + 2; 
        tamanhos_blocos[4] = 2*TAM_TAB + 6;
        tamanhos_blocos[5] = 2*TAM_TAB + 9; 
        tamanhos_blocos[6] = 2*TAM_TAB + 2;
        tamanhos_blocos[7] = 2*TAM_TAB + 2; 
        tamanhos_blocos[8] = 2*TAM_TAB + 2;
    }
    
    void forma_saidas(std::vector<SaidasLinhaQuadroComparativo> *saidas_linhas, std::vector<EntradasLinhaQuadroComparativo> *linhas,int max_iteracoes) { 
        EntradasLinhaQuadroComparativo* entrada; 
        for (int i = 0; i < linhas->size(); i++ ){ 
            entrada = &(linhas->at(i)); 
        int num_metodo = entrada->metodo; 
        Pendulo funcao_pendulo(entrada->a3,entrada->a2);
        NewtonRaphson *metodo;
        if (num_metodo == ORIGINAL) 
            metodo = &NewtonRaphson(max_iteracoes,entrada->epsilon,funcao_pendulo); 
        else if(num_metodo == FL) 
            metodo = &NewtonRaphsonFL(max_iteracoes,entrada->epsilon,funcao_pendulo,entrada->lambda); 
        else metodo = &NewtonRaphsonComDerivadaNumerica(max_iteracoes,entrada->epsilon,funcao_pendulo);

        int num_iteracoes = metodo->get_num_passos(); 
        double x_k = (metodo->get_iteracoes_de_x())[num_iteracoes]; 
        double e1 = std::abs(x_k - metodo->get_iteracoes_de_x()[(num_iteracoes -1)]);
        double e2 = std::abs(funcao_pendulo.get_valor_funcao(x_k));  
        SaidasLinhaQuadroComparativo linha{entrada,x_k,e1,e2,num_iteracoes};
        saidas_linhas->push_back(linha); 
        } 
    }

    void get_max_espaco(int num_saida,int *tamanho_blocos,SaidasLinhaQuadroComparativo *saida_linha, int precisao) { 
        tamanho_blocos[0] = std::max(static_cast<unsigned int>(tamanho_blocos[0]), static_cast<unsigned int>(std::to_string(num_saida).size())); 
        tamanho_blocos[1] = std::max(static_cast<unsigned int>((saida_linha->entrada->get_nome_metodo()).size()),static_cast<unsigned int>(tamanho_blocos[1]));
        tamanho_blocos[2] = std::max(static_cast<unsigned int>(std::to_string(std::trunc(saida_linha->entrada->a3)).size() -7 + precisao),static_cast<unsigned int>(tamanho_blocos[2])); 
        tamanho_blocos[3] = std::max(static_cast<unsigned int>(std::to_string(std::trunc(saida_linha->entrada->a2)).size() -7 + precisao),static_cast<unsigned int>(tamanho_blocos[3])); 
        tamanho_blocos[4] = std::max(static_cast<unsigned int>(std::to_string(std::trunc(saida_linha->entrada->lambda)).size() -7 + precisao),static_cast<unsigned int>(tamanho_blocos[4])); 
        tamanho_blocos[5] = std::max(static_cast< unsigned int>(std::to_string(saida_linha->iteracoes).size()),static_cast< unsigned int>(tamanho_blocos[5])); 
        tamanho_blocos[6] = std::max(static_cast<unsigned int>(std::to_string(std::trunc(saida_linha->x_k)).size() -7 + precisao),static_cast<unsigned int>(tamanho_blocos[6])); 
        tamanho_blocos[7] = std::max(static_cast<unsigned int>(std::to_string(std::trunc(saida_linha->e1)).size() -7 + precisao),static_cast<unsigned int>(tamanho_blocos[7])); 
        tamanho_blocos[8] = std::max(static_cast<unsigned int>(std::to_string(std::trunc(saida_linha->e2)).size() -7 + precisao),static_cast<unsigned int>(tamanho_blocos[8]));
    }

    void max_espaco_linha(std::vector<SaidasLinhaQuadroComparativo> *saidas_linhas,int *tamanho_blocos ,int precisao) {
        for (int i = 0; i< saidas_linhas->size(); i++) { 
            get_max_espaco(i+1, tamanho_blocos,&(saidas_linhas->at(i)), precisao);
        }
    }

    //tamanho_blocos - > array de tamanho 9
    void print_header(int *tamanhos_blocos){
        std::string palavras[NUM_BLOCOS] {"Entrada", "Método", "a3", "a2", "lambda", "iterações", "xk", "e1", "e2"};
        int espaco_palavras[NUM_BLOCOS]; 
        int espaco_palavras_metade1[NUM_BLOCOS]; 
        int espaco_palavras_metade2[NUM_BLOCOS]; 
        for (int i = 0; i < NUM_BLOCOS; i++){ 
            espaco_palavras[i] = tamanhos_blocos[i] - palavras[i].size()+1; 
            espaco_palavras_metade1[i] = static_cast<unsigned int>(espaco_palavras[i]/2); 
            espaco_palavras_metade2[i] = espaco_palavras[i] - espaco_palavras_metade1[i]; 
        }
        for (int i = 0; i < NUM_BLOCOS; i++){ 
            std::cout << std::string(espaco_palavras_metade1[i],' ') << palavras[i] << std::string(espaco_palavras_metade2[i],' ') << "|";
        }
        std::cout << "\n";
    }

    void print_linha_quadro_comparativo(SaidasLinhaQuadroComparativo *linha, int *tamanho_blocos, int precisao) {
        std::cout << std::fixed << std::setprecision(precisao);

        // Bloco 1: nome do metodo
        int tamanho_da_sobra1 = tamanho_blocos[1] - (linha->entrada->get_nome_metodo()).size();
        int tamanho_espacamento1 = static_cast<int>((tamanho_da_sobra1) / 2);
        std::string espacamento1 = std::string(tamanho_espacamento1, ' ');
        std::string espacamento1_sobra = std::string(tamanho_da_sobra1 - tamanho_espacamento1, ' ');
        std::cout << espacamento1 << linha->entrada->get_nome_metodo() << espacamento1_sobra << "|";

        // Bloco 2: a3
        int tamanho_da_sobra2 = tamanho_blocos[2] - std::to_string(std::trunc(linha->entrada->a3)).size() + 7 - precisao  ;
        int tamanho_espacamento2 = static_cast<unsigned int>(tamanho_da_sobra2 / 2);
        std::string espacamento2 = std::string(tamanho_espacamento2, ' ');
        std::string espacamento2_sobra = std::string(tamanho_da_sobra2 - tamanho_espacamento2, ' ');
        std::cout << espacamento2 <<linha->entrada->a3 << espacamento2_sobra << "|";

        // Bloco 3: a2
        int tamanho_da_sobra3 = tamanho_blocos[3] - std::to_string(std::trunc(linha->entrada->a2)).size() - precisao + 7  ;
        int tamanho_espacamento3 = static_cast<unsigned int>(tamanho_da_sobra3 / 2);
        std::string espacamento3 = std::string(tamanho_espacamento3, ' ');
        std::string espacamento3_sobra = std::string(tamanho_da_sobra3 - tamanho_espacamento3, ' ');
        std::cout << espacamento3 << linha->entrada->a2 << espacamento3_sobra << "|";

        // Bloco 4: lambda
        int tamanho_da_sobra4 = tamanho_blocos[4] - std::to_string(std::trunc(linha->entrada->lambda)).size() - precisao + 7 ;
        int tamanho_espacamento4 = static_cast<unsigned int>(tamanho_da_sobra4 / 2);
        std::string espacamento4 = std::string(tamanho_espacamento4, ' ');
        std::string espacamento4_sobra = std::string(tamanho_da_sobra4 - tamanho_espacamento4, ' ');
        std::cout << espacamento4 << linha->entrada->lambda << espacamento4_sobra << "|";

        // Bloco 5: iteracoes
        int tamanho_da_sobra5 = tamanho_blocos[5] - std::to_string(linha->iteracoes).size() ;
        int tamanho_espacamento5 = static_cast<unsigned int>(tamanho_da_sobra5 / 2);
        std::string espacamento5 = std::string(tamanho_espacamento5, ' ');
        std::string espacamento5_sobra = std::string(tamanho_da_sobra5 - tamanho_espacamento5 -1, ' ');
        std::cout << espacamento5 << linha->iteracoes << espacamento5_sobra << "|";

        // Bloco 6: xk
        int tamanho_da_sobra6 = tamanho_blocos[6] - std::to_string(std::trunc(linha->x_k)).size() - precisao + 7 ;
        int tamanho_espacamento6 = static_cast<unsigned int>(tamanho_da_sobra6 / 2);
        std::string espacamento6 = std::string(tamanho_espacamento6, ' ');
        std::string espacamento6_sobra = std::string(tamanho_da_sobra6 - tamanho_espacamento6, ' ');
        std::cout << espacamento6 <<linha->x_k << espacamento6_sobra << "|";

        // Bloco 7: e1
        int tamanho_da_sobra7 = tamanho_blocos[7] - std::to_string(std::trunc(linha->e1)).size() - precisao + 7 ;
        int tamanho_espacamento7 = static_cast<unsigned int>(tamanho_da_sobra7 / 2);
        std::string espacamento7 = std::string(tamanho_espacamento7, ' ');
        std::string espacamento7_sobra = std::string(tamanho_da_sobra7 - tamanho_espacamento7, ' ');
        std::cout << espacamento7 << std::floor(linha->e1) << espacamento7_sobra << "|";

        // Bloco 8: e2
        int tamanho_da_sobra8 = tamanho_blocos[8] - std::to_string(std::trunc(linha->e2)).size() - precisao + 7 ;
        int tamanho_espacamento8 = static_cast<unsigned int>(tamanho_da_sobra8 / 2);
        std::string espacamento8 = std::string(tamanho_espacamento8, ' ');
        std::string espacamento8_sobra = std::string(tamanho_da_sobra8 - tamanho_espacamento8, ' ');
        std::cout << espacamento8 << linha->e2<< espacamento8_sobra << "|";

        std::cout << "\n";
        std::cout.unsetf(std::ios::fixed);
    }

    void print_quadro_comparativo(std::vector<EntradasLinhaQuadroComparativo> linhas,int precisao,int max_iteracoes){ 
        int tamanho_bloco[9]; 
        calcula_tamanho_blocos(tamanho_bloco);
        std::vector<SaidasLinhaQuadroComparativo> saidas_linhas; 
        forma_saidas(&saidas_linhas, &linhas, max_iteracoes);
        max_espaco_linha(&saidas_linhas,tamanho_bloco,precisao); 

        print_header(tamanho_bloco);        
        for (int i = 0; i < linhas.size(); i++) {
            int tamanho_espaco_metade1 = static_cast<int>((tamanho_bloco[0] - std::to_string(i+1).size())/2);
            std::cout<< std::string(tamanho_espaco_metade1,' ') << std::to_string(i+1) << std::string(tamanho_bloco[0] - std::to_string(i+1).size()- tamanho_espaco_metade1 + 1, ' ') << "|";
            print_linha_quadro_comparativo(&saidas_linhas[i], tamanho_bloco, precisao); 
        }
    } 

}