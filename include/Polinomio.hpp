#ifndef METODOS_NUMERICOS1_INCLUDE_POLINOMIO_HPP_
#define METODOS_NUMERICOS1_INCLUDE_POLINOMIO_HPP_

#include <vector> 

namespace metodos_numericos1::include {
    class Polinomio { 
        public:
            Polinomio(); 
            Polinomio(std::vector<double> coeficientes); 

            std::vector<double> coeficientes; 
            std::vector<std::pair<double, double>> intervalos;

            int get_grau() const;
            Polinomio get_funcao_derivada() const;
            double get_valor_funcao(double x) const; // Método que retorna P(x) 

            double operator[] (int i) const; // acessa o coeficiente a_i
            void print();

            Polinomio soma(Polinomio p);
            Polinomio divide(Polinomio p);
            Polinomio divide(double valor);
            Polinomio subtrai(Polinomio p);
            Polinomio multiplica(Polinomio p);
            Polinomio multiplica(double valor);

            /*
             * Dado um polinômio retorna intervalos contendo raizes desse polinômi desse polinômioo 
             */
            void encontra_intervalos(double a, double b, int n_raizes);

            /*
             * Dado um intervalo é retornado a quantidade de raízes dentro daquele intervalo 
             * Esse método faz uso do teorema de Sturm para fazer o cálculo da quantidade de raizes existentes no intervalo dado
             */
            int numero_raizes_reais(double a, double b);

            /*
             * Retorna um intervalo onde as raízes do polinômio se encontram.
             * Esse método faz o uso do Cauchy's bounds.
             */
            std::pair<double, double> intervalo_max();

    }; 
} // namespace metodos_numericos1::include

#endif /* METODOS_NUMERICOS1_INCLUDE_POLINOMIO_HPP_ */
