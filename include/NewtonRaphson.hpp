#ifndef METODOS_NUMERICOS1_INCLUDE_NewtonRaphson_HPP 
#define METODOS_NUMERICOS1_INCLUDE_NewtonRaphson_HPP 

#include <vector>
#include <string>

#include "Polinomio.hpp"

using namespace metodos_numericos1::funcoes;

namespace metodos_numericos1::metodos {

    class NewtonRaphson { 
    private:
        bool quebra;
        double erro;
        bool raiz_valida;
        Polinomio funcao; 
        int max_iteracoes;
        std::vector<std::pair<double, double>> isolamento;

        /* roda o método numérico salvando informações no vetor iteracoes_de_x */
        virtual void calcula_raiz(double x0);

    protected:
        /* [x_0,x_1,...,x_n], onde x_n é a raiz encontrada*/
        std::vector<std::vector<double>> iteracoes_de_x;

    public: 
        NewtonRaphson (int max_iteracoes,double erro, Polinomio& funcao); 
        virtual ~NewtonRaphson() {}

        double get_erro() const;
        Polinomio& get_funcao();
        double get_raiz(int index);
        std::vector<double> get_raizes();
        std::string get_quebra();
        int get_total_iteracoes();
        virtual double get_lambda();
        double get_media_iteracoes();
        bool get_raiz_valida() const;
        int get_max_iteracoes() const;
        virtual std::string get_nome();
        virtual std::string get_nome_abreviado();
        virtual std::string get_classe(int precisao);
        std::vector<double>& get_iteracoes_de_x(int index);
        std::vector<std::vector<double>>& get_iteracoes_de_x_todas_raizes();
        std::vector<std::pair<double, double>> get_isolamento();
        void set_raiz_valida(bool r);

        /* Executa o método numérico para cada intervalo do isolamento, guardando
        * as iterações em iteracoes_de_x
        */
        void calcula_raizes();
    }; 
}
#endif
