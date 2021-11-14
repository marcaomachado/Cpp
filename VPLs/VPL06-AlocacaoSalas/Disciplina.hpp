#ifndef DISCIPLINA_H
#define DISCIPLINA_H
#include "Alocacao.hpp"
#include <list>
//#include <set>
#include <iostream>
#include <string>

struct Disciplina
{
    int numero_alocacoes = 0;
    std::string codigo;
    std::string nome;
    
    std::list<Alocacao> alocacao;
    std::list<Alocacao>::iterator it;

    Disciplina();
    Disciplina(std::string codigo, std::string nome);

    void inserir_alocacao(std::string dia, std::string horario, std::string sala);
    void remover_alocacao(std::string horario);
    void imprimir_alocacao();
};
#endif