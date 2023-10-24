#include "NewtonRaphson.hpp"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <iomanip>


NewtonRaphson::NewtonRaphson(int max_iteracoes, double erro, Polinomio& funcao) {
    this->set_max_iteracoes(max_iteracoes);
    this->set_erro(erro);
    this->set_funcao(funcao);
    this->set_raiz_valida(true);
}

int NewtonRaphson::get_max_iteracoes() const {
    return this->max_iteracoes;
}

void NewtonRaphson::set_max_iteracoes(int m) {
    this->max_iteracoes = m;
}

bool NewtonRaphson::get_raiz_valida() const {
    return this->raiz_valida;
}

void NewtonRaphson::set_raiz_valida(bool r) {
    this->raiz_valida = r;
}

int NewtonRaphson::get_num_passos() const {
    return this->num_passos;
}

void NewtonRaphson::set_num_passos(int n) {
    this->num_passos = n;
}

double NewtonRaphson::get_erro() const {
    return this->erro;
}

void NewtonRaphson::set_erro(double e) {
    this->erro = e;
}

Polinomio& NewtonRaphson::get_funcao() {
    return this->funcao;
}

void NewtonRaphson::set_funcao(Polinomio& f) {
    this->funcao = f;
}

std::vector<double>& NewtonRaphson::get_iteracoes_de_x() {
    return this->iteracoes_de_x;
}
void NewtonRaphson::set_iteracoes_de_x(std::vector<double>& i) {
    this->iteracoes_de_x = i;
}

double NewtonRaphson::get_raiz() {
    if (!(this->raiz_valida)) {
        throw std::logic_error("Erro: raiz inválida, pois o método estorou o número máximo de iterações.");
    }

    if (this->iteracoes_de_x.size() < 1) {
        throw std::domain_error("Erro: raiz não calculada, chame calcula_raiz antes de acessar a raiz");
    }

    return this->iteracoes_de_x.back();
}

std::string NewtonRaphson::get_nome_abreviado() {
    return "NR";
}   

std::string NewtonRaphson::get_nome() {
    return "Newton Raphson";
}

std::string NewtonRaphson::get_classe(int precisao) {
    Polinomio p = this->get_funcao();

    std::stringstream ss;
    ss << std::fixed << std::setprecision(precisao) << this->get_nome_abreviado() << "(a3: " << p[0] << ", a2: " << p[2]/9 << ", erro: " << this->get_erro() << ")";

    return ss.str();
}


void NewtonRaphson::calcula_raiz(double x0) {
    int k = 1;
    double x_k = x0;
    bool continuar_iteracao = true;

    this->iteracoes_de_x.push_back(x_k);

    Polinomio f_derivada = this->funcao.get_funcao_derivada();

    while (continuar_iteracao) {
        double f_x = this->funcao.get_valor_funcao(x0);
        double f_derivada_x = f_derivada.get_valor_funcao(x0);

        x_k = x0 - (f_x / f_derivada_x);
        this->iteracoes_de_x.push_back(x_k);

        /* Resultado do método é invalidado por estouro do número máximo de iterações */
        if (k > this->max_iteracoes) {
            this->raiz_valida = false;
            this->num_passos = this->max_iteracoes;
            return;
        }

        if ((std::abs(f_x) < this->erro) && (std::abs(x_k - x0) < this->erro)) {
            continuar_iteracao = false;
        }

        x0 = x_k;
        k++;
    }

    this->num_passos = this->iteracoes_de_x.size();
}

