#ifndef PASSOS_HPP
#define PASSOS_HPP

#include <vector>
#include <string>

#include "NewtonRaphson.hpp"

namespace Passos {
    class Passo {
    public:
        int k;
        double xk;
        double xk_1;
        double fxk;
        double fxk_1;
        double e1;
        double e2;

        Passo(int k, double xk, double xk_1, double fxk, double fxk_1, double e1, double e2);
    };

    void exibir_passos(NewtonRaphson* metodo);
}

#endif