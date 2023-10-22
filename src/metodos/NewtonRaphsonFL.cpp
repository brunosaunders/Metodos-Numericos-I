#include "NewtonRaphsonFL.hpp"
#include "NewtonRaphson.hpp"
#include <cmath>

NewtonRaphsonFL::NewtonRaphsonFL(int max_passos, double erro, Polinomio& funcao, double lambda) : NewtonRaphson(max_passos, erro, funcao) {
    this->lambda = lambda;
}

double NewtonRaphsonFL::get_lambda() const {
    return this->lambda;
}
void NewtonRaphsonFL::set_lambda(double l) {
    this->lambda = l;
}

void NewtonRaphsonFL::calcula_raiz(double x0) {
    int k = 1;
    double xk = x0;
    bool continuar = true;

    //Primeiro, adicionamos xk no vector de itera��es
    this->get_iteracoes_de_x().push_back(xk);

    //Calculando a derivada da fun��o
    Polinomio derivada = this->get_funcao().get_funcao_derivada();

    //Inicialmente xw = x0, pois ambos pontos se jogados na fun��o derivada possuem m�dulo >= lambda
    double xw = x0;

    while (continuar) {
        //Verificar se j� passamos do limite de passos(numero m�ximo)
        if (k > this->get_max_iteracoes()) {
            //N�o temos raiz v�lida
            continuar = false;
            this->set_raiz_valida(false);
            this->set_num_passos(this->get_max_iteracoes());
            return;
        }

        //Caso contr�rio, iremos nos preocupar com a pr�xima aproxima��o
        if (std::abs(derivada.get_valor_funcao(xk)) > this->get_lambda()) {
            xk = xk - (this->get_funcao().get_valor_funcao(xk) / derivada.get_valor_funcao(xk));
        }
        else {
            xk = xk - (this->get_funcao().get_valor_funcao(xk) / derivada.get_valor_funcao(xw));
        }

        //Verificar se atualizo o xw ou n�o
        if (std::abs(derivada.get_valor_funcao(xk)) >= this->get_lambda()) {
            //Atualizo o xw
            xw = xk;
        }

        //Verificar se atendemos a condi��o de parada
        if ((std::abs(this->get_funcao().get_valor_funcao(xk)) < this->get_erro()) && (std::abs(xk - (this->get_iteracoes_de_x().back())) < this->get_erro())) {
            continuar = false;
            this->set_raiz_valida(true);
            this->set_num_passos(k);
        }

        //Acrescentamos a nova aproxima��o no vector de itera��es
        this->get_iteracoes_de_x().push_back(xk);

        //Incrementar o k
        k++;
    }
}