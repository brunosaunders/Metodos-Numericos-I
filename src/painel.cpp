#include <iostream>

using namespace std;

int main() {
    double prec;
    int n, i;

    cout << "Vamos calcular o deslocamento da oscilaçao de um determinado balanco.\n";
    cout << "Primeiramente, insira o numero de lambdas que serao testados:\n";
    cin >> n;
    double* lambda = new double[n];
    double* coef3 = new double[n];
    double* coef2 = new double[n];
    cout << "Em seguida, insira o(s) lambda(s):\n";
    for (i = 0; i < n; i++)
    {
        cin >> lambda[i] >> coef2[i] >> coef3[i];
    }
    cout << "Por fim, insira a precisao que deseja adotar para o calculo:\n";
    cin >> prec;
    cout << "Agora, comecaremos calculando o deslocamento pelo Metodo de Newton original:\n";
    //a) função metodo de newton [usar o exemplo do item d) nos itens a), b) e c)?]
    cout << "Depois, calculamos o deslocamento pelo Metodo de Newton com FL:\n";
    //b) função metodo de newton FL (explicar o que seria o FL?)
    cout << "Continuando, calculamos o deslocamento utilizando a derivada de f(d):\n";
    //c) função com derivada
    cout << "Com isso, obtemos os seguintes quadros respostas para cada metodo:\n";
    //e) mostrar tabelas resposta
    cout << "Comparando os resultados em um quadro comparativo...\n";
    //f) mostrar tabela comparativa
    cout << "Nos podemos chegar na seguinte analise:\n";



    //cout << "n = " << n << "\n";
    //for (i = 0; i < n; i++)
    //{
       // cout << "lambda " << i+1 << "=" << lambda[i] << "\n";
    //}
    //cout << "prec = " << prec << "\n";

    delete[] lambda;
    delete[] coef3;
    delete[] coef2;
    return 0;
}
