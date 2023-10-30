#include <iostream>
#include <string>
#include <iomanip>

#include "Tabela.hpp"

namespace metodos_numericos1::outputs {
        void Tabela::formata_numero_cientifico(double numero, int precisao, int largura_total) {

            std::cout << std::scientific << std::setprecision(precisao) << std::setw(largura_total) << numero << "|";
            std::cout << std::defaultfloat;
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

        void Tabela::formata_numero(int numero, int largura_total, int precisao) {

            std::cout << std::fixed << std::setprecision(precisao) << std::setw(largura_total) << numero << "|";
        }
        
        void Tabela::formata_numero(double numero, int largura_total, int precisao) {
            

            std::cout << std::right << std::setprecision(precisao) << std::setw(largura_total) << numero <<  "|";
        }

        int conta_substrings(const std::string& main_string, const std::string& substring) {
            int count = 0;
            size_t offset = 0;
            
            while (true) {
                size_t foundPos = main_string.find(substring, offset);
                
                if (foundPos != std::string::npos) {
                    count++;
                    offset = foundPos + substring.length();
                } else {
                    break;
                }
            }
            
            return count;
        }

        int conta_caracters_especias(std::string p) {
            std::string c_especiais[6] = {"ã", "õ", "á", "é", "ç", "à"};
            int contador = 0;

            for (auto& c : c_especiais) {
                contador += conta_substrings(p, c);
            }
            return contador;
        }

        void Tabela::formata_palavra(std::string palavra, int largura_total) {
            int tamanho_palavra = palavra.size() ;

            int caracteres_especiais = conta_caracters_especias(palavra);
            largura_total += caracteres_especiais;

            std::cout << std::right << std::setw(largura_total) << palavra << "|";
        }

        void Tabela::exibir_tampa_tabela(int tamanho) {
            for (int i=0; i < tamanho; i++) {
                std::cout << "-";
            }
            std::cout << std::endl;
        }
}