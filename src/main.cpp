#include <iostream>
#include "Polinomio.hpp"
#include "NewtonRaphsonComDerivadaNumerica.hpp"
#include "NewtonRaphsonFL.hpp"
#include "NewtonRaphson.hpp"

void print_vector(std::vector<double> v) {
    std::cout << "[";
    for (auto& item : v) {
        std::cout << item << " ";
    }
    std::cout << "]\n";
}

int main() {
    Polinomio p = Polinomio({ 1.0, 0, -9.0, 3.0 }); // x³ - 9x + 3 ----> Derivada = 3x^2 - 9
    std::cout << p.get_grau() << std::endl;
    std::cout << p.get_valor_funcao(10.0) << std::endl;

    print_vector(p.get_funcao_derivada().coeficientes);

    NewtonRaphsonComDerivadaNumerica numerica(1000, 0.001, p);
    NewtonRaphsonFL fl(1000, 0.001, p, 0.05);
    NewtonRaphson original(1000, 0.001, p);

    numerica.calcula_raiz(0.5);
    fl.calcula_raiz(0.5);
    original.calcula_raiz(0.5);

    print_vector(numerica.get_iteracoes_de_x());
    print_vector(fl.get_iteracoes_de_x());
    print_vector(original.get_iteracoes_de_x());

    std::cout << numerica.get_num_passos() << std::endl;
    std::cout << fl.get_num_passos() << std::endl;
    std::cout << original.get_num_passos() << std::endl;

    std::cout << numerica.get_raiz_valida() << std::endl;
    std::cout << fl.get_raiz_valida() << std::endl;
    std::cout << original.get_raiz_valida() << std::endl;

    return 0;
}
