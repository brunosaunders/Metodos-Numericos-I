#include "Gauss.hpp"
#include <stdexcept>

using namespace std;
using namespace metodos_numericos1::metodos;

void Gauss::resolve_sistema_linear() {
    // TODO
    return;
}

double Gauss::get_a() {
    return this->a;
}

vector<double> Gauss::get_vetor_d_deslocamentos() {
    if (this->vetor_d_deslocamentos.size() == 0) {
        throw runtime_error("Chame resolve_sistema_linear() antes.");
    }
    return this->vetor_d_deslocamentos;
}

vector<double> Gauss::get_vetor_amplitudes() {
    vector<double> vetor_amplitudes = this->get_vetor_d_deslocamentos();
    for (auto& item : vetor_amplitudes) {
        item *= this->a;
    }
    return vetor_amplitudes;
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