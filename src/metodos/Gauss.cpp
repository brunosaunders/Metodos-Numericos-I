#include "Gauss.hpp"
#include <stdexcept>
#include <cmath>

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

void Gauss::set_vetor_d_deslocamentos(vector<double> vetor_d_deslocamentos) {
    this->vetor_d_deslocamentos = vetor_d_deslocamentos;
}

int Gauss::get_trocas_de_linha() {
    return this->trocas_de_linha;
}

double Gauss::get_determinante_matriz_c() {
    if (this->vetor_d_deslocamentos.size() == 0) {
        Gauss::resolve_sistema_linear();
    }

    vector<vector<double>> matriz_c = this->matriz_c;
    double det = 1;

    for (int i=0; i < matriz_c.size(); i++) {
        det *= matriz_c[i][i];
    }
    
    return det * std::pow(-1, this->trocas_de_linha);
}

bool Gauss::get_balanco_quebra() {
    vector<double> vetor_amplitudes = this->get_vetor_amplitudes();
    if (vetor_amplitudes.size() == 0) {
        throw runtime_error("Chame resolve_sistema_linear() antes.");
    }

    for (auto& valor : vetor_amplitudes) {
        if (valor > this->amplitude_limite) {
            return true;
        }
    }

    return false;
}