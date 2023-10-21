#include "NewtonRaphson.hpp"
/*Função temporária: TODO:Ajustar com macros*/
std::string NewtonRaphson::nome(int tipo_de_derivacao)  { 
   if (tipo_de_derivacao == 0) return std::string("Newton Rhapson com Derivação Progressiva"); 
   if (tipo_de_derivacao == 1) return std::string("Newton Rhapson com Derivação Centrada"); 
   if (tipo_de_derivacao == 2) return std::string("Newton Rhapson com Derivação Centrada"); 
   return std::string("Newton Rhapson"); 
}
/*Temporaria*/
void NewtonRaphson::original(Polinomio polinomio){ 
   num_passos = 5; 
   tabela.push_back(1111.16); 
   tabela.push_back(1.1);
   tabela.push_back(1.200);
   tabela.push_back(1.9998);
   tabela.push_back(1222222.99999999);

}
void NewtonRaphson::derivada_numerica(Polinomio polinomio){
   num_passos = 222; 
   for (int i = 0; i < num_passos; i ++) 
      tabela.push_back(123.0);
} 
void NewtonRaphson::modificado(Polinomio polinomio){
   num_passos = 5; 
   tabela.push_back(13311.16); 
   tabela.push_back(3222.1);
   tabela.push_back(3.200);
   tabela.push_back(3.9998);
   tabela.push_back(3333222000.213);
} 
