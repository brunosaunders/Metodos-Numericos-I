#include "GaussJordan.hpp"
#include <stdexcept>

using namespace metodos_numericos1::metodos;

void GaussJordan::resolve_sistema_linear() {
    Gauss::resolve_sistema_linear();

    std::vector<std::vector<double>> matriz_c = this->get_matriz_c();
    std::vector<double> vetor_v = this->get_vetor_v();
    int n = matriz_c.size();
    
    // Checa diagonal principal
    for (int i=0; i < n; i++) {
        if (matriz_c[i][i] == 0) {
            throw std::runtime_error("Diagonal principal deve ser não nula");
        }
    }

    // Começa pela última linha e coluna da matriz
    for (int i = n - 1; i > 0; i--) {
        double a_ii = matriz_c[i][i];

        // Elimina a coluna acima de a_ii
        for (int j = i-1; j >= 0; j--) {
            double a_ji = matriz_c[j][i];

            // Elimina elemento acima de a_ii (como a matriz é triangular inferior, e começamos da linha mais baixa, 
            // não precisamos calcular os outros termos, pois em cada linha haverá apenas um pivô)
            double fator = a_ji/a_ii * (-1);
            matriz_c[j][i] += matriz_c[i][i] * fator;
            vetor_v[j] += vetor_v[i] * fator;
        }
    }

    this->set_matriz_c(matriz_c);
    this->set_vetor_v(vetor_v);
    this->set_vetor_d_deslocamentos(vetor_v); // Vetor resultado do sistema
}