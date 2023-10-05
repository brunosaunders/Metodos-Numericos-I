#include <vector>
#include "Polinomio.hpp"

Polinomio::Polinomio() {}

Polinomio::Polinomio(std::vector<double> v) {
    this->grau = v.size() - 1;
    this->coeficientes = v;
}

int Polinomio::get_grau() const {
    return this->grau;
}