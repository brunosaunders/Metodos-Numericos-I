#include <cstddef>
#include <iostream>
#include <vector> 
#include <iomanip>

#include "Painel.hpp"
#include "Utils.hpp"
#include "GaussJordan.hpp"


using namespace std;
using namespace metodos_numericos1::outputs;
using namespace metodos_numericos1::metodos;


int main()
{
    Painel painel;
    vector<vector<double>> matriz_c = {{1, 3, 2, 9}, {0, 3, 1, 1}, {0, 0, 2, 9}, {0, 0, 0, -2}};

    vector<double> vetor_v = {2, 0, 12, 9};

    GaussJordan* gauss_jordan = new GaussJordan(matriz_c, vetor_v, 2);

    gauss_jordan->resolve_sistema_linear();
    Imprimir::vetor(gauss_jordan->get_vetor_v());
    Imprimir::vetor(gauss_jordan->get_vetor_v_inicial());

    Imprimir::matriz(gauss_jordan->get_matriz_c());
    return 0;
}