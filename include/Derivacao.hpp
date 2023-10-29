#ifndef DERIVADANUMERICA_HPP
#define DERIVADANUMERICA_HPP

#include "Polinomio.hpp"

// Macros para definir qual método usar no cálculo da derivada numérica.
#define DERIVACAO_REGRESSIVA 0
#define DERIVACAO_CENTRADA 1
#define DERIVACAO_PROGRESSIVA 2

using namespace metodos_numericos1::include;

class Derivacao {

    public:
        Derivacao();

        /*
            Retorna a derivada numérica de uma função qualquer num ponto x, com passo h, utilizando o método especificado.
            O método padrão utilizado é o DERIVACAO_CENTRADA, pois esse é o mais preciso em geral.
        */
        double derivar(double (*fn)(double), double x, double h = 1.0e-10, int metodo = DERIVACAO_CENTRADA);

        /*
            Retorna a derivada numérica de um Polinômio num ponto x, com passo h, utilizando o método especificado.
            O método padrão utilizado é o DERIVACAO_CENTRADA, pois esse é o mais preciso em geral. O valor padrão para 
        */
        double derivar(Polinomio polinomio, double x, double h = 1.0e-10, int metodo = DERIVACAO_CENTRADA);

};

#endif
