#ifndef METODO_HPP 
#define METODO_HPP 

#include <vector>
class Metodo { 
public: 
    Metodo (int max_iteracoes,double erro); 
    void print_tabela();
    int get_passos();
    
private: 
    /*Tabela(vetor) que guarda o histórico do método, por exemplo: [x_0,x_1,...,x_n]*/
    std::vector<double> tabela; 
    int max_iteracoes;
    int num_passos; 
    double erro;
}; 
#endif