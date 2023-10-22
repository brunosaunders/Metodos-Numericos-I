#include "NewtonRaphson.hpp"
#include <stdexcept>


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

void NewtonRaphson::calcula_raiz(double x0) {
    /* TODO: Ismael */
}
#include "NewtonRaphson.hpp"
/*Função temporária: TODO:Ajustar com macros*/
std::string NewtonRaphson::nome(int tipo_de_derivacao)  { 
   if (tipo_de_derivacao == 0) return std::string("Newton Rhapson com Derivação Progressiva"); 
   if (tipo_de_derivacao == 1) return std::string("Newton Rhapson com Derivação Centrada"); 
   if (tipo_de_derivacao == 2) return std::string("Newton Rhapson com Derivação Centrada"); 
   return std::string("Newton Rhapson"); 
}
/*Temporaria*/
void NewtonRaphson::original(Polinomio polinomio){ 
   num_passos = 5; 
   tabela.push_back(1111.16); 
   tabela.push_back(1.1);
   tabela.push_back(1.200);
   tabela.push_back(1.9998);
   tabela.push_back(1222222.99999999);

}
void NewtonRaphson::derivada_numerica(Polinomio polinomio){
   num_passos = 222; 
   for (int i = 0; i < num_passos; i ++) 
      tabela.push_back(123.0);
} 
void NewtonRaphson::modificado(Polinomio polinomio){
   num_passos = 5; 
   tabela.push_back(13311.16); 
   tabela.push_back(3222.1);
   tabela.push_back(3.200);
   tabela.push_back(3.9998);
   tabela.push_back(3333222000.213);
} 
