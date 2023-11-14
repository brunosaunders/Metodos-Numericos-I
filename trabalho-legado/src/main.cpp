#include <cstddef>
#include <iostream>
#include <vector> 
#include <iomanip>

#include "Painel.hpp"
#include "Polinomio.hpp"
#include "NewtonRaphsonComDerivadaNumerica.hpp"
#include "NewtonRaphsonFL.hpp"
#include "NewtonRaphson.hpp"
#include "Pendulo.hpp"
#include "Passos.hpp"
#include "Utils.hpp"
#include "QuadroComparativo.hpp"

using namespace std;
using namespace metodos_numericos1::outputs;


void testa_passos()
{
    Polinomio p = Pendulo(3, 1);
    NewtonRaphson *nr = new NewtonRaphson(100, 0.001, p);
    NewtonRaphson *nr_d = new NewtonRaphsonComDerivadaNumerica(100, 0.00001, p);
    NewtonRaphson *nr_fl = new NewtonRaphsonFL(100, 0.001, p, 0.5);


    metodos_numericos1::outputs::Passos::exibir_passos_todas_raizes(nr);
}

void gera_quadro_nr_a3_fixo_a2_variando()
{
    std::vector<NewtonRaphson *> metodos;

    for (int i = -10; i <= 10; i++) {
        Polinomio p = Pendulo(1, i);
        metodos.push_back(new NewtonRaphsonFL(100, 0.001, p, 0.05));
    }
    metodos_numericos1::outputs::QuadroComparativo::exibir_quadro(metodos);
}

void gera_quadro_nr_fl_a3_fixo_lambda_fixo_a2_variando()
{
    std::vector<NewtonRaphson *> metodos;

    for (int i = -50; i <= 10; i+=15) {
        Polinomio p = Pendulo(1, i);
        metodos.push_back(new NewtonRaphson(100, 0.001, p));
    }

    for (int i = -50; i <= 10; i+=15) {
        Polinomio p = Pendulo(1, i);
        metodos.push_back(new NewtonRaphsonFL(100, 0.001, p, 0.5));
    }

    for (int i = -50; i <= 10; i+=15) {
        Polinomio p = Pendulo(1, i);
        metodos.push_back(new NewtonRaphsonComDerivadaNumerica(100, 0.001, p));
    }
    metodos_numericos1::outputs::QuadroComparativo::exibir_quadro(metodos);
}

void gera_quadro_nr_fl_a3_variando_lambda_fixo_a2_fixo()
{
    std::vector<NewtonRaphson *> metodos;

    for (int i = -3; i <= 3; i+=1) {
        Polinomio p = Pendulo(i, 1);
        metodos.push_back(new NewtonRaphson(100, 0.001, p));
    }
    for (int i = -3; i <= 3; i+=1) {
        Polinomio p = Pendulo(i, 1);
        metodos.push_back(new NewtonRaphsonFL(100, 0.001, p, 0.3));
    }
    for (int i = -3; i <= 3; i+=1) {
        Polinomio p = Pendulo(i, 1);
        metodos.push_back(new NewtonRaphsonComDerivadaNumerica(100, 0.001, p));
    }

    metodos_numericos1::outputs::QuadroComparativo::exibir_quadro(metodos);
}

// TODO: necessário rever dado que um resultado -nan aparece
void gera_quadro_nr_d_a3_fixo_a2_variando()
{
    std::vector<NewtonRaphson *> metodos;

    for (int i = -10; i <= 10; i++) {
        Polinomio p = Pendulo(1, i);
        metodos.push_back(new NewtonRaphsonFL(100, 0.001, p, 0.05));
    }
    metodos_numericos1::outputs::QuadroComparativo::exibir_quadro(metodos);
}

void gera_quadro_a3_fixo_a2_variando() {
    std::vector<NewtonRaphson *> metodos;

    for (int i = -10; i <= 10; i++) {
        Polinomio p = Pendulo(3, i);
        metodos.push_back(new NewtonRaphsonComDerivadaNumerica(100, 0.001, p));
    }
    metodos_numericos1::outputs::QuadroComparativo::exibir_quadro(metodos);
}

void passo_a_passo_funcoes_criticas() {
    Polinomio p = Pendulo(0.3, (double)2.636/9);
    NewtonRaphson* nr = new NewtonRaphson(100, 0.0001, p);
    NewtonRaphson* nr_fl = new NewtonRaphsonFL(100, 0.0001, p, 0.35);
    NewtonRaphson* nr_d = new NewtonRaphsonComDerivadaNumerica(100, 0.0001, p);
    Passos::exibir_passos_todas_raizes(nr);
    Passos::exibir_passos_todas_raizes(nr_fl);
    Passos::exibir_passos_todas_raizes(nr_d);

    QuadroComparativo::exibir_quadro({nr, nr_fl, nr_d});
}

void funcoes_criticas_FL() {
    double n = 2.636/9;
    Polinomio p = Pendulo(0.3, 2.636/9);
    std::vector<NewtonRaphson*> nrs;
    for (int i=0; i < 200; i += 10) {
        std::cout << i << " ";
        nrs.push_back(new NewtonRaphsonFL(100, 0.0001, p, i/(double) 200));
    }
    QuadroComparativo::exibir_quadro(nrs);
}

void gera_quadro_funcoes_a3_a2_iguais() {
    std::vector<NewtonRaphson*> metodos;
    for (int i = 1; i <= 10; i++) {
        Polinomio p = Pendulo(i, i);
        metodos.push_back(new NewtonRaphson(100, 0.001, p));
    }
    for (int i = -1; i > -10; i--) {
        Polinomio p = Pendulo(i, i);
        metodos.push_back(new NewtonRaphson(100, 0.001, p));
    }
    QuadroComparativo::exibir_quadro(metodos);
}

int main()
{
    // gera_quadro_nr_d_a3_fixo_a2_variando();
    // gera_quadro_nr_fl_a3_fixo_lambda_fixo_a2_variando();
    // gera_quadro_nr_fl_a3_variando_lambda_fixo_a2_fixo();
    // gera_quadro_nr_fl_a3_variando_lambda_fixo_a2_fixo();
    // testa_passos();

    
    // Inicializa painel da aplicação;
    Painel painel;
    std::vector<NewtonRaphson*> funcoes;
    painel.init(funcoes);

    return 0;
}

   
