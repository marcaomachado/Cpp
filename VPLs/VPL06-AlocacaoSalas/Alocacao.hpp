#ifndef ALOCACAO_H
#define ALOCACAO_H
#include <iostream>

struct Alocacao{
    std::string dia;
    std::string horario;
    std::string sala;

    Alocacao(std::string dia, std::string horario, std::string sala);
    Alocacao();

    void imprimir_dados();

};
#endif