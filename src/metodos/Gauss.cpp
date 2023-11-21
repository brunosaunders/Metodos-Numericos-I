#include "Gauss.hpp"

using namespace std;
using namespace metodos_numericos1::metodos;

void Gauss::resolve_sistema_linear() {
    return;
}


vector<double> Gauss::get_vetor_v() {
    return this->vetor_v;
}

vector<double> Gauss::get_vetor_v_inicial() {
    return this->vetor_v_inicial;
}

vector<vector<double>> Gauss::get_matriz_c() {
    return this->matriz_c;
}

vector<vector<double>> Gauss::get_matriz_c_inicial() {
    return this->matriz_c_inicial;
}

void Gauss::set_vetor_v(vector<double> v) {
    this->vetor_v = v;
}

void Gauss::set_matriz_c(vector<vector<double>> c) {
    this->matriz_c = c;
}