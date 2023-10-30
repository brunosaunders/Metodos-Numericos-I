#include <stdexcept>

#include "Pendulo.hpp"
#include "Polinomio.hpp"

using namespace metodos_numericos1::funcoes;

Pendulo::Pendulo(double a3, double a2) {
    if (a3 == 0 && a2 == 0) {
        throw std::invalid_argument("a3 e a2 não podem ser 0 ao mesmo tempo!");
    }
    this->coeficientes = {a3, 0, -9*a2, 3};
}
