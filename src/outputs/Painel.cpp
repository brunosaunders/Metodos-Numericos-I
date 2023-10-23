#include "Painel.hpp"
#include "NewtonRaphson.hpp"
#include "Polinomio.hpp"
#include "fmt/core.h"
#include "fmt/format.h"
#include <iostream>
#include <memory>
#include <string>

using namespace metodos_numericos1::include;

Painel::Painel() {}

void Painel::init() {
    int escolha_usuario;
    this->output(this->texto_menu_principal);
    std::cin >> escolha_usuario;
    switch (escolha_usuario) {
        case 1: 
            {
                double a3, a2, precisao;
                this->output(this->texto_cadastrar_funcao_metodo_analise);
                std::cin >> a3 >> a3 >> precisao;
                Polinomio polinomio = Polinomio({a3, a2, 3});
                this->output(this->texto_escolher_newton_raphson);
                std::cin >> escolha_usuario;
                switch (escolha_usuario) {
                    case 1:
                        {
                            this->output(this->texto_newton_raphson_normal);
                            //nr.met = "NR";
                            //funcoes.push_back(nr);
                            fmt::print("{0} NR(a3: {1}, a2: {2}, e: {3}) \n", this->texto_metodo_cadastrado, a3, a2, precisao);
                            break;
                        }
                    case 2:
                        {
                            this->output(this->texto_newton_raphson_fl);
                            //nr.met = "NR-Fl";
                            //cout << "Informe o lambda:\n";
                            //cin >> nr.lambda;
                            //funcoes.push_back(nr);
                            //this->output(this->texto_metodo_cadastrado, 1, 2);
                            fmt::print("{0} NR-FL(a3: {1}, a2: {2}, e: {3}, lambda: {4}) \n", this->texto_metodo_cadastrado, a3, a2, precisao, lambda);
                            break;
                        }
                    case 3: 
                        {
                            this->output(this->texto_newton_raphson_derivada_numerica);
                            //nr.met = "NR-D";
                            //funcoes.push_back(nr);
                            //this->output(this->texto_metodo_cadastrado, "o", "p");
                            fmt::print("{0} NR-D(a3: {1}, a2: {2}, e: {3}) \n", this->texto_metodo_cadastrado, a3, a2, precisao);
                            break;
                        }
                    default: 
                        {
                            this->output(this->texto_entrada_invalida);
                            this->init();
                            break;
                        }
                }
                break;
            }
        case 2: 
            {
                this->output(this->texto_remover_funcao_cadastrada);
                //// Checar a possibilidade dessa ação acontecer
                //if (funcoes.size() < 1)
                //{
                //    cout << "Ainda nao foram cadastradas funcoes. Portanto, nao e possivel remover nenhuma. ";
                //    cout << "Tente inserir uma funcao primeiramente.\n\n";
                //}
                //else // Aqui pode acontecer
                //{
                //    int j;
                //    cout << "Estas sao as funcoes cadastradas:\n\n";
                //    for (int i = 0; i < funcoes.size(); i++) 
                //    {
                //        cout << i + 1 << " -> " << funcoes[i].met << "(" << funcoes[i].a3 << " " << funcoes[i].a2 << " " << funcoes[i].prec << " " << funcoes[i].lambda << ")\n";
                //    }
                //    cout << "\nInsira o indice de qual funcao deseja remover:\n";
                //   cin >> j;
                //    funcoes.erase(funcoes.begin() + (j - 1));
                //    cout << "Funcao removida com sucesso.\n\n";
                //}
                this->init();
                break;
            }
        case 3: 
            {
                this->output(this->texto_resetar_funcoes_cadastradas);
                //// Checar a possibilidade dessa ação ocorrer
                //if (funcoes.size() < 1)
                //{
                //    cout << "Nao existem funcoes cadastradas. Portanto, nao ha o que remover.\n\n";
                //}
                //else
                //{
                //    funcoes.clear();
                //    cout << "Pronto, todas as funcoes foram removidas.\n\n";
                //}
                this->init();
                break;
            }
        case 4: 
            {
                this->output(this->texto_analise_passo_passo_funcao);
                //if (funcoes.size() < 1)
                //{
                //    cout << "Ainda nao foram cadastradas funcoes. Portanto, nao e possivel analisar nenhuma. ";
                //    cout << "Tente inserir uma funcao primeiramente.\n\n";
                //}
                //else
                //{
                //    int j;
                //    cout << "Estas sao as funcoes cadastradas:\n\n";
                //    for (int i = 0; i < funcoes.size(); i++)
                //    {
                //        cout << i + 1 << " -> " << funcoes[i].met << "(" << funcoes[i].a3 << " " << funcoes[i].a2 << " " << funcoes[i].prec << " " << funcoes[i].lambda << ")\n";
                //    }
                //    cout << "\nInsira o indice de qual funcao deseja analisar:\n";
                //    cin >> j;
                //    if (funcoes[j - 1].met == "NR")
                //    {
                //        //chamar metodo NR
                //    }
                //    else if (funcoes[j - 1].met == "NR-FL")
                //    {
                //        //chamar metodo NR-FL
                //    }
                //    else if (funcoes[j - 1].met == "NR-D")
                //    {
                //        //chamar metodo NR-D
                //    }
                //}
                this->init();
                break;
            }
        case 5: 
            {
                this->output(this->texto_mostrar_quadro_comparativo_func_cadastradas);
                // Chamar método que mostra quadro comparativo
                this->init();
                break;
            }
        case 6: 
            {
                this->output(this->texto_mostrar_isolamento_funcao);
                // Chamar método que mostra o isolamento da função
                this->init();
                break;
            }
        default: 
            {
                this->output(this->texto_entrada_invalida);
                this->init();
                break;
            }
    }
}

void Painel::output(const char *texto_principal) const {
    std::cout << texto_principal << std::endl;
}
