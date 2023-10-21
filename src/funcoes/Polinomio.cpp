#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <utility>
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

bool Polinomio::tem_mais_raiz(double a, double b) {
    return (get_valor_funcao(a) * get_valor_funcao(b) <= 0);
}

void Polinomio::encontra_intervalos(double a, double b) {
    double epsilon = 1;
    if (fabs(b - a) < epsilon) {
        intervalos.push_back(std::make_pair(a, b));
    } else {
        double meio = (a + b) / 2;
        if (tem_mais_raiz(a, meio) || fabs(a - meio) >= epsilon) {
            encontra_intervalos(a, meio);
        } 
        if (tem_mais_raiz(meio, b) || (fabs(meio - b) >= epsilon)) {
            encontra_intervalos(meio, b);
        }
    }
}

std::pair<double, double> Polinomio::intervalo_max(std::vector<double> coeficientes) {
    std::reverse(coeficientes.begin(), coeficientes.end());
    int n = coeficientes.size() - 1;
    std::vector<double> values;
    for (size_t i = 0; i < n; i++) {
        values.push_back((fabs(coeficientes[i])/fabs(coeficientes[n])));
    }
    double raio_max = *max_element(values.begin(), values.end()) + 1;
    return std::make_pair(-raio_max, raio_max);
}
