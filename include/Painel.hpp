#ifndef METODOS_NUMERICOS1_INCLUDE_PAINEL_HPP_
#define METODOS_NUMERICOS1_INCLUDE_PAINEL_HPP_

#include <vector>
#include <utility>
#include <string>

#include "Gauss.hpp"

using namespace metodos_numericos1::metodos;

namespace metodos_numericos1::outputs {

    // Implementação de um painel interativo (terminal) em modo texto para interação
    // com usuário.
    class Painel {
        public:
            Painel();
            const char *texto_menu_principal =
                "---------------------------------------------------------------------\n"
                "|                    Tela inicial MN-Analyzer v3                    |\n"
                "---------------------------------------------------------------------\n"
                "| Escolha uma opção:                                                |\n"
                "| 1 -> Cadastrar um sistema linear e método para análise.           |\n"
                "| 2 -> Remover um sistema linear já cadastrado.                     |\n"
                "| 3 -> Resetar sistemas lineares cadastrados.                       |\n"
                "| 4 -> Mostrar análise de um sistema linear.                        |\n"
                "| 5 -> Mostrar análise de todos os sistemas lineares cadastrados.   |\n"
                "| 0 -> Sair.                                                        |\n"
                "---------------------------------------------------------------------\n";
            const char *texto_cadastrar_sistema_linear_metodo_analise =
                "\nVocê escolheu 1 -> Cadastrar um sistema linear e método para análise.\n\n";
            
            const char *texto_inserir_parametro_a = "\n Insira o parâmetro 'a': ";
            const char *texto_inserir_ordem_matriz = "\n Insira a ordem da matriz 'C': ";
            const char *texto_inserir_linha_matriz = "\n Insira, separados por espaços, os valores da linha {0} da matriz 'C': ";
            const char *texto_inserir_vetor_v = "\n Insira, separado por espaços, os elementos do vetor 'v': ";
            
            const char *texto_escolher_metodo =
                "\n"
                "----------------------------------------------------\n"
                "|        Qual dos métodos deseja cadastrar?        |\n"
                "----------------------------------------------------\n"
                "| 1 -> Gauss                                       |\n"
                "| 2 -> Gauss-Jordan                                |\n"
                "| 3 -> Cramer                                      |\n"
                "----------------------------------------------------\n\n"
                "R: ";

            const char *texto_escolheu_gauss =
                "Você escolheu 1 -> Gauss Normal.\n";

            const char *texto_escolheu_gauss_jordan =
                "Você escolheu 2 -> Gauss-Jordan.\n";

            const char *texto_escolheu_cramer =
                "Você escolheu 3 -> Cramer.\n";

            const char *texto_metodo_cadastrado =
                "Método cadastrado";

            const char *texto_cadastrar_outro_metodo =
                "----------------------------------------------------\n"
                "|  Deseja cadastrar esta matriz com outro método?  |\n"
                "----------------------------------------------------\n"
                "| 1 -> Sim                                         |\n"
                "| 2 -> Não                                         |\n"
                "---------------------------------------------------\n\n"
                "R: ";


            const char *texto_remover_sistema_cadastrado =
                "Você escolheu 2 -> Remover um sistema já cadastrado.\n";

            const char *texto_nenhum_sistema_para_remover =
                "Ainda não existe nenhum sistema cadastrado. Portanto, não é possível remover.";

            const char *texto_inserir_indice_remover = 
                "\nInsira o ID de qual sistema deseja remover ou 0 para voltar: ";

            const char *texto_sistema_removido = 
                "Sistema removido com sucesso.";

            const char *texto_resetar_sistemas_cadastrados =
                "Você escolheu 3 -> Resetar sistemas cadastrados.\n";

            const char *texto_opcao_invalida = 
                "Opção digitada invalida.";

            const char *texto_sistemas_resetados = 
                "Pronto, todas os sistemas foram removidos.";

            const char *texto_analise_um_sistema =
                "Você escolheu 4 -> Mostrar análise de um sistema linear.\n";

            const char *texto_sem_sistemas_analisar = 
                "Ainda não foi cadastrada nenhum sistema. Cadastre uma sistema para prosseguir.";

            const char *texto_mostrar_sistemas_cadastrados =
                "Estes são os sistemas cadastrados:\n";

            const char *texto_inserir_indice_analisar =
                "\nInsira o ID de qual sistema deseja analisar ou 0 para voltar: ";

            const char *texto_analisar_todos_sistemas = "Você escolheu 5 -> Mostrar análise de todos os sistemas lineares cadastrados.\n";

            const char *texto_inserir_precisao = "\nInsira a quantidade de casas decimais (precisão) com que deseja exibir o quadro: ";

            const char *texto_entrada_invalida = 
                "Entrada inválida. Tente novamente";

            void init();

            void output(const char *texto_principal) const;
            void output(const char *texto_principal, int numero) const;

            void formata_avisos(const char *texto) const;

            void imprimir_quadro_comparativo(std::vector<Metodo*> sistemas, int precisao = 3) const;

            void imprimir_sistemas_cadastrados(std::vector<Metodo*> sistemas, int precisao = 3);

            void imprimir_matriz(std::vector<std::vector<double>> matriz);
            void imprimir_vetor_coluna(std::vector<double> vetor);
            void imprimir_vetor_linha(std::vector<double> vetor);

            void limpar_painel() const;
    };
};

#endif 
