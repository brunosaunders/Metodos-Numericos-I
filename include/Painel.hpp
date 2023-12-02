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
                "--------------------------------------------------------------------\n"
                "|                     Tela inicial MN-Analyzer v3                  |\n"
                "--------------------------------------------------------------------\n"
                "|Escolha uma opção:                                                |\n"
                "|1 -> Cadastrar um sistema linear e método para análise.           |\n"
                "|2 -> Remover uma sistema linear já cadastrado.                    |\n"
                "|3 -> Resetar sistemas lineares cadastrados.                       |\n"
                "|4 -> Mostrar análise de um sistema linear.                        |\n"
                "|5 -> Mostrar análise de todos sistemas lineares cadastrados.      |\n"
                "|0 -> Sair.                                                        |\n"
                "---------------------------------------------------------\n";
            const char *texto_cadastrar_sistema_linear_metodo_analise =
                "\nVocê escolheu 1 -> Cadastrar um sistema linear e método para análise.\n\n";
            
            const char *texto_inserir_parametro_a = "\n Insira o parâmetro 'a': ";
            const char *texto_inserir_numero_linhas = "\n Insira o número de linhas do sistema linear: ";
            const char *texto_inserir_numero_colunas = "\n Insira o número de colunas do sistema linear: ";
            const char *texto_inserir_matriz = "\n Insira a matriz para análise:\n";
            const char *texto_inserir_vetor_v = "\n Insira o vetor 'v' de distâncias";
            
            const char *texto_escolher_metodo =
                "\n"
                "---------------------------------------------------\n"
                "|Agora, escolha o método desejado:                |\n"
                "---------------------------------------------------\n"
                "|1 -> Gauss Normal.                               |\n"
                "|2 -> Gauss-Jordan.                               |\n"
                "---------------------------------------------------\n";

            const char *texto_newton_raphson_normal =
                "Você escolheu 1 -> Gauss Normal.\n";

            const char *texto_newton_raphson_fl =
                "Você escolheu 2 -> Gauss-Jordan.\n";

            const char *texto_metodo_cadastrado =
                "Método cadastrado: ";

            const char *texto_remover_sistema_cadastrado =
                "Você escolheu 2 -> Remover um sistema já cadastrado.\n";

            const char *texto_nenhum_sistema_para_remover =
                "Ainda não existe nenhum sistema cadastrado. Portanto, não é possível remover.";

            const char *texto_inserir_indice_remover = 
                "\nInsira o índice de qual sistema deseja remover:\n";

            const char *texto_sistema_removido = 
                "Sistema removido com sucesso.";

            const char *texto_resetar_sistemas_cadastrados =
                "Você escolheu 3 -> Resetar sistemas cadastrados.\n";

            const char *texto_opcao_invalida = 
                "Opção digitada invalida.";

            const char *texto_sistemas_resetados = 
                "Pronto, todas os sistemas foram removidos.";

            const char *texto_analise_passo_passo_sistema =
                "Você escolheu 4 -> Mostrar análise de um sistema linear.\n";

            const char *texto_sem_sistemas_analisar = 
                "Ainda não foi cadastrada nenhum sistema. Cadastre uma sistema para prosseguir.";

            const char *texto_mostrar_sistemas_cadastrados =
                "Estes são os sistemas cadastrados:\n";

            const char *texto_inserir_indice_analisar =
                "\nInsira o índice de qual sistema deseja analisar:\n";

            const char *texto_analisar_todos_sistemas = "\nVocê escolheu 5 -> Mostrar análise de todos sistemas lineares cadastrados.\n";

            const char *texto_entrada_invalida = 
                "Entrada inválida. Teste novamente";

            void init(std::vector<Metodo*> metodos);

            void output(const char *texto_principal) const;

            void formata_avisos(const char *texto) const;

            void imprimir_quadro_comparativo(std::vector<Metodo*> metodos, int precisao) const;

            void imprimir_sistema_cadastrado(Metodo* metodo);

            void imprimir_matriz(std::vector<std::vector<double>> matriz);
            void imprimir_vetor_coluna(std::vector<double> vetor);
            void imprimir_vetor_linha(std::vector<double> vetor);
    };
};

#endif 
