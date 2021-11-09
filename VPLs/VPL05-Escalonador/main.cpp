// NÃO ALTERE ESSA LINHA
//#include "avaliacao_basica_escalonador.hpp"

#include <iostream>
#include "Processo.hpp"
#include "ListaProcessos.hpp"
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    ListaProcessos lista;

    char entrada;
    while (cin >> entrada)
    {
        switch (entrada)
        {
            case 'a':
            {
                int id;
                string nome;
                int prioridade;

                cin >> id >> nome >> prioridade;

                Processo* aux = new Processo(id, nome, prioridade);

                lista.adicionar_processo(aux);
                break;
            }

            case 'm':
                lista.remover_processo_maior_prioridade();
                break;
            case 'n':
                lista.remover_processo_menor_prioridade();
                break;
            case 'r':
                int id;
                cin >> id;
                lista.remover_processo_por_id(id);
                break;
            case 'p':
                lista.imprimir_lista();
                break;
            case 'b':
                //avaliacao_basica();
                break;
            default:
                break;
        }
    }

    return 0;
}