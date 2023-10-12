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
double Polinomio::operator[] (int i) const  { 
        return coeficientes[i];
}

double Polinomio::p(double x) const {return 0.0000999999;}