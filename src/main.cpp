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
    Polinomio p = Pendulo(1, -1);
    NewtonRaphson *nr = new NewtonRaphson(100, 0.001, p);
    NewtonRaphson *nr_d = new NewtonRaphsonComDerivadaNumerica(100, 0.00001, p);

    metodos_numericos1::outputs::Passos::exibir_passos_todas_raizes(nr);
}

void testa_polinomios()
{
    Polinomio p = Pendulo(1, -1);

    for (const auto &root : p.intervalos)
    {
        std::cout << "Raiz no intervalo [" << root.first << ", " << root.second << "]\n";
    }
    std::cout << "eae\n";
}

void testa_divisao()
{
    Polinomio p = Pendulo(1, -1);
    Polinomio p_deriv = p.get_funcao_derivada();
    p.print();
    p_deriv.print();

    Polinomio p_div = p.divide(p_deriv);
    p_div.print();

    Polinomio p_div2 = p_deriv.divide(p_div);
    p_div2.print();
}
void testa_quadro_comparativo()
{
    std::vector<NewtonRaphson *> metodos;

    Polinomio p = Pendulo(1, 1);
    Polinomio p2 = Pendulo(-52, 2);
    Polinomio p3 = Pendulo(5, 2);

    metodos.push_back(new NewtonRaphson(100, 0.001, p));
    metodos.push_back(new NewtonRaphsonFL(100, 0.001, p, 0.5));
    metodos.push_back(new NewtonRaphsonComDerivadaNumerica(100, 0.001, p));

    metodos.push_back(new NewtonRaphson(100, 0.001, p2));
    metodos.push_back(new NewtonRaphsonFL(100, 0.001, p2, 0.5));
    metodos.push_back(new NewtonRaphsonComDerivadaNumerica(100, 0.001, p2));

    metodos.push_back(new NewtonRaphson(100, 0.001, p3));
    metodos.push_back(new NewtonRaphsonFL(100, 0.001, p3, 0.5));
    metodos.push_back(new NewtonRaphsonComDerivadaNumerica(100, 0.001, p3));

    metodos_numericos1::outputs::QuadroComparativo::exibir_quadro(metodos);
}

void testa_isolamento()
{
    Polinomio p = Pendulo(1, -1);
    std::cout << p.numero_raizes_reais(-3.16, 2.82);
}

int main()
{
    // testa_polinomios();

    // testa_isolamento();
    // testa_divisao();
    
    // testa_quadro_comparativo();
    // testa_passos();

    // Inicializa painel da aplicação;
    Painel painel;
    std::vector<NewtonRaphson*> funcoes;
    painel.init(funcoes);

    return 0;
}

   
