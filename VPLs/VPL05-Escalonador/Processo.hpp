#ifndef PROCESSO_H
#define PROCESSO_H
#include <string>
using namespace std;

struct Processo
{
    int _id;
    int _prioridade;
    string _nome;
    Processo* next = nullptr;
    Processo* last = nullptr;

    Processo(int id, string nome, int prioridade);
    Processo();

    void imprimir_dados();
};

#endif