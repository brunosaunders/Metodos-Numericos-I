#include <iostream>
#include <string>
#include <iomanip>

#include "Tabela.hpp"

namespace metodos_numericos1::outputs {
        void Tabela::formata_cabecalho(std::string palavra, int tamanho_coluna) {
            int size = palavra.size();
            int padding = (tamanho_coluna - size) / 2;
            int correcao = (tamanho_coluna - size) % 2;
            int tamanho_palavra = tamanho_coluna - 2*padding - correcao;
            std::cout << std::setw(padding + correcao + tamanho_palavra) << palavra << std::setw(padding) << "|";
        }

        void Tabela::formata_numero_cientifico(double numero, int precisao, int largura_total, int padding) {
            int largura_numeros = largura_total - 2*padding;

            std::cout << std::scientific << std::setprecision(precisao) << std::setw(largura_numeros + padding) << numero << std::setw(padding) << "|";
            std::cout << std::defaultfloat;
        }

        void Tabela::formata_numero_normal(double numero, int largura_total, int padding) {
            int largura_numeros = largura_total - 2*padding;
            std::cout << std::defaultfloat << std::setw(largura_numeros + padding) << numero << std::setw(padding) << "|";
        }

        void Tabela::formata_numero(double numero, int largura_total, int padding) {
            std::string n = std::to_string(numero);
            int size = n.size();

            int novo_padding = (largura_total + 2 * padding - size) / 2;
            std::cout << std::setprecision(1) << std::setw(size + novo_padding) << numero << std::setw(novo_padding) << "|";
        }

        void Tabela::formata_palavra(std::string palavra, int largura_total, int padding) {
            int largura_numeros = largura_total - 2*padding;
            std::cout << std::defaultfloat << std::setw(largura_numeros + padding) << palavra << std::setw(padding) << "|";
        }

        void Tabela::exibir_tampa_tabela(int tamanho) {
            for (int i=0; i < tamanho; i++) {
                std::cout << "-";
            }
            std::cout << std::endl;
        }
}