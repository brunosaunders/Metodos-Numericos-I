#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <string>

#include "Painel.hpp"
#include "exceptions/PivoZeroException.hpp"
#include "fmt/core.h"
#include "fmt/format.h"
#include "Gauss.hpp"


using namespace metodos_numericos1::outputs;
using namespace metodos_numericos1::metodos;

Painel::Painel() {}


void Painel::init(std::vector<Gauss*> metodos){
    int escolha_usuario;
    this->output(this->texto_menu_principal);
    std::cout << "R: ";
    std::cin >> escolha_usuario;
    try {
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
            default: 
                {
                    Painel::formata_avisos(this->texto_entrada_invalida);
                    this->init(metodos);
                    break;
                }
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void Painel::formata_avisos(const char *texto) const {
    fmt::print("\n!!! {0} !!!\n\n", texto);
}

void Painel::output(const char *texto_principal) const {
    std::cout << texto_principal;
}
