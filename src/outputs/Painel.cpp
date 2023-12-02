#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <string>
#include <limits>

#include "Painel.hpp"
#include "exceptions/PivoZeroException.hpp"
#include "fmt/core.h"
#include "fmt/format.h"
#include "Gauss.hpp"
#include "GaussJordan.hpp"
#include "Cramer.hpp"
#include "Tabela.hpp"

using namespace metodos_numericos1::outputs;
using namespace metodos_numericos1::metodos;

Painel::Painel() {}


void Painel::init(){

    bool repetir_painel, repetir_escolha_metodo;
    int escolha_usuario, precisao, ordem_matriz_C;
    double a;
    std::vector<std::vector<double>> matriz_C;
    std::vector<double> vetor_v, vetor_linha;

    std::vector<Metodo*> sistemas;

    u_char temp;

    try {

        this->limpar_painel();

        repetir_painel = true;
        while (repetir_painel) {

            this->output(this->texto_menu_principal);
            escolha_usuario = 0;
            std::cout << "R: ";
            std::cin >> escolha_usuario;

            switch (escolha_usuario) {

                case 0:
                    repetir_painel = false;
                    this->limpar_painel();
                    break;

                case 1: 
                    // 1 -> Cadastrar um sistema linear e método para análise.

                    this->limpar_painel();
                    this->output(this->texto_cadastrar_sistema_linear_metodo_analise);

                    a = 0.0;
                    this->output(this->texto_inserir_parametro_a);
                    std::cin >> a;

                    while (a < 0.0) {

                        this->formata_avisos(this->texto_entrada_invalida);
                        this->output(this->texto_inserir_parametro_a);
                        std::cin >> a;

                    }
                    this->limpar_painel();

                    ordem_matriz_C = 0;
                    this->output(this->texto_inserir_ordem_matriz);
                    std::cin >> ordem_matriz_C;

                    while (ordem_matriz_C <= 0) {

                        this->formata_avisos(this->texto_entrada_invalida);
                        this->output(this->texto_inserir_ordem_matriz);
                        std::cin >> ordem_matriz_C;

                    }
                    this->limpar_painel();

                    matriz_C = std::vector<std::vector<double>>(ordem_matriz_C, std::vector<double>(ordem_matriz_C, 0.0));

                    for (int i = 0; i < ordem_matriz_C; i++) {

                        this->output(this->texto_inserir_linha_matriz, i + 1);
                        
                        for (int j = 0; j < ordem_matriz_C; j++) {

                            std::cin >> matriz_C[i][j];

                        }

                    }
                    this->limpar_painel();
                    
                    vetor_v = std::vector<double>(ordem_matriz_C, 0.0);

                    this->output(this->texto_inserir_vetor_v);
                    for (int i = 0; i < ordem_matriz_C; i++) {

                        std::cin >> vetor_v[i];

                    }

                    repetir_escolha_metodo = true;
                    while (repetir_escolha_metodo) {

                        this->limpar_painel();
                        this->output(this->texto_escolher_metodo);
                        std::cin >> escolha_usuario;

                        while (escolha_usuario < 1 || escolha_usuario > 3) {
                            
                            this->limpar_painel();
                            this->formata_avisos(this->texto_entrada_invalida);
                            this->output(this->texto_escolher_metodo);
                            std::cin >> escolha_usuario;

                        }
                        this->limpar_painel();

                        if (escolha_usuario == 1) {

                            this->output(this->texto_escolheu_gauss);
                            sistemas.push_back(new Gauss(matriz_C, vetor_v, a));

                        } else if (escolha_usuario == 2) {

                            this->output(this->texto_escolheu_gauss_jordan);
                            sistemas.push_back(new GaussJordan(matriz_C, vetor_v, a));

                        } else {

                            this->output(this->texto_escolheu_cramer);
                            sistemas.push_back(new Cramer(matriz_C, vetor_v, a));

                        }

                        sistemas[sistemas.size() - 1]->resolve_sistema_linear();

                        this->formata_avisos(this->texto_metodo_cadastrado);

                        this->output(this->texto_cadastrar_outro_metodo);
                        std::cin >> escolha_usuario;

                        while (escolha_usuario < 1 || escolha_usuario > 2) {

                            this->limpar_painel();
                            this->formata_avisos(this->texto_entrada_invalida);
                            this->output(this->texto_cadastrar_outro_metodo);
                            std::cin >> escolha_usuario;

                        }

                        if (escolha_usuario == 2) repetir_escolha_metodo = false;

                    }
                    this->limpar_painel();

                    break;

                case 2: 
                    // 2 -> Remover um sistema linear já cadastrado.

                    this->limpar_painel();
                    this->output(this->texto_remover_sistema_cadastrado);

                    if (sistemas.size() > 0) {

                        this->imprimir_sistemas_cadastrados(sistemas);
                        this->output(this->texto_inserir_indice_remover);
                        std::cin >> escolha_usuario;

                        while (escolha_usuario < 0 || escolha_usuario > sistemas.size()) {

                            this->limpar_painel();
                            this->formata_avisos(this->texto_entrada_invalida);
                            this->imprimir_sistemas_cadastrados(sistemas);
                            this->output(this->texto_inserir_indice_remover);
                            std::cin >> escolha_usuario;

                        }

                        if (escolha_usuario == 0) {
                            
                            this->limpar_painel();
                            break;

                        };

                        escolha_usuario = escolha_usuario - 1;
                        sistemas.erase(sistemas.begin() + escolha_usuario);
                        this->limpar_painel();
                        this->formata_avisos(this->texto_sistema_removido);

                    } else {

                        this->formata_avisos(this->texto_nenhum_sistema_para_remover);

                    }

                    break;

                case 3: 
                    // 3 -> Resetar sistemas lineares cadastrados.

                    this->limpar_painel();
                    this->output(this->texto_resetar_sistemas_cadastrados);

                    if (sistemas.size() > 0) {

                        sistemas.clear();
                        this->formata_avisos(this->texto_sistemas_resetados);

                    } else {

                        this->formata_avisos(this->texto_nenhum_sistema_para_remover);

                    }

                    break;

                case 4: 
                    // 4 -> Mostrar análise de um sistema linear.

                    this->limpar_painel();
                    this->output(this->texto_analise_um_sistema);

                    if (sistemas.size() > 0) {

                        this->imprimir_sistemas_cadastrados(sistemas);
                        this->output(this->texto_inserir_indice_analisar);
                        std::cin >> escolha_usuario;

                        while (escolha_usuario < 0 || escolha_usuario > sistemas.size()) {

                            this->limpar_painel();
                            this->formata_avisos(this->texto_entrada_invalida);
                            this->imprimir_sistemas_cadastrados(sistemas);
                            this->output(this->texto_inserir_indice_analisar);
                            std::cin >> escolha_usuario;

                        }

                        if (escolha_usuario == 0) {

                            this->limpar_painel();
                            break;

                        }
                        this->limpar_painel();

                        this->output(this->texto_inserir_precisao);
                        std::cin >> precisao;

                        while (precisao < 0) {

                            this->limpar_painel();
                            this->formata_avisos(this->texto_entrada_invalida);
                            this->output(this->texto_inserir_precisao);
                            std::cin >> precisao;

                        }
                        this->limpar_painel();

                        this->imprimir_quadro_comparativo(std::vector<Metodo*>{sistemas[escolha_usuario - 1]}, precisao);
                        std::cout << std::endl;

                    } else {

                        this->formata_avisos(this->texto_sem_sistemas_analisar);

                    }

                    break;

                case 5: 
                    // 5 -> Mostrar análise de todos os sistemas lineares cadastrados.

                    this->limpar_painel();
                    this->output(this->texto_analisar_todos_sistemas);

                    if (sistemas.size() > 0) {

                        this->output(this->texto_inserir_precisao);
                        std::cin >> precisao;

                        while (precisao < 0) {

                            this->limpar_painel();
                            this->formata_avisos(this->texto_entrada_invalida);
                            this->output(this->texto_inserir_precisao);
                            std::cin >> precisao;

                        }
                        this->limpar_painel();

                        this->imprimir_quadro_comparativo(sistemas, precisao);
                        std::cout << std::endl;

                    } else {

                        this->formata_avisos(this->texto_sem_sistemas_analisar);

                    }

                    break;

                default:
                    this->limpar_painel();
                    Painel::formata_avisos(this->texto_entrada_invalida);

                    break;

            }

        }

    } catch (std::exception& e) {

        std::cout << e.what() << std::endl;

    }
}

void Painel::formata_avisos(const char *texto) const {
    fmt::print("\n!!! {0} !!!\n\n", texto);
}

void Painel::output(const char *texto_principal) const {
    std::cout << texto_principal;
}

void Painel::output(const char *texto_principal, int numero) const {
    fmt::print(texto_principal, numero);
}

void Painel::imprimir_quadro_comparativo(std::vector<Metodo*> sistemas, int precisao) const {

    // Dimensão da maior matriz usada nos métodos.
    int n_maximo = 0;

    // Booleano para indicar se o balanço quebrou ou não.
    bool quebrou;

    // Tamanho do espaço vazio nas células da tabela.
    int largura_extra = 1;

    // Largura da coluna "ID"
    int largura_id = 0;

    // Largura da coluna "Método"
    int largura_metodo = 6 + largura_extra ;

    // Largura da coluna "a"
    int largura_a = 0;

    // Largura de cada coluna da matriz C
    int largura_coluna_c = 0;

    // Largura da coluna "v"
    int largura_v = 0;

    // Largura da coluna "d"
    int largura_d = 0;

    // Largura da coluna "a*d"
    int largura_a_d = 0;

    // Largura da coluna "Quebrou?"
    int largura_quebrou = 9;

    // Largura total da tabela
    int largura_total;

    // Variável para guardar a largura de uma coluna temporariamente.
    int largura_temp;

    // Calculando as larguras das colunas e o n_máximo.

    // Coluna "ID"
    largura_id = largura_extra + std::trunc(std::log10(sistemas.size() == 0 ? 1 : sistemas.size())) + 1;

    for (int m = 0; m < sistemas.size(); m++) {

        // Coluna "a"
        largura_temp = largura_extra + precisao + std::trunc(std::log10(std::abs(sistemas[m]->get_a()))) + 2;
        largura_a = largura_temp > largura_a ? largura_temp : largura_a;

        for (int i = 0; i < sistemas[m]->get_matriz_c_inicial().size(); i++) {

            // Colunas da matriz "C"
            for (int j = 0; j < sistemas[m]->get_matriz_c_inicial().size(); j++) {

                largura_temp = largura_extra + precisao + std::trunc(std::log10(std::abs(sistemas[m]->get_matriz_c_inicial()[i][j]))) + 2;
                largura_coluna_c = largura_temp > largura_coluna_c ? largura_temp : largura_coluna_c;

            }

            // Coluna "v"
            largura_temp = largura_extra + precisao + std::trunc(std::log10(std::abs(sistemas[m]->get_vetor_v_inicial()[i]))) + 2;
            largura_v = largura_temp > largura_v ? largura_temp : largura_v;

            // Coluna "d"
            largura_temp = largura_extra + precisao + std::trunc(std::log10(std::abs(sistemas[m]->get_vetor_d_deslocamentos()[i]))) + 2;
            largura_d = largura_temp > largura_d ? largura_temp : largura_d;

            // Coluna "a*d"
            largura_temp = largura_extra + precisao + std::trunc(std::log10(std::abs(sistemas[m]->get_a() * sistemas[m]->get_vetor_d_deslocamentos()[i]))) + 2;
            largura_a_d = largura_temp > largura_a_d ? largura_temp : largura_a_d;

        }

        n_maximo = n_maximo > sistemas[m]->get_matriz_c_inicial().size() ? n_maximo : sistemas[m]->get_matriz_c_inicial().size();

    }

    // Largura total das colunas.
    largura_total = largura_id + largura_metodo + largura_a + n_maximo*largura_coluna_c + largura_v + largura_d + largura_a_d + largura_quebrou;
    // Adicionando a quantidade de linhas verticas à largura total.
    largura_total = largura_total + 8 + n_maximo;

    // Exibindo nome das colunas da tabela.
    Tabela::exibir_tampa_tabela(largura_total);
    std::cout << "|";
    Tabela::formata_palavra("ID", largura_id);
    Tabela::formata_palavra("Método", largura_metodo);
    Tabela::formata_palavra("a", largura_a);

    for (int i = 1; i <= n_maximo; i++) {

        Tabela::formata_palavra(std::string("C") + std::to_string(i), largura_coluna_c);

    }

    Tabela::formata_palavra("v", largura_v);
    Tabela::formata_palavra("d", largura_d);
    Tabela::formata_palavra("a*d", largura_a_d);
    Tabela::formata_palavra("Quebrou?", largura_quebrou);
    std::cout << std::endl;

    Tabela::exibir_tampa_tabela(largura_total);

    // Exibindo linhas da tabela.
    for (int m = 0; m < sistemas.size(); m++) {

        // Calculando se o balanço quebrou.
        quebrou = false;
        for (int d = 0; d < sistemas[m]->get_vetor_d_deslocamentos().size(); d++) {

            if (sistemas[m]->get_a() * sistemas[m]->get_vetor_d_deslocamentos()[d] > 3.0) {

                quebrou = true;

            }

        }
        
        // Exibindo a primeira "sublinha" da linha.
        std::cout << "|";
        Tabela::formata_numero(m + 1, largura_id, 0);
        Tabela::formata_palavra(sistemas[m]->get_nome_abreviado(), largura_metodo);
        Tabela::formata_numero(sistemas[m]->get_a(), largura_a, precisao);

        for (int j = 0; j < n_maximo; j++) {

            if (j < sistemas[m]->get_matriz_c_inicial()[0].size()) {

                Tabela::formata_numero(sistemas[m]->get_matriz_c_inicial()[0][j], largura_coluna_c, precisao);

            } else {

                Tabela::formata_palavra(" ", largura_coluna_c);

            }

        }

        Tabela::formata_numero(sistemas[m]->get_vetor_v_inicial()[0], largura_v, precisao);
        Tabela::formata_numero(sistemas[m]->get_vetor_d_deslocamentos()[0], largura_d, precisao);
        Tabela::formata_numero(sistemas[m]->get_a() * sistemas[m]->get_vetor_d_deslocamentos()[0], largura_a_d, precisao);
        if (quebrou) {

            Tabela::formata_palavra("Sim", largura_quebrou);

        } else {

            Tabela::formata_palavra("Não", largura_quebrou);

        }
        std::cout << std::endl;

        // Exibindo as demais "sublinhas" da linha.
        for (int i = 1; i < sistemas[m]->get_matriz_c_inicial().size(); i++) {

            std::cout << "|";
            Tabela::formata_palavra(" ", largura_id);
            Tabela::formata_palavra(" ", largura_metodo);
            Tabela::formata_palavra(" ", largura_a);

            for (int j = 0; j < n_maximo; j++) {

                if (j < sistemas[m]->get_matriz_c_inicial()[0].size()) {

                    Tabela::formata_numero(sistemas[m]->get_matriz_c_inicial()[i][j], largura_coluna_c, precisao);

                } else {

                    Tabela::formata_palavra(" ", largura_coluna_c);

                }

            }

            Tabela::formata_numero(sistemas[m]->get_vetor_v_inicial()[i], largura_v, precisao);
            Tabela::formata_numero(sistemas[m]->get_vetor_d_deslocamentos()[i], largura_d, precisao);
            Tabela::formata_numero(sistemas[m]->get_a() * sistemas[m]->get_vetor_d_deslocamentos()[i], largura_a_d, precisao);
            Tabela::formata_palavra(" ", largura_quebrou);
            std::cout << std::endl;

        }

        Tabela::exibir_tampa_tabela(largura_total);

    }

}

void Painel::imprimir_sistemas_cadastrados(std::vector<Metodo*> sistemas, int precisao) {
    
    // Dimensão da maior matriz usada nos métodos.
    int n_maximo = 0;

    // Tamanho do espaço vazio nas células da tabela.
    int largura_extra = 1;

    // Largura da coluna "ID"
    int largura_id = 0;

    // Largura da coluna "Método"
    int largura_metodo = 6 + largura_extra ;

    // Largura da coluna "a"
    int largura_a = 0;

    // Largura de cada coluna da matriz C
    int largura_coluna_c = 0;

    // Largura da coluna "v"
    int largura_v = 0;

    // Largura total da tabela
    int largura_total;

    // Variável para guardar a largura de uma coluna temporariamente.
    int largura_temp;

    // Calculando as larguras das colunas e o n_máximo.

    // Coluna "ID"
    largura_id = largura_extra + std::trunc(std::log10(sistemas.size() == 0 ? 1 : sistemas.size())) + 1;

    for (int m = 0; m < sistemas.size(); m++) {

        // Coluna "a"
        largura_temp = largura_extra + precisao + std::trunc(std::log10(std::abs(sistemas[m]->get_a()))) + 2;
        largura_a = largura_temp > largura_a ? largura_temp : largura_a;

        for (int i = 0; i < sistemas[m]->get_matriz_c_inicial().size(); i++) {

            // Colunas da matriz "C"
            for (int j = 0; j < sistemas[m]->get_matriz_c_inicial().size(); j++) {

                largura_temp = largura_extra + precisao + std::trunc(std::log10(std::abs(sistemas[m]->get_matriz_c_inicial()[i][j]))) + 2;
                largura_coluna_c = largura_temp > largura_coluna_c ? largura_temp : largura_coluna_c;

            }

            // Coluna "v"
            largura_temp = largura_extra + precisao + std::trunc(std::log10(std::abs(sistemas[m]->get_vetor_v_inicial()[i]))) + 2;
            largura_v = largura_temp > largura_v ? largura_temp : largura_v;

        }

        n_maximo = n_maximo > sistemas[m]->get_matriz_c_inicial().size() ? n_maximo : sistemas[m]->get_matriz_c_inicial().size();

    }

    // Largura total das colunas.
    largura_total = largura_id + largura_metodo + largura_a + n_maximo*largura_coluna_c + largura_v;
    // Adicionando a quantidade de linhas verticas à largura total.
    largura_total = largura_total + 5 + n_maximo;

    // Exibindo nome das colunas da tabela.
    Tabela::exibir_tampa_tabela(largura_total);
    std::cout << "|";
    Tabela::formata_palavra("ID", largura_id);
    Tabela::formata_palavra("Método", largura_metodo);
    Tabela::formata_palavra("a", largura_a);

    for (int i = 1; i <= n_maximo; i++) {

        Tabela::formata_palavra(std::string("C") + std::to_string(i), largura_coluna_c);

    }

    Tabela::formata_palavra("v", largura_v);
    std::cout << std::endl;

    Tabela::exibir_tampa_tabela(largura_total);

    // Exibindo linhas da tabela.
    for (int m = 0; m < sistemas.size(); m++) {
        
        // Exibindo a primeira "sublinha" da linha.
        std::cout << "|";
        Tabela::formata_numero(m + 1, largura_id, 0);
        Tabela::formata_palavra(sistemas[m]->get_nome_abreviado(), largura_metodo);
        Tabela::formata_numero(sistemas[m]->get_a(), largura_a, precisao);

        for (int j = 0; j < n_maximo; j++) {

            if (j < sistemas[m]->get_matriz_c_inicial()[0].size()) {

                Tabela::formata_numero(sistemas[m]->get_matriz_c_inicial()[0][j], largura_coluna_c, precisao);

            } else {

                Tabela::formata_palavra(" ", largura_coluna_c);

            }

        }

        Tabela::formata_numero(sistemas[m]->get_vetor_v_inicial()[0], largura_v, precisao);

        std::cout << std::endl;

        // Exibindo as demais "sublinhas" da linha.
        for (int i = 1; i < sistemas[m]->get_matriz_c_inicial().size(); i++) {

            std::cout << "|";
            Tabela::formata_palavra(" ", largura_id);
            Tabela::formata_palavra(" ", largura_metodo);
            Tabela::formata_palavra(" ", largura_a);

            for (int j = 0; j < n_maximo; j++) {

                if (j < sistemas[m]->get_matriz_c_inicial()[0].size()) {

                    Tabela::formata_numero(sistemas[m]->get_matriz_c_inicial()[i][j], largura_coluna_c, precisao);

                } else {

                    Tabela::formata_palavra(" ", largura_coluna_c);

                }

            }

            Tabela::formata_numero(sistemas[m]->get_vetor_v_inicial()[i], largura_v, precisao);

            std::cout << std::endl;

        }

        Tabela::exibir_tampa_tabela(largura_total);

    }

}

void Painel::limpar_painel() const {

    // Limpa o terminal.
    std::system("clear");

}