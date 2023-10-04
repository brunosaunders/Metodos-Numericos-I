#ifndef POLINOMIO_HPP
#define POLINOMIO_HPP
#include <vector> 

class Polinomio { 
public:
    Polinomio(); 
    Polinomio(std::vector<double>); 
    inline int get_grau() const;
    double p(double) const; //Método que retorna P(x) 
    inline Polinomio funcaoDerivada() const; 
    /*acessa o coeficiente a_i*/
    inline double operator[] (int i) const;

private: 
    int grau; 
    std::vector<double> coeficientes; 
}; 
#endif