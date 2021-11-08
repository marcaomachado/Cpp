#include <iostream>
#include "Processo.hpp"
using namespace std;

Processo::Processo(){}

Processo::Processo(int id, string nome, int prioridade)
{
    _id = id;
    _nome = nome;
    _prioridade = prioridade;
}


//SEMPRE LEMBRAR DE USAR "Nome_Struct :: nome_do_metodo"
//Observe que não há necessidade de usar o this para chamar os atributos do próprio processo.
void Processo::imprimir_dados()
{
    cout << this->_id << " " << _nome << " " << this->_prioridade << endl;
}