#include <vector>
class Metodos { 
public: 
    void printTabela();
    int getPassos();
    

private: 
    std::vector<double> tabela; 
    int maxIteracoes;
    int numPassos; 
    double erro;
}; 