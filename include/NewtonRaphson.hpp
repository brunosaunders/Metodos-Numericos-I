#ifndef NewtonRaphson_HPP 
#define NewtonRaphson_HPP 

#include <vector>
#include <string>

#include "Polinomio.hpp"

class NewtonRaphson { 
private:
    int max_iteracoes;
    bool raiz_valida;
    int num_passos;
    double erro;
    Polinomio funcao; 
    std::vector<double> isolamento_raizes;

protected:
    /* [x_0,x_1,...,x_n], onde x_n é a raiz encontrada*/
    std::vector<std::vector<double>> iteracoes_de_x;

public: 
    NewtonRaphson (int max_iteracoes,double erro, Polinomio& funcao); 

    virtual ~NewtonRaphson() {}

    int get_max_iteracoes() const;
    void set_max_iteracoes(int m);

    bool get_raiz_valida() const;
    void set_raiz_valida(bool r);

    double get_erro() const;
    void set_erro(double e);

    Polinomio& get_funcao();
    void set_funcao(Polinomio& f);

    std::vector<double>& get_iteracoes_de_x(int index);
    std::vector<std::vector<double>>& get_iteracoes_de_x_todas_raizes();

    double get_raiz(int index);

    virtual std::string get_nome();
    virtual std::string get_nome_abreviado();
    virtual std::string get_classe(int precisao);

    virtual double get_lambda();
    void calcula_raizes();
private:
    /* roda o método numérico salvando informações no vetor iteracoes_de_x */
    virtual void calcula_raiz(double x0);

}; 
#endif
