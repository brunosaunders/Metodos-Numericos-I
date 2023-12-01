#include "exceptions/PivoZeroException.hpp"

using namespace metodos_numericos1::exceptions;

const char* PivoZeroException::what() const throw() {
    return "Um dos pivores tem valor igual a 0, logo não terá uma solução única! Por favor, escolha outro sistema";
}
