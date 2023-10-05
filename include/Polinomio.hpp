#ifndef POLINOMIO_HPP
#define POLINOMIO_HPP
#include <vector> 

class Polinomio { 
public:
    Polinomio(); 
    Polinomio(std::vector<double>); 
    int get_grau() const;
    double p(double) const; //Método que retorna P(x) 
    Polinomio funcao_derivada() const;

    /*acessa o coeficiente a_i*/
    double operator[] (int i) const;

private: 
    int grau; 
    std::vector<double> coeficientes; 
}; 
#endif
