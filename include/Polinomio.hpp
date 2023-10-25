#ifndef METODOS_NUMERICOS1_INCLUDE_POLINOMIO_HPP_
#define METODOS_NUMERICOS1_INCLUDE_POLINOMIO_HPP_

#include <vector> 

namespace metodos_numericos1::include {
    class Polinomio { 
        public:
            Polinomio(); 
            Polinomio(std::vector<double> coeficientes); 

            int get_grau() const;
            double get_valor_funcao(double x) const; // Método que retorna P(x) 
            std::vector<double> coeficientes; 

            Polinomio get_funcao_derivada() const;

            /*acessa o coeficiente a_i*/
            double operator[] (int i) const;

            double p(double x) const;

            /*
             * Dado um intervalo [a, b] é feito o teste para saber se existem mais de uma raiz nesse intervalo
             */
            bool tem_mais_raiz(double a, double b);

            /*
             * Dado um polinômio retorna intervalos contendo raizes desse polinômi desse polinômioo 
             */
            void encontra_intervalos(double a, double b, int n_raizes);

            Polinomio divide(Polinomio p);

            Polinomio divide(double valor);

            Polinomio multiplica(double valor);

            Polinomio multiplica(Polinomio p);

            Polinomio soma(Polinomio p);

            Polinomio subtrai(Polinomio p);

            void print();

            /*
             * Dado um intervalo é retornado a quantidade de raízes dentro daquele intervalo 
             */
            int numero_raizes(double a, double b);

            /*
             * Retorna um intervalo onde as raízes do polinômio se encontram.
             * Essa função faz o uso do Cauchy's bounds.
             */
            std::pair<double, double> intervalo_max();

            std::vector<std::pair<double, double>> intervalos;
    }; 
} // namespace metodos_numericos1::include

#endif /* METODOS_NUMERICOS1_INCLUDE_POLINOMIO_HPP_ */
