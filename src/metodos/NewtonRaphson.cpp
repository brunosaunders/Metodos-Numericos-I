#include "NewtonRaphson.hpp"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace metodos_numericos1::metodos;

NewtonRaphson::NewtonRaphson(int max_iteracoes, double erro, Polinomio& funcao) {
    this->max_iteracoes = max_iteracoes;
    this->erro = erro;
    this->funcao = funcao;
    this->raiz_valida = true;

    if (funcao.intervalos.size() > 0){
        this->isolamento = funcao.intervalos;
        return;
    } 

    /* Isolamento do polinomio */
    std::pair<double, double> intervalo = funcao.intervalo_max();
    int qtd_raizes = funcao.numero_raizes_reais(intervalo.first, intervalo.second);
    funcao.encontra_intervalos(intervalo.first, intervalo.second, qtd_raizes);
    this->isolamento = funcao.intervalos;
}

std::vector<std::pair<double, double>> NewtonRaphson::get_isolamento() {
    return this->isolamento;
}

int NewtonRaphson::get_max_iteracoes() const {
    return this->max_iteracoes;
}

bool NewtonRaphson::get_raiz_valida() const {
    return this->raiz_valida;
}

void NewtonRaphson::set_raiz_valida(bool r) {
    this->raiz_valida = r;
}

double NewtonRaphson::get_erro() const {
    return this->erro;
}

Polinomio& NewtonRaphson::get_funcao() {
    return this->funcao;
}

int NewtonRaphson::get_total_iteracoes() {
    int acumulador = 0;
    for (auto& iteracoes_de_x: this->iteracoes_de_x) {
        acumulador += iteracoes_de_x.size();
    }
    return acumulador;
}

double NewtonRaphson::get_media_iteracoes() {
    int total_iteracoes = this->get_total_iteracoes();
    return total_iteracoes / (double) this->iteracoes_de_x.size();
}

std::string NewtonRaphson::get_quebra() {
    if (this->quebra) return "Sim";
    return "Não";
}

std::vector<double>& NewtonRaphson::get_iteracoes_de_x(int index) {
    if (index > this->iteracoes_de_x.size()) {
        std::stringstream ss;
        ss << "Erro: essa função tem apenas " << this->iteracoes_de_x.size() << " raízes, você tentou acessar a raiz: " << index + 1 << ".\n";
        throw std::domain_error(ss.str());
    }
    return this->iteracoes_de_x[index];
}

std::vector<std::vector<double>>& NewtonRaphson::get_iteracoes_de_x_todas_raizes() {
    return this->iteracoes_de_x;
}

double NewtonRaphson::get_raiz(int index) {
    if (index > this->iteracoes_de_x.size()) {
        std::stringstream ss;
        ss << "Erro: essa função tem apenas " << this->iteracoes_de_x.size() << " raízes, você tentou acessar a raiz: " << index + 1 << ".\n";
        throw std::domain_error(ss.str());
    }
    // if (!(this->raiz_valida)) {
    //     throw std::logic_error("Erro: raiz inválida, pois o método estorou o número máximo de iterações.");
    // }

    if (this->iteracoes_de_x[index].size() < 1) {
        throw std::domain_error("Erro: raiz não calculada, chame calcula_raiz antes de acessar a raiz");
    }

    return this->iteracoes_de_x[index].back();
}

std::string NewtonRaphson::get_nome_abreviado() {
    return "NR";
}   

std::string NewtonRaphson::get_nome() {
    return "Newton Raphson";
}

void NewtonRaphson::print_isolamento() {
    std::vector<std::pair<double, double>> isolamento = this->get_isolamento();

    std::cout << "[ ";
    for (auto& item : isolamento) {
        std::cout << "[" << item.first << ", " << item.second << "] ";
    }
    std::cout << "]\n";
}

std::string NewtonRaphson::get_classe(int precisao) {
    Polinomio p = this->get_funcao();

    std::stringstream ss;
    ss << std::fixed << std::setprecision(precisao) << this->get_nome_abreviado() << "(a3: " << p[0] << ", a2: " << p[2]/9 << ", erro: " << this->get_erro() << ")";

    return ss.str();
}

double NewtonRaphson::get_lambda() {
    return 0;
}


void NewtonRaphson::calcula_raiz(double x0) {

    int k = 1;
    double x_k = x0;
    bool continuar_iteracao = true;

    std::vector<double> iteracoes_de_x;

    iteracoes_de_x.push_back(x_k);

    Polinomio f_derivada = this->funcao.get_funcao_derivada();

    while (continuar_iteracao) {
        double f_x = this->funcao.get_valor_funcao(x0);
        double f_derivada_x = f_derivada.get_valor_funcao(x0);

        x_k = x0 - (f_x / f_derivada_x);

        /* Resultado do método é invalidado por estouro do número máximo de iterações */
        if (k > this->max_iteracoes) {
            break;
        }

        iteracoes_de_x.push_back(x_k);


        if ((std::abs(f_x) < this->erro) && (std::abs(x_k - x0) < this->erro)) {
            continuar_iteracao = false;
        }

        x0 = x_k;
        k++;
    }

    this->iteracoes_de_x.push_back(iteracoes_de_x);
}

std::vector<double> NewtonRaphson::get_raizes() {
    std::vector<double> raizes;
    for (auto& item : this->iteracoes_de_x) {
        raizes.push_back(item.back());
    }
    return raizes;
}

void NewtonRaphson::calcula_raizes() {
    double fator_de_risco = 0.3;
    std::vector<double> x0s;

    if (this->iteracoes_de_x.size() != 0) {
        return;
    }

    for (auto& item : this->get_isolamento()) {
        x0s.push_back((item.first + item.second) / 2);
    }

    for (int i=0; i < x0s.size(); i++) {
        this->calcula_raiz(x0s[i]);


        if (this->get_raiz(i) >= fator_de_risco) this->quebra = true;
    }
}
