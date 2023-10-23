#ifndef METODOS_NUMERICOS1_INCLUDE_PAINEL_HPP_
#define METODOS_NUMERICOS1_INCLUDE_PAINEL_HPP_

namespace metodos_numericos1::include {
    // Implementação de um painel iterativo (terminal) em modo texto para iteração
    // com usuário.
    class Painel {
        public:
            Painel();
            const char *texto_menu_principal =
                "Escolha uma opção: \n"
                "1 -> Cadastrar uma função e método para análise \n"
                "2 -> Remover uma função já cadastrada \n"
                "3 -> Resetar funções cadastradas.\n"
                "4 -> Mostrar analise passo a passo de um funcao.\n"
                "5 -> Gerar quadro comparativo das funcoes cadastradas.\n"
                "6 -> Mostrar isolamento de uma funcao.\n"
                "0 -> Sair.\n";
            const char *texto_cadastrar_funcao_metodo_analise =
                "Voce escolheu 1 -> Cadastrar uma funcao e metodo para analise.\n\n"
                "Insira os seguintes dados: a3, a2 e precisao\n";
            const char *texto_escolher_newton_raphson =
                "Agora, escolha o metodo desejado:\n"
                "1 -> Newton Raphson (NR).\n"
                "2 -> Newton Raphson com FL (NR-FL).\n"
                "3 -> Newton Raphson com Derivada Numerica (NR-D).\n";
            const char *texto_newton_raphson_normal =
                "Voce escolheu 1 -> Newton Raphson (NR).\n";
            const char *texto_newton_raphson_fl =
                "Voce escolheu 2 -> Newton Raphson com FL (NR-FL).\n";
            const char *texto_newton_raphson_derivada_numerica =
                "Voce escolheu 3 -> Newton Raphson com Derivada Numerica (NR-D).\n";
            const char *texto_metodo_cadastrado =
                "Método cadastrado: ";
            const char *texto_remover_funcao_cadastrada =
                "Voce escolheu 2 -> Remover uma funcao ja cadastrada.\n";
            const char *texto_resetar_funcoes_cadastradas =
                "Voce escolheu 3 -> Resetar funcoes cadastradas.\n";
            const char *texto_analise_passo_passo_funcao =
                "Voce escolheu 4 -> Mostrar analise passo a passo de um funcao.\n";
            const char *texto_mostrar_quadro_comparativo_func_cadastradas =
                "Voce escolheu 5 -> Gerar quadro comparativo das funcoes cadastradas.\n";
            const char *texto_mostrar_isolamento_funcao =
                "Voce escolheu 6 -> Mostrar isolamento de uma funcao.\n";
            const char *texto_entrada_invalida = "Entrada inválida. Teste novamente. \n";

            // Inicialização do painel, a partir dela será feita a iteração com o usuário.
            void init();
            void output() const;
            // Output de textos da aplicação. Esses textos estão alocados em atributos da classe Painel.
            void output(const char *texto_principal) const;
    };
} // namespace metodos_numericos1::include

#endif /* METODOS_NUMERICOS1_INCLUDE_PAINEL_HPP_ */
