#ifndef NEWTONRAPHSON_HPP
#define NEWTONRAPHSON_HPP
#include "Polinomio.hpp"
#include "Metodo.hpp"
class NewtonRaphson:public Metodo{ 
public: 
    NewtonRaphson(int max_passos,double erro): Metodo(max_passos,erro) {}
    void original(Polinomio); 
    void modificado(Polinomio); 
    void derivada_numerica(Polinomio); 
    std::string nome(int) override; 
};
#endif