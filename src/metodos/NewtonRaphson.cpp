#include "NewtonRaphson.hpp"
#include <stdexcept>


NewtonRaphson::NewtonRaphson(int max_iteracoes, double erro, Polinomio funcao) {
    this->max_iteracoes = max_iteracoes;
    this->erro = erro;
    this->funcao = funcao;
    this->raiz_valida = true;
}

double NewtonRaphson::get_raiz() {
    if (!(this->raiz_valida)) {
        throw std::logic_error("Erro: raiz inválida, pois o método estorou o número máximo de iterações.");
    }

    if (this->iteracoes_de_x.size() < 1) {
        throw std::domain_error("Erro: raiz não calculada, chame calcula_raiz antes de acessar a raiz");
    }

    return this->iteracoes_de_x.back();
}

void NewtonRaphson::calcula_raiz(double x0) {
    /* TODO: Ismael */

    int k = 1;
    double x_k = 0.0, raiz = 0.0;
    bool continuar_iteracao = true;

    // Checando se o x inicial já é próximo o suficiente da raiz.
    if (std::abs(this->funcao.get_valor_funcao(x0)) < this->erro) {
        raiz = x0;
        continuar_iteracao = false;
    }

    this->iteracoes_de_x.push_back(x0);

    while (continuar_iteracao) {
        double f_x = this->funcao.get_valor_funcao(x0);
        double f_prime_x = this->funcao.get_funcao_derivada().get_valor_funcao(x0);

        x_k = x0 - (f_x / f_prime_x);
        this->iteracoes_de_x.push_back(x_k);

        /* Resultado do método é invalidado por estouro do número máximo de iterações */
        if (k > this->max_iteracoes) {
            this->raiz_valida = false;
            this->num_passos = max_iteracoes;
            return;
        }

        if ((std::abs(f_x) < this->erro) && (std::abs(x_k - x0) < this->erro)) {
            raiz = x_k;
            continuar_iteracao = false;
        }

        x0 = x_k;
        k++;
    }

    this->num_passos = this->iteracoes_de_x.size();
}
