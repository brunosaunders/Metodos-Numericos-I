#include "Passos.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include "NewtonRaphson.hpp"
#include "NewtonRaphsonFL.hpp"
#include "NewtonRaphsonComDerivadaNumerica.hpp"
#include "Pendulo.hpp"

namespace Passos {
    Passo::Passo(int k, double xk, double xk_1, double fxk, double fxk_1, double e1, double e2)
        : k(k), xk(xk), xk_1(xk_1), fxk(fxk), fxk_1(fxk_1), e1(e1), e2(e2) {}

    void exibirPassos(const std::string& nomeMetodo, double a3, double a2, double lambda, double epsilon, int maxIteracoes) {
        Pendulo funcaoPendulo(a3, a2);
        NewtonRaphson* metodo;

        if (nomeMetodo == "original") {
            metodo = new NewtonRaphson(maxIteracoes, epsilon, funcaoPendulo);
        }
        else if (nomeMetodo == "FL") {
            metodo = new NewtonRaphsonFL(maxIteracoes, epsilon, funcaoPendulo, lambda);
        }
        else {
            metodo = new NewtonRaphsonComDerivadaNumerica(maxIteracoes, epsilon, funcaoPendulo);
        }

        double x0 = (a3 + a2) / 2; // Valor inicial arbitrário
        metodo->calcula_raiz(x0);

        int precisaoXk = std::abs(int(log10(epsilon))) + 2;
        int precisaoFx = 2;

        // Definir largura de coluna padrão
        int colWidth = 15;

        // Imprimir cabeçalho
        if (nomeMetodo == "FL")
            std::cout << "Método: " << nomeMetodo << "(a3: " << a3 << ", a2: " << a2 << ", lambda: " << lambda << ")" << std::endl;
        else
            std::cout << "Método: " << nomeMetodo << "(a3: " << a3 << ", a2: " << a2 << ")" << std::endl;
        std::cout << std::left << std::setw(5) << "k" << "|";
        std::cout << std::setw(colWidth) << "xk" << "|";
        std::cout << std::setw(colWidth) << "xk-1" << "|";
        std::cout << std::setw(colWidth) << "f(xk)" << "|";
        std::cout << std::setw(colWidth) << "f(xk-1" << "|";
        std::cout << std::setw(colWidth) << "e1" << "|";
        std::cout << std::setw(colWidth) << "e2" << "|" << std::endl;

        double xk_1 = x0;
        for (int k = 1; k <= metodo->get_num_passos(); k++) {
            double xk = metodo->get_iteracoes_de_x()[k];
            double fxk = funcaoPendulo.get_valor_funcao(xk);
            double fxk_1 = funcaoPendulo.get_valor_funcao(xk_1);
            double e1 = std::abs(xk - xk_1);
            double e2 = std::abs(fxk);

            // Configurar alinhamento
            std::cout << std::left << std::setw(5) << std::to_string(k) << "|";
            std::cout << std::fixed << std::setprecision(precisaoXk) << std::setw(colWidth) << xk << "|";
            std::cout << std::setw(colWidth) << xk_1 << "|";
            std::cout << std::setprecision(precisaoFx) << std::setw(colWidth) << fxk << "|";
            std::cout << std::setw(colWidth) << fxk_1 << "|";
            std::cout << std::setw(colWidth) << e1 << "|";
            std::cout << std::setw(colWidth) << e2 << "|" << std::endl;

            xk_1 = xk;
        }

        delete metodo;

        //quebra de linha
        std::cout << std::endl;
    }
}