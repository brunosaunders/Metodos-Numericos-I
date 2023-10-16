#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <iostream>

#include "Polinomio.hpp"

Polinomio::Polinomio() {}

Polinomio::Polinomio(std::vector<double> v) {
    this->coeficientes = v;
}

int Polinomio::get_grau() const {
    return this->coeficientes.size() - 1;
}

double Polinomio::get_valor_funcao(double x) const {
    double valor = 0;
    int grau = this->get_grau();

    for (auto& item : this->coeficientes) {
        valor += item * (std::pow(x, grau--));
    }
    return valor;
}

Polinomio Polinomio::get_funcao_derivada() const {
    std::vector<double> novos_coeficientes;
    int grau = this->get_grau();

    for (int i = 0; i < this->coeficientes.size() - 1; i++) {
        novos_coeficientes.push_back(this->coeficientes[i] * grau--);
    }

    novos_coeficientes.pop_back();

    return Polinomio(novos_coeficientes);
}

double Polinomio::operator[](int i) const {
    if (i >= 0 && i < this->coeficientes.size()) {
        return this->coeficientes[i];
    }
    else {
        // Throw an exception if the index is out of bounds
        throw std::out_of_range("Index out of bounds");
    }
}

double Polinomio::p(double x) const {return 0.0000999999;}
