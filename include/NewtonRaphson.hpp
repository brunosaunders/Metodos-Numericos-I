#ifndef NewtonRaphson_HPP 
#define NewtonRaphson_HPP 

#include <vector>
#include "Polinomio.hpp"

class NewtonRaphson { 
private:
    int max_iteracoes;
    bool raiz_valida;
    int num_passos;
    double erro;
    Polinomio funcao; 

public: 
    /* [x_0,x_1,...,x_n], onde x_n é a raiz encontrada*/
    std::vector<double> iteracoes_de_x;

    NewtonRaphson (int max_iteracoes,double erro, Polinomio funcao); 

    int get_max_iteracoes() const;
    void set_max_iteracoes(int m);

    bool get_raiz_valida() const;
    void set_raiz_valida(bool r);

    int get_num_passos() const;
    void set_num_passos(int n);

    double get_erro() const;
    void set_erro(double e);

    Polinomio get_funcao() const;
    void set_funcao(Polinomio f);

    double get_raiz();

    /* roda o método numérico salvando informações no vetor iteracoes_de_x */
    void calcula_raiz(double x0);
}; 
#endif