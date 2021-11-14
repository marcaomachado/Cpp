// NÃO ALTERE ESSA LINHA
//#include "avaliacao_basica_alocacao.hpp"

#include <iostream>
#include <string>
#include "QuadroAlocacao.hpp"
using namespace std;


int main() {
    QuadroAlocacao quadroalocacao;
    vector<Disciplina> vector;

    char entrada;
    while (cin >> entrada)
    {
        switch (entrada)
        {
            case 'a':
            {
                string codigo, nome, dia, horario, sala;
                cin >> codigo >> nome >> dia >> horario >> sala;
                quadroalocacao.inserir_alocacao(codigo, nome, dia, horario, sala);
                break;
            }
            case 'm':
            {
                vector = quadroalocacao.recuperar_disciplinas_mais_ofertadas();
                for(auto disciplina: vector)
                {
                    disciplina.imprimir_alocacao();
                }
                break;
            }
            case 'r':
            {
                string codigo, horario;
                cin >> codigo >> horario;
                quadroalocacao.remover_alocacao_disciplina(codigo, horario);
                break;
            }
            case 'p':
            {
                quadroalocacao.imprimir_alocacao_completa();
                break;
            }
            case 'b':
            {
                //avaliacao_basica();
                break;
            }
            default:
                break;  
        }
    }
    return 0;
}