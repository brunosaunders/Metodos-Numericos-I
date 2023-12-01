#include "Cramer.hpp"
#include "Gauss.hpp"

#include <iostream>
#include <string>

using namespace std;
using namespace metodos_numericos1::metodos;

vector<double> Cramer::get_vetor_d_deslocamentos() {
    return this->vetor_d_deslocamentos;
}

vector<double> Cramer::get_vetor_amplitudes() {
    vector<double> vetor_amplitudes = this->get_vetor_d_deslocamentos();
    for (auto& item : vetor_amplitudes) {
        item *= this->a;
    }
    return vetor_amplitudes;
}

string Cramer::get_balanco_quebra() {
    vector<double> vetor_amplitudes = this->get_vetor_amplitudes();
    if (vetor_amplitudes.size() == 0) {
        throw runtime_error("Chame resolve_sistema_linear() antes.");
    }

    for (auto& valor : vetor_amplitudes) {
        if (valor > this->amplitude_limite) {
            return "sim";
        }
    }

    return "não";
}

void Cramer::resolve_sistema_linear() {
    int n = this->matriz_c.size();
    vector<double> vetor_v = this->vetor_v;
    int tamanho_v = vetor_v.size();
    Gauss* gauss = new Gauss(this->matriz_c, this->vetor_v, this->a);
    double det_matriz_a = gauss->get_determinante_matriz_c();
    delete gauss;

    vector<double> vetor_d_deslocamentos;

    for (int i=0; i < n; i++) {
        vector<vector<double>> matriz_a_i = this->matriz_c;

        for (int j=0; j < tamanho_v; j++) {
            matriz_a_i[j][i] = vetor_v[j];
        }

        Gauss* gauss = new Gauss(matriz_a_i, vetor_v, this->a);
        double det_matriz_a_i = gauss->get_determinante_matriz_c();
        vetor_d_deslocamentos.push_back(det_matriz_a_i / det_matriz_a);
        delete gauss;
    }

    this->vetor_d_deslocamentos = vetor_d_deslocamentos;
}