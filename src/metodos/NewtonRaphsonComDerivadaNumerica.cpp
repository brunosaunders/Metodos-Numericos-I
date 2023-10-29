#include <cmath>
#include <string>
#include <iomanip>
#include <sstream>

#include "NewtonRaphsonComDerivadaNumerica.hpp"
#include "Derivacao.hpp"
#include <cmath>

void NewtonRaphsonComDerivadaNumerica::calcula_raiz(double x0) {
    int k = 1;
    double x_k = 0.0;
    bool continuar_iteracao = true;

    std::vector<double> iteracoes_de_x;

    iteracoes_de_x.push_back(x0);

    while (continuar_iteracao) {
        x_k = x0 - (this->get_funcao().get_valor_funcao(x0)/this->derivador.derivar(this->get_funcao(), x0));
        iteracoes_de_x.push_back(x_k);

        /* Resultado do método é invalidado por estouro do número máximo de iterações */
        if (k > this->get_max_iteracoes()) {
            this->set_raiz_valida(false);
            return;
        }

        if ( (std::abs(this->get_funcao().get_valor_funcao(x_k)) < this->get_erro()) && (std::abs(x_k - x0) < this->get_erro()) ) {
            continuar_iteracao = false; 
        }

        x0 = x_k;
        k++;
    }

    this->iteracoes_de_x.push_back(iteracoes_de_x);
}

std::string NewtonRaphsonComDerivadaNumerica::get_nome() {
    return "Newton Raphson Derivada Numérica";
}

std::string NewtonRaphsonComDerivadaNumerica::get_nome_abreviado() {
    return "NR-D";
}

