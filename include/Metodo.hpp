#ifndef METODO_HPP 
#define METODO_HPP 

#include <vector>
#include <string>
class Metodo { 
public: 
    Metodo (int max_iteracoes,double erro); 
    virtual ~Metodo(); 
    void print_tabela();
    int get_passos();
    int get_max_iteracoes();
    double get_erro(); 
    double get_Tabela_x(int i) const; 
    virtual std::string nome(int) = 0;
private: 
    /*Tabela(vetor) que guarda o histórico do método, por exemplo: [x_0,x_1,...,x_n]*/
    int max_iteracoes;
    double erro;
protected: 
    int num_passos; 
    std::vector<double> tabela;
}; 
#endif