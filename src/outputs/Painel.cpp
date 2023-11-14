#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "Painel.hpp"
#include "fmt/core.h"
#include "Passos.hpp"
#include "fmt/format.h"



using namespace metodos_numericos1::outputs;


Painel::Painel() {}


void Painel::init(std::vector<int> funcoes){
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
                // TODO
            }
        case 2: 
            {
                // TODO                
            }
        case 3: 
            {
                // TODO
            }
        case 4: 
            {
                // TODO
            }
        case 5: 
            {
                // TODO
            }
        case 6: 
            {
                // TODO
            }
        default: 
            {
                Painel::formata_avisos(this->texto_entrada_invalida);
                // this->init(funcoes); // TODO
                break;
            }
    }
}

void Painel::formata_avisos(const char *texto) const {
    fmt::print("\n!!! {0} !!!\n\n", texto);
}

void Painel::output(const char *texto_principal) const {
    std::cout << texto_principal;
}
