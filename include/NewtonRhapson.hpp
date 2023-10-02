#include "Polinomio.hpp"
#include "Metodos.hpp"
namespace newton { 
    class NewtonRhapson:public Metodos{};
    class NewtonRhapsonFL: public Metodos{};
    //Ou: 
    void NewtonRhapson(Polinomio);
    void NewtonRhapsonFL(Polinomio); 
};