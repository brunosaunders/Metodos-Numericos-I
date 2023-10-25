#ifndef METODOS_NUMERICOS1_OUTPUTS_QUADRO_COMPARATIVO_HPP
#define METODOS_NUMERICOS1_OUTPUTS_QUADRO_COMPARATIVO_HPP 

#include <vector>
#include <iostream>

#include "Polinomio.hpp"
#include "NewtonRaphson.hpp"

namespace metodos_numericos1::outputs
{
    class QuadroComparativo {
        public:
            static void exibir_quadro(std::vector<NewtonRaphson*> metodos);
    };
}

    // class EntradasLinhaQuadroComparativo { 
    // public: 
    //     int metodo; // 0-> original, 1->FL, 2 -> Derivada
    //     double a3; 
    //     double a2; 
    //     double lambda; 
    //     double epsilon; 
    //     inline std::string get_nome_metodo(); 
    // }; 
    // class SaidasLinhaQuadroComparativo { 
    // public: 
    //     EntradasLinhaQuadroComparativo* entrada;
    //     double x_k;
    //     double e1; // erro obtido por |x_{k} - x_{k-1}|
    //     double e2; // erro obtido por |f(x_{k})|
    //     int iteracoes;  
    // };
    
    // void print_quadro_comparativo(std::vector<EntradasLinhaQuadroComparativo> linhas,int,int,double*); 
#endif
