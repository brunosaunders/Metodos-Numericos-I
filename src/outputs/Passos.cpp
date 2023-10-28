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
#include "Tabela.hpp"


namespace metodos_numericos1::outputs {
    void Passos::exibir_passos_todas_raizes(NewtonRaphson* metodo) {
        std::cout << std::endl;
        
        int precisao_fx_xk = std::log10(metodo->get_erro()) * (-1);

        metodo->calcula_raizes();
        std::cout << "Método: " << metodo->get_classe(precisao_fx_xk) << std::endl;
        
        for (int i=0; i < metodo->get_iteracoes_de_x_todas_raizes().size(); i++) {
            Passos::exibir_passos_raiz(metodo, i);
        }
        std::cout << "Raízes: [ ";
        for (auto& item : metodo->get_raizes()) {
            std::cout << std::setprecision(precisao_fx_xk + 3) << item << " ";
        }
        std::cout << "]\n";
    }


    void Passos::exibir_passos_raiz(NewtonRaphson* metodo, int index) {

        Polinomio p = metodo->get_funcao();
        int max_iteracoes = metodo->get_iteracoes_de_x(index).size();

        int precisao_fx_xk = std::log10(metodo->get_erro()) * (-1);

        int largura_padrao = 12;

        std::pair intervalo = metodo->get_isolamento()[index];

        // Imprimir cabeçalho
        std::cout << index+1 << "a raiz\n";
        std::cout << "Intervalo: [" << intervalo.first << ", " << intervalo.second << "]\n";

        int largura_total_tabela = 7 * largura_padrao + 8;

        
        metodos_numericos1::outputs::Tabela::exibir_tampa_tabela(largura_total_tabela);

        std::cout << "|";
        metodos_numericos1::outputs::Tabela::formata_palavra("k", largura_padrao);
        metodos_numericos1::outputs::Tabela::formata_palavra("xk", largura_padrao);
        metodos_numericos1::outputs::Tabela::formata_palavra("xk-1", largura_padrao);
        metodos_numericos1::outputs::Tabela::formata_palavra("f(xk)", largura_padrao);
        metodos_numericos1::outputs::Tabela::formata_palavra("f'(xk)", largura_padrao);
        metodos_numericos1::outputs::Tabela::formata_palavra("e1", largura_padrao);
        metodos_numericos1::outputs::Tabela::formata_palavra("e2", largura_padrao);
        std::cout << std::endl;
        metodos_numericos1::outputs::Tabela::exibir_tampa_tabela(largura_total_tabela);

        double xk_1 = metodo->get_iteracoes_de_x(index)[0];
        Polinomio f_derivada = metodo->get_funcao().get_funcao_derivada();
        Derivacao* derivacao = new Derivacao();

        for (int k = 1; k < metodo->get_iteracoes_de_x(index).size(); k++) {
            double xk = metodo->get_iteracoes_de_x(index)[k];
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

            std::cout << "|";
            metodos_numericos1::outputs::Tabela::formata_numero(k, largura_padrao);
            metodos_numericos1::outputs::Tabela::formata_numero_cientifico(xk, precisao_fx_xk, largura_padrao);
            metodos_numericos1::outputs::Tabela::formata_numero_cientifico(xk_1, precisao_fx_xk, largura_padrao);
            metodos_numericos1::outputs::Tabela::formata_numero_cientifico(fxk, precisao_fx_xk, largura_padrao);
            metodos_numericos1::outputs::Tabela::formata_numero_cientifico(f_derivada_xk, precisao_fx_xk, largura_padrao);
            metodos_numericos1::outputs::Tabela::formata_numero_cientifico(e1, precisao_fx_xk, largura_padrao);
            metodos_numericos1::outputs::Tabela::formata_numero_cientifico(e2, precisao_fx_xk, largura_padrao);
            std::cout << std::endl;

            xk_1 = xk;
        }

        metodos_numericos1::outputs::Tabela::exibir_tampa_tabela(largura_total_tabela);
    }
}