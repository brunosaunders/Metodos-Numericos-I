#ifndef METODOS_NUMERICOS1_INCLUDE_EXCEPTIONS_PIVOZEROEXCEPTIONS_HPP_
#define METODOS_NUMERICOS1_INCLUDE_EXCEPTIONS_PIVOZEROEXCEPTIONS_HPP_

#include <exception>

namespace metodos_numericos1::exceptions {
    class PivoZeroException : public std::exception {
        public:
            virtual const char * what() const throw();
    };
}

#endif
