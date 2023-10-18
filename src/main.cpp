#include <iostream>
#include "Polinomio.hpp"
#include "NewtonRaphson.hpp"

void print_vector(std::vector<double> v) {
    std::cout << "[";
    for (auto &item : v) {
        std::cout << item << " ";
    }
    std::cout << "]\n";
}

int main() {
    std::vector<double> coef = {-2, 1, 1}; // Cria um vetor de coeficientes para o polinômio com a3 = 1, a2 = 1 e a1 = -2
    Polinomio p(coef); // Cria um polinômio usando o vetor de coeficientes
    NewtonRaphson nr(10, 0.001, p); // Cria um objeto da classe NewtonRaphson com os parâmetros dados com max_iteracoes = 10, erro = 0.001 e funcao = p
    nr.calcula_raiz(0.5); // Calcula a raiz da função usando o método de Newton-Raphson com x0 = 0.5
    std::cout << "A raiz encontrada foi: " << nr.get_raiz() << std::endl; // Imprime a raiz encontrada
    return 0;
}
