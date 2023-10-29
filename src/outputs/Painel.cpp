#include "Painel.hpp"
#include "NewtonRaphson.hpp"
#include "NewtonRaphsonFL.hpp"
#include "NewtonRaphsonComDerivadaNumerica.hpp"
#include "Polinomio.hpp"
#include "Pendulo.hpp"
#include "fmt/core.h"
#include "fmt/format.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace metodos_numericos1::include;

Painel::Painel() {}

void Painel::init(std::vector<NewtonRaphson*>& funcoes){
    int escolha_usuario;
    this->output(this->texto_menu_principal);
    std::cout << "R: ";
    std::cin >> escolha_usuario;
    switch (escolha_usuario) {
        case 0:
            {
                break;
            }
        case 1: 
            {
                double a3, a2, precisao, lambda;
                this->output(this->texto_cadastrar_funcao_metodo_analise);
                std::cin >> a3 >> a2 >> precisao;
                Pendulo pendulo(a3, a2);
                this->output(this->texto_escolher_newton_raphson);
                std::cout << "R: ";
                std::cin >> escolha_usuario;
                switch (escolha_usuario) {
                    case 1:
                        {
                            this->output(this->texto_newton_raphson_normal);
                            NewtonRaphson* nr = new NewtonRaphson(100, precisao, pendulo);
                            funcoes.push_back(nr);
                            fmt::print("\n!!! {0} {1} !!!\n\n", this->texto_metodo_cadastrado, nr->get_classe(precisao));
                            this->init(funcoes);
                            break;
                        }
                    case 2:
                        {
                            this->output(this->texto_newton_raphson_fl);
                            this->output(this->texto_cadastrar_lambda);
                            std::cin >> lambda;
                            NewtonRaphson* nr_fl = new NewtonRaphsonFL(100, precisao, pendulo, lambda);
                            funcoes.push_back(nr_fl);
                            fmt::print("\n!!! {0} {1} !!!\n\n", this->texto_metodo_cadastrado, nr_fl->get_classe(precisao));
                            this->init(funcoes);
                            break;
                        }
                    case 3: 
                        {
                            this->output(this->texto_newton_raphson_derivada_numerica);
                            NewtonRaphson* nr_d = new NewtonRaphsonComDerivadaNumerica(100, precisao, pendulo);
                            funcoes.push_back(nr_d);
                            fmt::print("\n!!! {0} {1} !!!\n\n", this->texto_metodo_cadastrado, nr_d->get_classe(precisao));
                            this->init(funcoes);
                            break;
                        }
                    default: 
                        {
                            this->output(this->texto_entrada_invalida);
                            this->init(funcoes);
                            break;
                        }
                }
                break;
            }
        case 2: 
            {
                this->output(this->texto_remover_funcao_cadastrada);
                // Checar a possibilidade dessa ação acontecer
                if (funcoes.size() < 1)
                {
                    fmt::print("\n!!! {0} !!!\n\n", this->texto_nenhuma_funcao_remover);
                }
                else // Aqui pode acontecer
                {
                    int j;
                    this->output(this->texto_mostrar_funcoes_cadastradas);
                    for (int i = 0; i < funcoes.size(); i++) 
                    {
                        std::cout << i+1 << " -> " << funcoes[i]->get_classe(2) << "\n";
                    }
                    this->output(this->texto_inserir_indice_remover);
                    std::cout << "R: ";

                    std::cin >> j;
                    funcoes.erase(funcoes.begin() + (j - 1));
                    fmt::print("\n!!! {0} !!!\n\n", this->texto_funcao_removida);
                }
                this->init(funcoes);
                break;
            }
        case 3: 
            {
                this->output(this->texto_resetar_funcoes_cadastradas);
                // Checar a possibilidade dessa ação ocorrer
                if (funcoes.size() < 1)
                {
                    fmt::print("\n!!! {0} !!!\n\n", this->texto_sem_funcoes_resetar);
                }
                else
                {
                    funcoes.clear();
                    fmt::print("\n!!! {0} !!!\n\n", this->texto_funcoes_resetadas);
                }
                this->init(funcoes);
                break;
            }
        case 4: 
            {
                this->output(this->texto_analise_passo_passo_funcao);
                if (funcoes.size() < 1)
                {
                    fmt::print("\n!!! {0} !!!\n\n", this->texto_funcoes_resetadas);
                }
                else
                {
                    int j;
                    this->output(this->texto_mostrar_funcoes_cadastradas);
                    for (int i = 0; i < funcoes.size(); i++)
                    {
                       std::cout << i+1 << " -> " << funcoes[i]->get_classe(2) << "\n";
                    }
                    this->output(this->texto_inserir_indice_analisar);
                    std::cin >> j;
                    if (funcoes[j - 1]->get_nome_abreviado() == "NR")
                    {
                        std::cout << "NR\n"; //inserir aqui o metodo de analise
                    }
                    else if (funcoes[j - 1]->get_nome_abreviado() == "NR-FL")
                    {
                        std::cout << "NR-FL\n"; //inserir aqui o metodo de analise
                    }
                    else if (funcoes[j - 1]->get_nome_abreviado() == "NR-D")
                    {
                        std::cout << "NR-D\n"; //inserir aqui o metodo de analise
                    }
                }
                this->init(funcoes);
                break;
            }
        case 5: 
            {
                this->output(this->texto_mostrar_quadro_comparativo_func_cadastradas);
                // Chamar método que mostra quadro comparativo
                this->init(funcoes);
                break;
            }
        case 6: 
            {
                this->output(this->texto_mostrar_isolamento_funcao);
                // Chamar método que mostra o isolamento da função
                this->init(funcoes);
                break;
            }
        default: 
            {
                fmt::print("\n!!! {0} !!!\n\n", this->texto_entrada_invalida);
                this->init(funcoes);
                break;
            }
    }
}

void Painel::output(const char *texto_principal) const {
    std::cout << texto_principal;
}
