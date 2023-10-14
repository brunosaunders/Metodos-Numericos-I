#include "NewtonRaphsonComDerivadaNumerica.hpp"
#include "Derivacao.hpp"
#include <cmath>

void NewtonRaphsonComDerivadaNumerica::calcula_raiz(double x0) {
    int k = 1;
    double x_k = 0.0, raiz = 0.0;
    bool continuar_iteracao = true;

    // Checando se o x inicial já é próximo o suficiente da raíz.
    if (std::abs(this->funcao.p(x0)) < this->erro) {

        raiz = x0;
        continuar_iteracao = false;
    }

    this->iteracoes_de_x.push_back(x0);

    while (continuar_iteracao) {

        x_k = x0 - (this->funcao.p(x0)/this->derivador.derivar(this->funcao, x0));
        this->iteracoes_de_x.push_back(x_k);

        if ((std::abs(this->funcao.p(x_k)) < this->erro) || (std::abs(x_k - x0) < this->erro) || (k >= this->max_iteracoes)) {

            raiz = x_k;
            continuar_iteracao = false; 

        }

        x0 = x_k;
        k++;
    }

    this->num_passos = this->iteracoes_de_x.size();
}