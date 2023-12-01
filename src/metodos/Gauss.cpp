#include "Gauss.hpp"
#include "exceptions/PivoZeroException.hpp"
#include <exception>
#include <stdexcept>
#include <cmath>
#include <string>
#include <utility>
#include <iostream>
using namespace std;
using namespace metodos_numericos1::metodos;
/*Aplica o tecnica de pivoteamento parcial*/
pair<double,int> selecionar_pivo(vector<vector<double>> &matrix, int line, int col, int n) { 
    double max = abs(matrix[line][col]); 
    double pivo = matrix[line][col];
    int num_linha = line;
    for (int i = line +1; i < n; i++) {
        if(abs(matrix[i][col]) > max){
            pivo = matrix[i][col]; 
            max = abs(pivo);
            num_linha = i; 
        } 
    }
    return pair<double,int>(pivo,num_linha); 
}

void trocar_linhas(vector<vector<double>> &matrix,vector<double> &v ,int linha1, int linha2, int n) { 
    double t; 
    for (int i = 0; i < n; i++) { 
        t = matrix[linha1][i]; 
        matrix[linha1][i] = matrix[linha2][i]; 
        matrix[linha2][i] = t; 
    }
    t = v[linha1];  
    v[linha1] = v[linha2]; 
    v[linha2] = t; 
}

void Gauss::resolve_sistema_linear() {
    vector<vector<double>> c_copia = get_matriz_c_inicial();        
    vector<double> v_copia = get_vetor_v_inicial(); 
    int n = c_copia.size(); 
    int matrix_trocas_de_linha = 0; 

    //o indice "i" percorre as colunas 
    for (int i = 0; i < n; i++) {
        pair<double,int> dupla; 
        dupla  = selecionar_pivo(c_copia, i, i, n);
        double pv = dupla.first; 
        if (pv == 0) {
            throw  metodos_numericos1::exceptions::PivoZeroException();
        }
        int num_linha = dupla.second;
        if (num_linha != i) {
            matrix_trocas_de_linha++; 
            trocar_linhas(c_copia,v_copia, i,num_linha, n);
        }
        double m; 
        //Dada a coluna i, "j" percorre as linhas dessa coluna a partir da linha i+1
        for (int j = i+1; j < n; j++) { 
            m = (c_copia[j][i])/(pv); 
            //"k" percorre as colunas, realizando a operação: L_j <- L_j - m*L_i
            for (int k = i; k < n; k++){ 
                c_copia[j][k] = c_copia[j][k] - m*(c_copia[i][k]); 
            }
            v_copia[j] = v_copia[j] - v_copia[i]*m; 
        }
    }

    /*Cálculo dos d's*/ 
    vector<double> resultados_d(n); 
    for (int i = n-1; i >= 0; i--){ 
        double sum = v_copia[i]; 
        for (int j = i + 1; j < n; j++){ 
          sum -= c_copia[i][j]*resultados_d[j]; 
        }
        resultados_d[i] = sum/c_copia[i][i]; 
    }   

    //No fim atualiza o estado dos atributos
    set_vetor_d_deslocamentos(resultados_d); 
    set_vetor_v(v_copia);
    set_matriz_c(c_copia); 
    set_trocas_de_linha(matrix_trocas_de_linha); 
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

string Gauss::get_balanco_quebra() {
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

void Gauss::set_trocas_de_linha(int trocas_de_linha) { 
    this->trocas_de_linha = trocas_de_linha; 
}
