#include <vector> 

class Polinomio { 
public:
    Polinomio(); 
    Polinomio(std::vector<double>); 
    inline int getGrau() const;
    double p(double) const; //Método que retorna P(x) 
    double derivada(double) const;
    inline Polinomio funcaoDerivada() const; 
    inline double operator[] (int i) const;//acessa o coeficiente a_i

private: 
    int grau; 
    std::vector<double> coeficientes; 
}; 