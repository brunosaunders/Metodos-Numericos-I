#include <iostream>

#include "Utils.hpp"

using namespace metodos_numericos1::outputs;


void Imprimir::vetor(std::vector<double> v)
{
    std::cout << "[";
    for (auto& item : v) {
        std::cout << item << " ";
    }
    std::cout << "]\n";
}

void Imprimir::matriz(std::vector<std::vector<double>> matriz) {
    int n = matriz.size();
    std::cout << "\n";

    for (auto& linha : matriz) {
        Imprimir::vetor(linha);
    }
    std::cout << "\n";
}
