#include <iostream>
#include <iomanip>
#include "Vizualizador.hpp"
#include <string>
#include <cmath>
Vizualizador::Vizualizador() {}


void print_coeficientes(Polinomio polinomio,int precisao) { 
    int grau = polinomio.get_grau();
    for (int i = 0; i <= grau; i++) {
        std::cout << " a_" << grau - i << " = " << std::fixed << std::setprecision(precisao) << polinomio[i] << "\n";
    }
}

void print_cabecalho(Metodo *metodo){ 
    std::string nome_metodo = metodo->nome(-1);
    std::cout << nome_metodo << "\n\n";
    std::cout << "Número de passos: " << metodo->get_passos() << " Erro: " << metodo->get_erro() 
    << " Lambda: " << "\n\n";
    std::cout << "\tIteração\t|\t\tx\t\t|\t\tf(x)\t\n";
}

void print_linha(Polinomio polinomio,Metodo *metodo,int i,int distancia_bloco1,int distancia_bloco2,int distancia_bloco3,int precisao) { 
    double x_i = metodo->get_Tabela_x(i);
    std::cout << "\t   " << i;
    int espacamento = 3; // espacamento acima
    const int tamanho_tab = 8;

    // Imprime com precisao fixa
    std::cout << std::fixed << std::setprecision(precisao);
    std::cout << std::string(distancia_bloco1 - tamanho_tab -espacamento -std::to_string(i).size(), ' ') << "|"; 
    int parte_inteira = std::floor(x_i); 
    int tamanho_parte_inteira = std::to_string(parte_inteira).size();
    int distancia_ate_x = 15 - tamanho_parte_inteira;
    std::cout << std::string(distancia_ate_x,' ') << x_i;
    std::cout << std::string(distancia_bloco2 - distancia_ate_x -1 - (std::to_string(x_i).size() - 5 + precisao), ' ') << "|";
    std::cout << "\t       " << polinomio.p(x_i) << "\n";

    //Reseta precisão
    std::cout.unsetf(std::ios::fixed);
}

void Vizualizador::print_quadro_coeficientes_fixos(Polinomio polinomio, std::vector<Metodo*> metodos, int precisao) {
    /*Blocos:
                1                           2                                3
            Iteração        |               x               |               f(x)
    */

    const int distancia_bloco1 = 24;
    const int distancia_bloco2 = 33;
    const int distancia_bloco3 = 36;
    const int comprimento = distancia_bloco1 + distancia_bloco2 + distancia_bloco3 + 2;

    std::cout << "\n\t\tCoeficientes \n\n";
    print_coeficientes(polinomio,precisao);

    std::cout << "\n\n\t\tMétodos:\n\n";
    for (Metodo* metodo : metodos) {
        print_cabecalho(metodo);

        std::cout << std::string(comprimento, '-') << '\n';
        int num_passos = metodo->get_passos();
        for (int i = 0; i < num_passos; i++) {
            print_linha(polinomio,metodo,i,distancia_bloco1,distancia_bloco2,distancia_bloco3,precisao);
        }

        std::cout << std::string(comprimento, '-') << "\n";
    }
}
