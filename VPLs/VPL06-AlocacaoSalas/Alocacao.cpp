#include <iostream>
#include "Alocacao.hpp"


Alocacao::Alocacao(){};
Alocacao::Alocacao(std::string dia, std::string horario, std::string sala)
{
    this->dia = dia;
    this->horario = horario;
    this->sala = sala;
}

void Alocacao::imprimir_dados(){
    std::cout << dia << " " << horario << " " << sala << std::endl;
}
