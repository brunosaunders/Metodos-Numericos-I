#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <utility>
#include <vector>

#include "Polinomio.hpp"

using namespace metodos_numericos1::include;

Polinomio::Polinomio() {}

Polinomio::Polinomio(std::vector<double> v) {
  std::vector<double> results;
  int i = 0;
  int size = v.size();
  while (i < size && v[i] == 0) {
    i++;
  }

  for (int j = i; j < size; j++) {
    results.push_back(v[j]);
  }

  this->coeficientes = results;
}

int Polinomio::get_grau() const {
  int size = this->coeficientes.size();
  return size - 1;
}

double Polinomio::get_valor_funcao(double x) const {
  double valor = 0;
  int grau = this->get_grau();

  for (auto &item : this->coeficientes) {
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
  } else {
    // Throw an exception if the index is out of bounds
    throw std::out_of_range("Index out of bounds");
  }
}

double Polinomio::p(double x) const { return 0.0000999999; }

bool Polinomio::tem_mais_raiz(double a, double b) {
  return (get_valor_funcao(a) * get_valor_funcao(b) <= 0);
}

void Polinomio::encontra_intervalos(double inicio, double fim, int n_raizes) {
  double epsilon = 1;
  if (fabs(fim - inicio) <= epsilon && n_raizes < 2) {
    intervalos.push_back(std::make_pair(inicio, fim));
    return;
  }

  double meio = (inicio + fim) / 2;
  int raizes_a_meio = this->numero_raizes(inicio, meio);
  int raizes_meio_fim = this->numero_raizes(meio, fim);

  if (raizes_a_meio > 0) {
    this->encontra_intervalos(inicio, meio, raizes_a_meio);
  }
  if (raizes_meio_fim > 0) {
    this->encontra_intervalos(meio, fim, raizes_meio_fim);
  }
}

std::pair<double, double> Polinomio::intervalo_max() {
  std::vector<double> values;
  std::reverse(this->coeficientes.begin(), this->coeficientes.end());
  int n = this->coeficientes.size() - 1;
  for (size_t i = 0; i < n; i++) {
    values.push_back(
        (fabs(this->coeficientes[i]) / fabs(this->coeficientes[n])));
  }
  double raio_max = *max_element(values.begin(), values.end()) + 1;
  return std::make_pair(-raio_max, raio_max);
}

Polinomio Polinomio::multiplica(double valor) {
  std::vector<double> result = this->coeficientes;

  for (int i = 0; i < result.size(); i++) {
    result[i] *= valor;
  }
  return Polinomio(result);
}

Polinomio Polinomio::divide(double valor) {
  return this->multiplica(1 / valor);
}

Polinomio Polinomio::soma(Polinomio p) {
  int this_grau = this->get_grau();
  int other_grau = p.get_grau();

  if (this_grau == -1 || other_grau == -1) {
    return Polinomio(this->coeficientes);
  }

  if (other_grau < this_grau) {
    int distance = this_grau - other_grau;
    std::vector<double> results = this->coeficientes;

    for (int i = 0; i < this_grau + 1; i++) {
      results[i + distance] += p.coeficientes[i];
    }
    return Polinomio(results);
  }

  int distance = other_grau - this_grau;
  std::vector<double> results = p.coeficientes;

  for (int i = 0; i < this_grau + 1; i++) {
    results[i + distance] += this->coeficientes[i];
  }
  return Polinomio(results);
}

Polinomio Polinomio::subtrai(Polinomio p) {
  Polinomio other = p.multiplica(-1);
  return this->soma(other);
}

void Polinomio::print() {
  std::cout << "P(";
  for (auto &item : this->coeficientes) {
    std::cout << item << " ";
  }
  std::cout << ")\n";
}

Polinomio Polinomio::multiplica(Polinomio p) {
  std::vector<double> result;
  int this_grau = this->get_grau();
  int other_grau = p.get_grau();

  int novo_grau = this->get_grau() + p.get_grau();

  for (int i = 0; i < novo_grau + 1; i++) {
    result.push_back(0);
  }

  for (int i = 0; i < this_grau + 1; i++) {
    for (int j = 0; j < other_grau + 1; j++) {
      result[i + j] += this->coeficientes[i] * p.coeficientes[j];
    }
  }

  return Polinomio(result);
}

Polinomio Polinomio::divide(Polinomio p) {
  int this_grau = this->get_grau();
  int other_grau = p.get_grau();

  if (this_grau == 0 || other_grau == 0) {
    throw std::invalid_argument("Polinômio inválido!");
  }

  if (other_grau > this_grau) {
    throw std::invalid_argument(
        "Grau do denominador é maior que o do numerador!");
  }

  Polinomio resto = Polinomio(this->coeficientes);

  while (resto.get_grau() >= other_grau) {
    int distancia = resto.get_grau() - other_grau;
    std::vector<double> divisor_inteiro;

    double r = resto.coeficientes[0] / p.coeficientes[0];

    divisor_inteiro.push_back(r);
    for (int i = 0; i < distancia; i++) {
      divisor_inteiro.push_back(0);
    }
    Polinomio p_divisor_inteiro = Polinomio(divisor_inteiro);

    Polinomio p_subtraindo = p.multiplica(p_divisor_inteiro);

    resto = resto.subtrai(p_subtraindo);
  }

  return resto;
}

int Polinomio::numero_raizes(double a, double b) {
  if (a > b) {
    throw std::invalid_argument("a maior que b");
  }
  std::vector<Polinomio> sequencia;
  sequencia.push_back(*this);
  sequencia.push_back(this->get_funcao_derivada());

  Polinomio p_anterior = sequencia[0];
  Polinomio p_atual = sequencia[1];

  while (p_atual.get_grau() > 0) {
    Polinomio p_temp = p_anterior;
    p_anterior = p_atual;
    p_atual = (p_temp.divide(p_atual)).multiplica(-1);
    sequencia.push_back(p_atual);
  }
  std::vector<double> valores_a;
  std::vector<double> valores_b;

  for (auto &polinomio : sequencia) {
    valores_a.push_back(polinomio.get_valor_funcao(a));
    valores_b.push_back(polinomio.get_valor_funcao(b));
  }

  int mudancas_a = 0;
  for (int i = 1; i < valores_a.size(); i++) {
    if (valores_a[i] >= 0 && valores_a[i - 1] < 0) {
      mudancas_a++;
    } else if (valores_a[i - 1] >= 0 && valores_a[i] < 0) {
      mudancas_a++;
    }
  }

  int mudancas_b = 0;
  for (int i = 1; i < valores_b.size(); i++) {
    if (valores_b[i] >= 0 && valores_b[i - 1] < 0) {
      mudancas_b++;
    } else if (valores_b[i - 1] >= 0 && valores_b[i] < 0) {
      mudancas_b++;
    }
  }

  return mudancas_a - mudancas_b;
}
