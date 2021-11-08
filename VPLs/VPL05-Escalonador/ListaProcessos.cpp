#include <iostream>
#include "Processo.hpp"
#include "ListaProcessos.hpp"

using namespace std;

void ListaProcessos::adicionar_processo(Processo *proc)
{
    Processo *newaux = head;
    Processo *oldaux = head;

    if (head == nullptr)
    {
        head = proc;
        tail = proc;
    }
    else if (head->_prioridade < proc->_prioridade)
    {
        proc->next = head; //primeiro passa o endereço do antigo head para o novo head
        head->last = proc;
        head = proc;
    }
    else if (tail->_prioridade >= proc->_prioridade)
    {
        tail->next = proc; // faço com que o antigo último processo aponte para o novo último processo.
        proc->last = tail;
        tail = proc;
    }
    else
    {
        while (newaux->_prioridade >= proc->_prioridade)
        {
            oldaux = newaux;
            newaux = newaux->next;
        }
        proc->next = newaux;
        newaux->last = proc;
        oldaux->next = proc;
        proc->last = oldaux;
    }
}

Processo *ListaProcessos::remover_processo_maior_prioridade()
{
    if (head == nullptr)
        return nullptr;
    Processo *aux = head;
    head = head->next;
    head->last = nullptr;
    return aux;
}

Processo *ListaProcessos::remover_processo_menor_prioridade()
{
    if (head == nullptr)
        return nullptr;
    Processo *aux = tail;
    tail = tail->last;
    tail->next = nullptr;
    return aux;
}

Processo *ListaProcessos::remover_processo_por_id(int id)
{
    Processo *aux = head;
    if (head->_id == id)
    {
        head = head->next;
        
        return aux;
    }
    while (aux != nullptr)
    {
        if (aux->_id == id)
        {
            aux->last->next = aux->next;
            return aux;
        }
        aux = aux->next;
    }
    delete aux;
    return nullptr;
}

void ListaProcessos::imprimir_lista()
{
    Processo *aux = head;
    while (aux != nullptr)
    {
        aux->imprimir_dados();
        aux = aux->next;
    }
    delete aux;
}
