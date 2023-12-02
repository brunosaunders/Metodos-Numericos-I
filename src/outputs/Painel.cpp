#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <string>

#include "Painel.hpp"
#include "exceptions/PivoZeroException.hpp"
#include "fmt/core.h"
#include "fmt/format.h"
#include "Gauss.hpp"
#include "Tabela.hpp"

using namespace metodos_numericos1::outputs;
using namespace metodos_numericos1::metodos;

Painel::Painel() {}


void Painel::init(std::vector<Metodo*> metodos){
    int escolha_usuario;
    this->output(this->texto_menu_principal);
    std::cout << "R: ";
    std::cin >> escolha_usuario;
    try {
        switch (escolha_usuario) {
            case 0:
                {
                    break;
                }
            case 1: 
                {
                    // TODO
                }
            case 2: 
                {
                    // TODO                
                }
            case 3: 
                {
                    // TODO
                }
            case 4: 
                {
                    // TODO
                }
            case 5: 
                {
                    // TODO
                }
            default: 
                {
                    Painel::formata_avisos(this->texto_entrada_invalida);
                    this->init(metodos);
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

void Painel::imprimir_quadro_comparativo(std::vector<Metodo*> metodos, int precisao) const {

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
    largura_id = largura_extra + std::trunc(std::log10(metodos.size() == 0 ? 1 : metodos.size())) + 1;

    for (int m = 0; m < metodos.size(); m++) {

        // Coluna "a"
        largura_temp = largura_extra + precisao + std::trunc(std::log10(std::abs(metodos[m]->get_a()))) + 2;
        largura_a = largura_temp > largura_a ? largura_temp : largura_a;

        for (int i = 0; i < metodos[m]->get_matriz_c_inicial().size(); i++) {

            // Colunas da matriz "C"
            for (int j = 0; j < metodos[m]->get_matriz_c_inicial().size(); j++) {

                largura_temp = largura_extra + precisao + std::trunc(std::log10(std::abs(metodos[m]->get_matriz_c_inicial()[i][j]))) + 2;
                largura_coluna_c = largura_temp > largura_coluna_c ? largura_temp : largura_coluna_c;

            }

            // Coluna "v"
            largura_temp = largura_extra + precisao + std::trunc(std::log10(std::abs(metodos[m]->get_vetor_v_inicial()[i]))) + 2;
            largura_v = largura_temp > largura_v ? largura_temp : largura_v;

            // Coluna "d"
            largura_temp = largura_extra + precisao + std::trunc(std::log10(std::abs(metodos[m]->get_vetor_d_deslocamentos()[i]))) + 2;
            largura_d = largura_temp > largura_d ? largura_temp : largura_d;

            // Coluna "a*d"
            largura_temp = largura_extra + precisao + std::trunc(std::log10(std::abs(metodos[m]->get_a() * metodos[m]->get_vetor_d_deslocamentos()[i]))) + 2;
            largura_a_d = largura_temp > largura_a_d ? largura_temp : largura_a_d;

        }

        n_maximo = n_maximo > metodos[m]->get_matriz_c_inicial().size() ? n_maximo : metodos[m]->get_matriz_c_inicial().size();

    }

    largura_total = 8 + n_maximo + largura_id + largura_metodo + largura_a + n_maximo*largura_coluna_c + largura_v + largura_d + largura_a_d + largura_quebrou;

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
    for (int m = 0; m < metodos.size(); m++) {

        // Calculando se o balanço quebrou.
        quebrou = false;
        for (int d = 0; d < metodos[m]->get_vetor_d_deslocamentos().size(); d++) {

            if (metodos[m]->get_a() * metodos[m]->get_vetor_d_deslocamentos()[d] > 3.0) {

                quebrou = true;

            }

        }
        
        // Exibindo a primeira "sublinha" da linha.
        std::cout << "|";
        Tabela::formata_numero(m + 1, largura_id, 0);
        Tabela::formata_palavra(metodos[m]->get_nome_abreviado(), largura_metodo);
        Tabela::formata_numero(metodos[m]->get_a(), largura_a, precisao);

        for (int j = 0; j < n_maximo; j++) {

            if (j < metodos[m]->get_matriz_c_inicial()[0].size()) {

                Tabela::formata_numero(metodos[m]->get_matriz_c_inicial()[0][j], largura_coluna_c, precisao);

            } else {

                Tabela::formata_palavra(" ", largura_coluna_c);

            }

        }

        Tabela::formata_numero(metodos[m]->get_vetor_v_inicial()[0], largura_v, precisao);
        Tabela::formata_numero(metodos[m]->get_vetor_d_deslocamentos()[0], largura_d, precisao);
        Tabela::formata_numero(metodos[m]->get_a() * metodos[m]->get_vetor_d_deslocamentos()[0], largura_a_d, precisao);
        if (quebrou) {

            Tabela::formata_palavra("Sim", largura_quebrou);

        } else {

            Tabela::formata_palavra("Não", largura_quebrou);

        }
        std::cout << std::endl;

        // Exibindo as demais "sublinhas" da linha.
        for (int i = 1; i < metodos[m]->get_matriz_c_inicial().size(); i++) {

            std::cout << "|";
            Tabela::formata_palavra(" ", largura_id);
            Tabela::formata_palavra(" ", largura_metodo);
            Tabela::formata_palavra(" ", largura_a);

            for (int j = 0; j < n_maximo; j++) {

                if (j < metodos[m]->get_matriz_c_inicial()[0].size()) {

                    Tabela::formata_numero(metodos[m]->get_matriz_c_inicial()[i][j], largura_coluna_c, precisao);

                } else {

                    Tabela::formata_palavra(" ", largura_coluna_c);

                }

            }

            Tabela::formata_numero(metodos[m]->get_vetor_v_inicial()[i], largura_v, precisao);
            Tabela::formata_numero(metodos[m]->get_vetor_d_deslocamentos()[i], largura_d, precisao);
            Tabela::formata_numero(metodos[m]->get_a() * metodos[m]->get_vetor_d_deslocamentos()[i], largura_a_d, precisao);
            Tabela::formata_palavra(" ", largura_quebrou);
            std::cout << std::endl;

        }

        Tabela::exibir_tampa_tabela(largura_total);

    }

}