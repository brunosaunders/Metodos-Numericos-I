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


int main()
{
    /*
    Painel painel;
    vector<Gauss *> teste_gauss;

    vector<vector<double>> matriz_c = {{0, 3, 2, 9}, {0, 3, 1, 1}, {0, 0, 2, 9}, {0, 0, 0, -2}};

    vector<double> vetor_v = {2, 0, 12, 9};

    Gauss* gauss = new Gauss(matriz_c, vetor_v, 2);
    teste_gauss.push_back(gauss);
    painel.init(teste_gauss);

    gauss->resolve_sistema_linear();

    GaussJordan* gauss_jordan = new GaussJordan(matriz_c, vetor_v, 2);

    Imprimir::matriz(gauss_jordan->get_matriz_c());
    
    cout << "Gauss-Jordan:\n";
    gauss_jordan->resolve_sistema_linear();
    Imprimir::vetor(gauss_jordan->get_vetor_v_inicial());
    Imprimir::vetor(gauss_jordan->get_vetor_d_deslocamentos()); // Vetor Resposta
    Imprimir::vetor(gauss_jordan->get_vetor_amplitudes()); // Vetor Resposta multiplicado por 'a'
    cout << "Quebra?? -> " << gauss_jordan->get_balanco_quebra() << "\n";

    cout << gauss_jordan->get_determinante_matriz_c() << "\n\n";

    cout << "Cramer agora:\n";
    Cramer* cramer = new Cramer(matriz_c, vetor_v, 2, 3);
    cramer->resolve_sistema_linear();
    cout << "Vetor_d_deslocamentos:\n";
    Imprimir::vetor(cramer->get_vetor_d_deslocamentos()); // Errado no momento pois resolve_sistema_linear de Gauss não está implementado ainda.
    cout << "Quebra?? -> " << cramer->get_balanco_quebra() << "\n";
    */

    vector<vector<double>> matriz_c = {{10, 1, 1, 1}, {1, 10, 1, 1}, {1, 1, 10, 1}, {1, 1, 1, 10}};
    vector<vector<double>> matriz_c2 = {{10, 1}, {1, 10}};
    vector<vector<double>> matriz_c3 = {{10, 1, 1}, {1, 10, 1}, {1, 1, 10}};

    vector<double> vetor_v = {12, 12, 12, 12};
    vector<double> vetor_v2 = {12, 12};
    vector<double> vetor_v3 = {12, 12, 12};

    vector<Metodo *> metodos;

    metodos.push_back(new Gauss(matriz_c, vetor_v, 1));
    metodos[0]->resolve_sistema_linear();
    metodos.push_back(new Cramer(matriz_c2, vetor_v2, 1));
    metodos[1]->resolve_sistema_linear();
    metodos.push_back(new GaussJordan(matriz_c3, vetor_v3, 1));
    metodos[2]->resolve_sistema_linear();

    Painel painel;
    painel.imprimir_quadro_comparativo(metodos, 3);

    return 0;
}
