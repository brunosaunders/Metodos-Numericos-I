#ifndef NEWTONRAPHSON_HPP
#define NEWTONRAPHSON_HPP
#include "Polinomio.hpp"
#include "Metodo.hpp"

// Macros para a derivada numérica.
#define DERIVACAO_REGRESSIVA 0
#define DERIVACAO_CENTRADA 1
#define DERIVACAO_PROGRESSIVA 2 

class NewtonRaphson:public Metodo{ 
    public:
        NewtonRaphson(int max_passos,double erro): Metodo(max_passos,erro) {}
        void original(Polinomio); 
        void modificado(Polinomio); 
        /*
            Retorna a derivada numérica de um polinômio num ponto x, com passo h, utilizando o método especificado.
            O método padrão utilizado é o DERIVACAO_CENTRADA, pois esse é o mais preciso em geral.
        */
        double derivada_numerica(Polinomio polinomio, double x, double h, int metodo = DERIVACAO_CENTRADA); 
};
#endif