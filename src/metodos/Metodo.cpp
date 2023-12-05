#include <iostream>
#include <string>

#include "Metodo.hpp"

using namespace std;
using namespace metodos_numericos1::metodos;

vector<double> Metodo::get_vetor_d_deslocamentos() {
    return this->vetor_d_deslocamentos;
}

vector<double> Metodo::get_vetor_amplitudes() {
    vector<double> vetor_amplitudes = this->get_vetor_d_deslocamentos();
    for (auto& item : vetor_amplitudes) {
        item *= this->a;
    }
    return vetor_amplitudes;
}

string Metodo::get_balanco_quebra() {
    vector<double> vetor_amplitudes = this->get_vetor_amplitudes();
    if (vetor_amplitudes.size() == 0) {
        throw runtime_error("Chame resolve_sistema_linear() antes.");
    }

    for (auto& valor : vetor_amplitudes) {
        if (std::abs(valor) > this->amplitude_limite) {
            return "sim";
        }
    }

    return "não";
}

double Metodo::get_a() {
    return this->a;
}

vector<vector<double>> Metodo::get_matriz_c() {
    return this->matriz_c;
}

vector<double> Metodo::get_vetor_v() {
    return this->vetor_v;
}

vector<double> Metodo::get_vetor_v_inicial() {
    return this->vetor_v_inicial;
}

vector<vector<double>> Metodo::get_matriz_c_inicial() {
    return this->matriz_c_inicial;
}

void Metodo::set_vetor_v(vector<double> v) {
    this->vetor_v = v;
}

void Metodo::set_matriz_c(vector<vector<double>> c) {
    this->matriz_c = c;
}

void Metodo::set_vetor_d_deslocamentos(vector<double> vetor_d_deslocamentos) {
    this->vetor_d_deslocamentos = vetor_d_deslocamentos;
}