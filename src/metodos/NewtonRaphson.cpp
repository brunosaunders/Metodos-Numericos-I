#include "NewtonRaphson.hpp"
#include <stdexcept>

double NewtonRaphson::derivada_numerica(Polinomio polinomio, double x, double h, int metodo) {

    double res = 0.0;

    if (metodo == DERIVACAO_REGRESSIVA) {

        res = (polinomio.p(x-h) - polinomio.p(x))/(-h);

    } else if (metodo == DERIVACAO_CENTRADA) {

        res = (polinomio.p(x+h) - polinomio.p(x-h))/(2*h);

    } else if (metodo == DERIVACAO_PROGRESSIVA) {

        res = (polinomio.p(x+h) - polinomio.p(x))/h;

    } else {

        throw std::invalid_argument("Erro: O parâmetro \"metodo\" de NewtonRaphson::derivada_numerica recebeu um valor invalido! Os possíveis valores válidos são: DERIVACAO_REGRESSIVA, DERIVACAO_CENTRADA e DERIVACAO_PROGRESSIVA.");

    }

    return res;

}