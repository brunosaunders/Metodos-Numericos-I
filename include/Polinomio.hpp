#ifndef POLINOMIO_HPP
#define POLINOMIO_HPP
#include <vector> 

class Polinomio { 
public:
    Polinomio(); 
    Polinomio(std::vector<double> coeficientes); 

    int get_grau() const;
    double get_valor_funcao(double x) const; // Método que retorna P(x) 
    std::vector<double> coeficientes; 

    Polinomio get_funcao_derivada() const;

    /*acessa o coeficiente a_i*/
    double operator[] (int i) const;

    bool tem_mais_raiz(double a, double b);

    void encontra_intervalos(double a, double b);
    
    Polinomio divide(Polinomio p);

    Polinomio divide(double valor);

    Polinomio multiplica(double valor);

    Polinomio soma(Polinomio p);

    Polinomio subtrai(Polinomio p);

    std::pair<double, double> intervalo_max(std::vector<double> coef);

    std::vector<std::pair<double, double>> intervalos;
}; 
#endif
