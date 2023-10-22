#ifndef VIZUALIZADOR_HPP
#define VIZUALIZADOR_HPP 


#include "Polinomio.hpp"
#include <vector>

namespace vizualizador
{
    class EntradasLinhaQuadroComparativo { 
    public: 
        int metodo; // 0-> original, 1->FL, 2 -> Derivada
        double a3; 
        double a2; 
        double  lambda; 
        double epsilon; 
        inline std::string get_nome_metodo(); 
    }; 
    class SaidasLinhaQuadroComparativo { 
    public: 
        EntradasLinhaQuadroComparativo* entrada;
        double x_k;
        double e1; // erro obtido por |x_{k} - x_{k-1}|
        double e2; // erro obtido por |f(x_{k})|
        int iteracoes;  
    };
    void print_quadro_comparativo(std::vector<EntradasLinhaQuadroComparativo> linhas,int,int,double*) ; 
}

#endif