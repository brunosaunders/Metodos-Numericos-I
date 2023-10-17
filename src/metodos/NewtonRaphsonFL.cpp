#include "NewtonRaphsonFL.hpp"
#include "NewtonRaphson.hpp"


NewtonRaphsonFL::NewtonRaphsonFL(int max_passos, double erro, Polinomio funcao, double lambda) : NewtonRaphson(max_passos, erro, funcao) {
    this->lambda = lambda;
}

void NewtonRaphsonFL::calcula_raiz(double x0) {
    /* TODO: Diego */
}