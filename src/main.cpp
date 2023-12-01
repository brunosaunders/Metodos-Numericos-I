#include <cstddef>
#include <iostream>
#include <vector> 
#include <iomanip>

#include "Gauss.hpp"
#include "Painel.hpp"
#include "Utils.hpp"
#include "GaussJordan.hpp"
#include "Cramer.hpp"


using namespace std;
using namespace metodos_numericos1::outputs;
using namespace metodos_numericos1::metodos;

void teste_matrizes_extremas() { 
    Gauss gauss({{0.1,0,0,0,0},{-1,0.1,0,0,0},{0,-1,0.1,0,0},{0,0,-1,0.1,0},{0,0,0,-1,0.1}},{1,0,0,0,1},1);
    cout  << "Matriz C e vetor v inicial: " << "\n";  
    Imprimir::matriz(gauss.get_matriz_c_inicial()); Imprimir::vetor(gauss.get_vetor_v_inicial()); 
    gauss.resolve_sistema_linear(); 
    cout << "Matriz C e vetor v resultado: " << "\n"; 
    Imprimir::matriz(gauss.get_matriz_c()); Imprimir::vetor(gauss.get_vetor_v()); 
    cout << "\n"; 
    cout << "Vetor d de deslocamentos: " << "\n"; 
    Imprimir::vetor(gauss.get_vetor_d_deslocamentos()); 
    cout << "Quebra? "; 
    cout << gauss.get_balanco_quebra() << "\n"; 

}

int main()
{
    // Painel painel;
    // vector<Gauss *> teste_gauss;

    // vector<vector<double>> matriz_c = {{0, 3, 2, 9}, {0, 3, 1, 1}, {0, 0, 2, 9}, {0, 0, 0, -2}};

    // vector<double> vetor_v = {2, 0, 12, 9};

    // Gauss* gauss = new Gauss(matriz_c, vetor_v, 2);
    // teste_gauss.push_back(gauss);
    // painel.init(teste_gauss);

    // gauss->resolve_sistema_linear();

    // GaussJordan* gauss_jordan = new GaussJordan(matriz_c, vetor_v, 2);

    // Imprimir::matriz(gauss_jordan->get_matriz_c());
    
    // cout << "Gauss-Jordan:\n";
    // gauss_jordan->resolve_sistema_linear();
    // Imprimir::vetor(gauss_jordan->get_vetor_v_inicial());
    // Imprimir::vetor(gauss_jordan->get_vetor_d_deslocamentos()); // Vetor Resposta
    // Imprimir::vetor(gauss_jordan->get_vetor_amplitudes()); // Vetor Resposta multiplicado por 'a'
    // cout << "Quebra?? -> " << gauss_jordan->get_balanco_quebra() << "\n";

    // cout << gauss_jordan->get_determinante_matriz_c() << "\n\n";

    // cout << "Cramer agora:\n";
    // Cramer* cramer = new Cramer(matriz_c, vetor_v, 2, 3);
    // cramer->resolve_sistema_linear();
    // cout << "Vetor_d_deslocamentos:\n";
    // Imprimir::vetor(cramer->get_vetor_d_deslocamentos()); // Errado no momento pois resolve_sistema_linear de Gauss não está implementado ainda.
    // cout << "Quebra?? -> " << cramer->get_balanco_quebra() << "\n";

    teste_matrizes_extremas(); 

    return 0;
}
