#include <iostream>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <typeinfo>

#include "Passos.hpp"
#include "NewtonRaphson.hpp"
#include "NewtonRaphsonFL.hpp"
#include "Derivacao.hpp"
#include "NewtonRaphsonComDerivadaNumerica.hpp"
#include "Pendulo.hpp"
#include "Utils.hpp"


namespace Passos {
    Passo::Passo(int k, double xk, double xk_1, double fxk, double fxk_1, double e1, double e2)
        : k(k), xk(xk), xk_1(xk_1), fxk(fxk), fxk_1(fxk_1), e1(e1), e2(e2) {}

    void exibir_passos_todos_intervalos(NewtonRaphson* metodo) {
        // TODO: Chamar exibir_passos para cada intervalo do método.
    }

    void formata_cabecalho(std::string palavra, int tamanho_coluna) {
        int size = palavra.size();
        int padding = (tamanho_coluna - size) / 2;
        int correcao = (tamanho_coluna - size) % 2;
        int tamanho_palavra = tamanho_coluna - 2*padding - correcao;
        std::cout << std::setw(padding + correcao + tamanho_palavra) << palavra << std::setw(padding) << "|";
    }

    void formata_numero_cientifico(double numero, int precisao, int largura_total, int padding) {
        int largura_numeros = largura_total - 2*padding;

        std::cout << std::scientific << std::setprecision(precisao) << std::setw(largura_numeros + padding) << numero << std::setw(padding) << "|";
    }

    void formata_numero_normal(double numero, int largura_total, int padding) {
        int largura_numeros = largura_total - 2*padding;
        std::cout << std::defaultfloat << std::setw(largura_numeros + padding) << numero << std::setw(padding) << "|";
    }

    void exibir_tampa_tabela(int tamanho) {
        for (int i=0; i < tamanho; i++) {
            std::cout << "-";
        }
        std::cout << std::endl;
    }

    void exibir_passos(NewtonRaphson* metodo) {
        std::cout << std::endl;
        
        double x0 = 5; // Valor inicial arbitrário
        metodo->calcula_raiz(x0);


        Polinomio p = metodo->get_funcao();
        int max_iteracoes = metodo->get_iteracoes_de_x().size();

        int precisao_fx_xk = std::log10(metodo->get_erro()) * (-1);

        // Definir largura de cada coluna dependendo da precisão dos valores
        int largura_numeros = precisao_fx_xk + 5;
        int padding = 3;
        int largura_total_coluna = largura_numeros + 2*padding;

        // Cálculo do tamanho da coluna de k 
        std::string maior_k = std::to_string(max_iteracoes);
        int largura_k = maior_k.size() + 2*padding;

        int largura_total_tabela = largura_k + largura_total_coluna * 6 + 1;


        // Imprimir cabeçalho
        std::cout << "Método: " << metodo->get_classe(precisao_fx_xk) << std::endl;
        std::cout << "Intervalo: TODO\n";

        exibir_tampa_tabela(largura_total_tabela);

        std::cout << "|";
        formata_cabecalho("k", largura_k);
        formata_cabecalho("xk", largura_total_coluna);
        formata_cabecalho("xk-1", largura_total_coluna);
        formata_cabecalho("f(xk)", largura_total_coluna);
        formata_cabecalho("f'(xk)", largura_total_coluna);
        formata_cabecalho("e1", largura_total_coluna);
        formata_cabecalho("e2", largura_total_coluna);
        std::cout << std::endl;

        double xk_1 = x0;
        Polinomio f_derivada = metodo->get_funcao().get_funcao_derivada();
        Derivacao* derivacao = new Derivacao();

        for (int k = 0; k < metodo->get_num_passos(); k++) {
            double xk = metodo->get_iteracoes_de_x()[k];
            double fxk = p.get_valor_funcao(xk);
            double e1 = std::abs(xk - xk_1);
            double e2 = std::abs(fxk);
            double f_derivada_xk;

            // Dependendo do método, o cálculo da derivada é diferente
            if (typeid(*metodo) == typeid(NewtonRaphsonComDerivadaNumerica)) {
                f_derivada_xk = derivacao->derivar(metodo->get_funcao(), xk);
            } else {
                f_derivada_xk = f_derivada.get_valor_funcao(xk);
            }

            // Configurar alinhamento
            // std::cout << std::scientific << std::setprecision(precisao_fx_xk) << std::setw(3) << std::to_string(k+1) << "|";
            std::cout << "|";
            formata_numero_normal(k, largura_k, padding);
            formata_numero_cientifico(xk, precisao_fx_xk, largura_total_coluna, padding);
            formata_numero_cientifico(xk_1, precisao_fx_xk, largura_total_coluna, padding);
            formata_numero_cientifico(fxk, precisao_fx_xk, largura_total_coluna, padding);
            formata_numero_cientifico(f_derivada_xk, precisao_fx_xk, largura_total_coluna, padding);
            formata_numero_cientifico(e1, precisao_fx_xk, largura_total_coluna, padding);
            formata_numero_cientifico(e2, precisao_fx_xk, largura_total_coluna, padding);
            std::cout << std::endl;

            xk_1 = xk;
        }

        exibir_tampa_tabela(largura_total_tabela);
    }
}