#include "NewtonRaphson.hpp"
#include <stdexcept>


NewtonRaphson::NewtonRaphson(int max_iteracoes, double erro, Polinomio funcao) {
    this->max_iteracoes = max_iteracoes;
    this->erro = erro;
    this->funcao = funcao;
}

double NewtonRaphson::get_raiz() {
    if (this->iteracoes_de_x.size() < 1) {
        throw std::domain_error("Erro: raiz não calculada, chame calcula_raiz antes de acessar a raiz");
    }

    return this->iteracoes_de_x.back();
}

void NewtonRaphson::calcula_raiz(double x0) {
    /* TODO: Ismael */
}
