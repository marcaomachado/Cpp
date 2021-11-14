#include "Disciplina.hpp"
#include <iostream>
#include <list>


Disciplina::Disciplina(){};
Disciplina::Disciplina(std::string codigo, std::string nome)
{
    this->codigo = codigo;
    this->nome = nome;
}

void Disciplina::inserir_alocacao(std::string dia, std::string horario, std::string sala)
{
    Alocacao alocacaoAtual(dia, horario, sala); 

    this->alocacao.push_back(alocacaoAtual);
    this->numero_alocacoes++;
}

void Disciplina::remover_alocacao(std::string horario)
{
    this->it = this->alocacao.begin();
    for ( ; it!=this->alocacao.end(); it++)
    {
        if( it->horario == horario)
        {
            alocacao.erase(it);
            this->numero_alocacoes--;
            it = alocacao.end();
            break;
        }
    }
}

void Disciplina::imprimir_alocacao(){
    
    alocacao.sort([] (Alocacao a, Alocacao b){return a.horario.compare(b.horario) < 0;});

    for (this->it = this->alocacao.begin(); it!= alocacao.end(); it++)
    {
        std::cout <<this->codigo << " " << this->nome << " " << it->dia << " " << it->horario << " " << it->sala << std::endl; 
    }
}