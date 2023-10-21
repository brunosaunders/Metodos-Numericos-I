#include <iostream>
#include "Polinomio.hpp"
#include "NewtonRaphsonComDerivadaNumerica.hpp"
#include "NewtonRaphsonFL.hpp"

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
    std::pair<double, double> interval = p.intervalo_max(p.coeficientes);
    p.encontra_intervalos(interval.first, interval.second);

    for (const auto& root : p.intervalos) {
        std::cout << "Raiz no intervalo [" << root.first << ", " << root.second << "]\n";
    }    
    print_vector(p.get_funcao_derivada().coeficientes);

    NewtonRaphsonComDerivadaNumerica numerica(1000, 0.001, p);
    NewtonRaphsonFL fl(1000, 0.001, p, 0.05);

    numerica.calcula_raiz(0.5);
    fl.calcula_raiz(0.5);

    print_vector(numerica.get_iteracoes_de_x());
    print_vector(fl.get_iteracoes_de_x());

    return 0;
}
