#include "Metodo.hpp"

 /*Implementações temporarias*/
 Metodo::Metodo (int max_iteracoes,double erro){ 
    this->max_iteracoes = max_iteracoes; 
    this->erro = erro; 
 }

 int Metodo::get_max_iteracoes() {
    return max_iteracoes; 
}
int Metodo::get_passos() { return num_passos;}

double Metodo::get_erro() { return erro; }

Metodo::~Metodo()  {};

double Metodo::get_Tabela_x(int i) const { 
   if (i <= num_passos) { 
      return tabela[i];
   }
   return -1;
}  

/****/