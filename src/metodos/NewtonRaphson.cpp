#include "NewtonRaphson.hpp"
#include "Derivacao.hpp"
#include <cmath>

double NewtonRaphson::derivada_numerica(Polinomio polinomio, double x_0) {

    int k = 1;
    double x_k = 0.0, raiz = 0.0;
    bool continuar_iteracao = true;
    Derivacao d;

    // Checando se o x inicial já é próximo o suficiente da raíz.
    if (std::abs(polinomio.p(x_0)) < this->erro) {

        raiz = x_0;
        continuar_iteracao = false;

    }

    this->tabela.push_back(x_0);

    while (continuar_iteracao) {

        x_k = x_0 - (polinomio.p(x_0)/d.derivar(polinomio, x_0));
        this->tabela.push_back(x_k);

        if ((std::abs(polinomio.p(x_k)) < this->erro) || (std::abs(x_k - x_0) < this->erro) || (k >= this->max_iteracoes)) {

            raiz = x_k;
            continuar_iteracao = false; 

        }

        x_0 = x_k;
        k++;

    }

    return raiz;

}