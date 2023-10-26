#ifndef TABELA_HPP
#define TABELA_HPP
#include <string> 

namespace metodos_numericos1::outputs
{

    class Tabela { 
    public:
        static void formata_cabecalho(std::string palavra, int tamanho_coluna);
        static void formata_numero_cientifico(double numero, int precisao, int largura_total, int padding);
        static void formata_numero_normal(double numero, int largura_total, int padding);
        static void exibir_tampa_tabela(int tamanho);
        static void formata_palavra(std::string palavra, int largura_total, int padding);
        static void formata_numero(double numero, int largura_total, int padding);
        static void formata_numero(int numero, int largura_total, int padding);
    }; 
} 

#endif
