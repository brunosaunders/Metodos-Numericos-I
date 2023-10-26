#include <iostream>
#include <string>
#include <iomanip>

#include "Tabela.hpp"

namespace metodos_numericos1::outputs {
        void Tabela::formata_cabecalho(std::string palavra, int tamanho_coluna) {
            int size = palavra.size();
            int padding = (tamanho_coluna - size) / 2;
            int correcao = (tamanho_coluna - size) % 2;
            int tamanho_palavra = tamanho_coluna - 2*padding;
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

        int conta_digitos(double numero) {
            int count = 0;
            int num = numero;

            // Handle the case of a zero as a special case
            if (num == 0) {
                return 1;
            }

            // Handle negative numbers by making them positive
            if (num < 0) {
                num = -num;
            }

            while (num != 0) {
                num = num / 10;
                count++;
            }

            return count;
        }

        void Tabela::formata_numero(int numero, int largura_total, int padding) {
            int tamanho_numero = std::to_string(numero).size() - 1;
            int novo_padding = (largura_total - tamanho_numero) / 2;

            int resto = (largura_total - tamanho_numero) % 2;

            int corrige_negativos = 0;
            if (numero < 0) corrige_negativos = 1;

            std::cout << std::fixed << std::setprecision(1) << std::setw(novo_padding + 2*tamanho_numero/3 - corrige_negativos) << numero << std::setw(novo_padding + resto + tamanho_numero/3 + corrige_negativos) << "|";
        }
        
        void Tabela::formata_numero(double numero, int largura_total, int padding) {
            int tamanho_numero = std::to_string(numero).size() - 1;
            int novo_padding = (largura_total - tamanho_numero) / 2;

            int resto = (largura_total - tamanho_numero) % 2;

            int corrige_negativos = 0;
            if (numero < 0) corrige_negativos = 1;

            std::cout << std::fixed << std::setprecision(1) << std::setw(novo_padding + 2*tamanho_numero/3 - corrige_negativos) << numero << std::setw(novo_padding + resto + tamanho_numero/3 + corrige_negativos) << "|";
        }

        void Tabela::formata_palavra(std::string palavra, int largura_total, int padding) {
            int tamanho_palavra = palavra.size() - 1;
            if (palavra == "Não") tamanho_palavra = 3;
            int novo_padding = (largura_total - tamanho_palavra) / 2;
            int resto = (largura_total - tamanho_palavra) % 2;

            std::cout << std::defaultfloat << std::setw(tamanho_palavra + novo_padding) << palavra << std::setw(novo_padding + resto) << "|";
        }

        void Tabela::exibir_tampa_tabela(int tamanho) {
            for (int i=0; i < tamanho; i++) {
                std::cout << "-";
            }
            std::cout << std::endl;
        }
}