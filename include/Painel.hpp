#ifndef METODOS_NUMERICOS1_INCLUDE_PAINEL_HPP_
#define METODOS_NUMERICOS1_INCLUDE_PAINEL_HPP_

#include "Polinomio.hpp"
#include "NewtonRaphson.hpp"
#include <vector>
#include <utility>
#include <string>

using namespace metodos_numericos1::metodos;

namespace metodos_numericos1::outputs {
    // Implementação de um painel iterativo (terminal) em modo texto para iteração
    // com usuário.
    class Painel {
        public:
            Painel();
            const char *texto_menu_principal =
                "---------------------------------------------------------\n"
                "|              Tela inicial MN-Analyzer v3              |\n"
                "---------------------------------------------------------\n"
                "|Escolha uma opção:                                     |\n"
                "|1 -> Cadastrar uma função e método para análise        |\n"
                "|2 -> Remover uma função já cadastrada                  |\n"
                "|3 -> Resetar funçôes cadastradas.                      |\n"
                "|4 -> Mostrar análise passo a passo de um função.       |\n"
                "|5 -> Gerar quadro comparativo das funções cadastradas. |\n"
                "|6 -> Mostrar isolamento de uma função.                 |\n"
                "|0 -> Sair.                                             |\n"
                "---------------------------------------------------------\n";
            const char *texto_cadastrar_funcao_metodo_analise =
                "\nVocê escolheu 1 -> Cadastrar uma função e método para análise.\n\n"
                "Insira, separados por espaços, a3 a2 precisão max_iterações: ";
            const char *texto_escolher_metodo =
                "\n"
                "---------------------------------------------------\n"
                "|Agora, escolha o método desejado:                |\n"
                "---------------------------------------------------\n"
                "|1 -> Newton Raphson (NR).                        |\n"
                "|2 -> Newton Raphson com FL (NR-FL).              |\n"
                "|3 -> Newton Raphson com Derivada Numerica (NR-D).|\n"
                "---------------------------------------------------\n";
            const char *texto_newton_raphson_normal =
                "Você escolheu 1 -> Newton Raphson (NR).\n";
            const char *texto_newton_raphson_fl =
                "Você escolheu 2 -> Newton Raphson com FL (NR-FL).\n";
            const char *texto_cadastrar_lambda = 
                "Informe o lambda: ";
            const char *texto_newton_raphson_derivada_numerica =
                "Você escolheu 3 -> Newton Raphson com Derivada Numerica (NR-D).\n";
            const char *texto_metodo_cadastrado =
                "Método cadastrado: ";
            const char *texto_remover_funcao_cadastrada =
                "Você escolheu 2 -> Remover uma função já cadastrada.\n";
            const char *texto_nenhuma_funcao_remover =
                "Ainda não foram cadastradas funções. Portanto, não é possível remover nenhuma. Tente inserir uma função primeiramente";
            const char *texto_inserir_indice_remover = 
                "\nInsira o índice de qual função deseja remover:\n";
            const char *texto_funcao_removida = 
                "Funcao removida com sucesso";
            const char *texto_resetar_funcoes_cadastradas =
                "Você escolheu 3 -> Resetar funções cadastradas.\n";
            const char *texto_opcao_invalida = 
                "Opção digitada invalida";
            const char *texto_sem_funcoes_resetar =
                "Não existem funções cadastradas. Portanto, não há o que remover";
            const char *texto_funcoes_resetadas = 
                "Pronto, todas as funções foram removidas";
            const char *texto_analise_passo_passo_funcao =
                "Você escolheu 4 -> Mostrar análise passo a passo de um função.\n";
            const char *texto_sem_funcoes_analisar = 
                "Ainda não foi cadastrada nenhuma função. Cadastre uma função para prosseguir";
            const char *texto_mostrar_funcoes_cadastradas =
                "Estas são as funções cadastradas:\n";
            const char *texto_inserir_indice_analisar =
                "\nInsira o índice de qual função deseja analisar:\n";
            const char *texto_mostrar_quadro_comparativo_func_cadastradas =
                "Você escolheu 5 -> Gerar quadro comparativo das funções cadastradas.\n";
            const char *texto_mostrar_isolamento_funcao =
                "Você escolheu 6 -> Mostrar isolamento de uma função.\n";
            const char *texto_entrada_invalida = 
                "Entrada inválida. Teste novamente\n";

            void init(std::vector<NewtonRaphson*> funcoes);

            void print_funcoes_cadastradas(std::vector<NewtonRaphson*> metodos);

            // Inicialização do painel, a partir dela será feita a iteração com o usuário.
            //void init();
            void output() const;

            void output(const char *texto_principal) const;
    };
};

#endif 
