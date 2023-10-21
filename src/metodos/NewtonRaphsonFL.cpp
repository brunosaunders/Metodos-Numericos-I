#include "NewtonRaphsonFL.hpp"
#include "NewtonRaphson.hpp"


NewtonRaphsonFL::NewtonRaphsonFL(int max_passos, double erro, Polinomio& funcao, double lambda) : NewtonRaphson(max_passos, erro, funcao) {
    this->lambda = lambda;
}

double NewtonRaphsonFL::get_lambda() const {
    return this->lambda;
}
void NewtonRaphsonFL::set_lambda(double l) {
    this->lambda = l;
}

void NewtonRaphsonFL::calcula_raiz(double x0) {
    /* TODO: Diego */
}