#include <iostream>
#include <vector>

using namespace std;

class NewtonRaphson 
{
 public:
     double a3, a2, prec, lambda;
     string met;

     NewtonRaphson() : a3(0.0), a2(0.0), prec(0.0), lambda(0.0), met(""){}
};


void painel(vector<NewtonRaphson> funcoes)
{
    int i;

    cout << "Escolha uma opcao:\n1 -> Cadastrar uma funcao e metodo para analise.\n2 -> Remover uma funcao ja cadastrada.\n";
    cout << "3 -> Resetar funcoes cadastradas.\n4 -> Mostrar analise passo a passo de um funcao.\n5 -> Gerar quadro comparativo das funcoes cadastradas.\n";
    cout << "6 -> Mostrar isolamento de uma funcao.\n0 -> Sair.\n";
    cin >> i;
    if (i == 0)
    {
        return;
    }
    else if (i == 1)
    {
        NewtonRaphson nr;
        int j;

        cout << "Voce escolheu 1 -> Cadastrar uma funcao e metodo para analise.\n\n";
        cout << "Insira os seguintes dados: a3, a2 e precisao\n";
        cin >> nr.a3 >> nr.a2 >> nr.prec;
        cout << "Agora, escolha o metodo desejado:\n1 -> Newton Raphson (NR).\n2 -> Newton Raphson com FL (NR-FL).\n";
        cout << "3 -> Newton Raphson com Derivada Numerica (NR-D).\n";
        cin >> j;
        if (j == 1)
        {
            cout << "Voce escolheu 1 -> Newton Raphson (NR).\n\n";
            nr.met = "NR";
            funcoes.push_back(nr);
            cout << "Metodo cadastrado: NR(a3: " << nr.a3 << ", a2: " << nr.a2 << ", e: " << nr.prec << ")\n\n";
        }
        if (j == 2)
        {
            cout << "Voce escolheu 2 -> Newton Raphson com FL (NR-FL).\n";
            nr.met = "NR-Fl";
            cout << "Informe o lambda:\n";
            cin >> nr.lambda;
            funcoes.push_back(nr);
            cout << "Metodo cadastrado: NR-FL(a3: " << nr.a3 << ", a2: " << nr.a2 << ", e: " << nr.prec << ", lambda: " << nr.lambda << ")\n\n";
        }
        if (j == 3)
        {
            cout << "Voce escolheu 3 -> Newton Raphson com Derivada Numerica (NR-D).\n\n";
            nr.met = "NR-D";
            funcoes.push_back(nr);
            cout << "Metodo cadastrado: NR-D(a3: " << nr.a3 << ", a2: " << nr.a2 << ", e: " << nr.prec << ")\n\n";
        }
        painel(funcoes);
    }
    else if (i == 2)
    {
        cout << "Voce escolheu 2 -> Remover uma funcao ja cadastrada.\n\n";
        if (funcoes.size() < 1)
        {
            cout << "Ainda nao foram cadastradas funcoes. Portanto, nao e possivel remover nenhuma. ";
            cout << "Tente inserir uma funcao primeiramente.\n\n";
        }
        else
        {
            int j;
            cout << "Estas sao as funcoes cadastradas:\n\n";
            for (int i = 0; i < funcoes.size(); i++) 
            {
                cout << i + 1 << " -> " << funcoes[i].met << "(" << funcoes[i].a3 << " " << funcoes[i].a2 << " " << funcoes[i].prec << " " << funcoes[i].lambda << ")\n";
            }
            cout << "\nInsira o indice de qual funcao deseja remover:\n";
            cin >> j;
            funcoes.erase(funcoes.begin() + (j - 1));
            cout << "Funcao removida com sucesso.\n\n";
        }
        painel(funcoes);
    }
    else if (i == 3)
    {
        cout << "Voce escolheu 3 -> Resetar funcoes cadastradas.\n\n";
        if (funcoes.size() < 1)
        {
            cout << "Nao existem funcoes cadastradas. Portanto, nao ha o que remover.\n\n";
        }
        else
        {
            funcoes.clear();
            cout << "Pronto, todas as funcoes foram removidas.\n\n";
        }
        painel(funcoes);
    }
    else if (i == 4)
    {
        cout << "Voce escolheu 4 -> Mostrar analise passo a passo de um funcao.\n\n";
        if (funcoes.size() < 1)
        {
            cout << "Ainda nao foram cadastradas funcoes. Portanto, nao e possivel analisar nenhuma. ";
            cout << "Tente inserir uma funcao primeiramente.\n\n";
        }
        else
        {
            int j;
            cout << "Estas sao as funcoes cadastradas:\n\n";
            for (int i = 0; i < funcoes.size(); i++)
            {
                cout << i + 1 << " -> " << funcoes[i].met << "(" << funcoes[i].a3 << " " << funcoes[i].a2 << " " << funcoes[i].prec << " " << funcoes[i].lambda << ")\n";
            }
            cout << "\nInsira o indice de qual funcao deseja analisar:\n";
            cin >> j;
            if (funcoes[j - 1].met == "NR")
            {
                //chamar metodo NR
            }
            else if (funcoes[j - 1].met == "NR-FL")
            {
                //chamar metodo NR-FL
            }
            else if (funcoes[j - 1].met == "NR-D")
            {
                //chamar metodo NR-D
            }
        }
        painel(funcoes);
    }
    else if (i == 5)
    {
        cout << "Voce escolheu 5 -> Gerar quadro comparativo das funcoes cadastradas.\n\n";
        //chamar metodo que mostra quadro comparativo
        painel(funcoes);
    }
    else if (i == 6)
    {
        cout << "Voce escolheu 6 -> Mostrar isolamento de uma funcao.\n\n";
        //chamar metodo que mostra o isolamento da funcao
        painel(funcoes);
    }
    else
    {
        cout << "Entrada invalida. Tente novamente.\n";
        painel(funcoes);
    }
}

int main() 
{
    vector<NewtonRaphson> funcoes;
    painel(funcoes);
    return 0;
}
