#ifndef NewtonRaphson_HPP 
#define NewtonRaphson_HPP 

#include <vector>
#include "Polinomio.hpp"

class NewtonRaphson { 
public: 
    NewtonRaphson (int max_iteracoes,double erro, Polinomio funcao); 
    
    /* [x_0,x_1,...,x_n], onde x_n é a raiz encontrada*/
    std::vector<double> iteracoes_de_x; 
    Polinomio funcao;

    int max_iteracoes;
    bool raiz_valida;
    int num_passos;
    double erro;


    double get_raiz();

    /* roda o método numérico salvando informações no vetor iteracoes_de_x */
    void calcula_raiz(double x0);
}; 
#endif