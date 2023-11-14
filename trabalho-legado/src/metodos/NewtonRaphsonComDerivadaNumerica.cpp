#include <cmath>
#include <string>
#include <iomanip>
#include <sstream>

#include "NewtonRaphsonComDerivadaNumerica.hpp"
#include "Derivacao.hpp"

using namespace metodos_numericos1::metodos;

void NewtonRaphsonComDerivadaNumerica::calcula_raiz(double x0) {
    int k = 1;
    double x_k = 0.0;
    bool continuar_iteracao = true;

    std::vector<double> iteracoes_de_x;

    iteracoes_de_x.push_back(x0);

    while (continuar_iteracao) {
        x_k = x0 - (this->get_funcao().get_valor_funcao(x0)/this->derivador.derivar(this->get_funcao(), x0));

        /* Resultado do método é invalidado por estouro do número máximo de iterações */
        if (k > this->get_max_iteracoes()) {
            break;
        }

        iteracoes_de_x.push_back(x_k);

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

std::string NewtonRaphsonComDerivadaNumerica::get_classe(int precision) {
    Polinomio p = this->get_funcao();

    std::stringstream ss;
    ss << std::fixed << std::setprecision(precision) << this->get_nome_abreviado() << "(a3: " << p[0] << ", a2: " << p[2]/-9 << ", erro: " << this->get_erro() << ")";

    return ss.str();
}