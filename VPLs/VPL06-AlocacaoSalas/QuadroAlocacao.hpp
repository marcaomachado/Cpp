#ifndef QUADRO_ALOCACAO_H
#define QUADRO_ALOCACAO_H
#include "Disciplina.hpp"
#include <map>
#include <vector>
#include <list>

struct QuadroAlocacao{
    std::map<std::string, Disciplina> disciplinas;
    int numero_maximo_alocacoes;
    std::list<std::string> lista_ordenada_codigos;

    QuadroAlocacao();

    void inserir_alocacao(std::string codigo, std::string nome, std::string dia, std::string horario, std::string sala);
    void remover_alocacao_disciplina(std::string codigo, std::string horario);
    void recupera_numero_maximo_alocacoes();
    std::vector<Disciplina> recuperar_disciplinas_mais_ofertadas();
    void recuperar_codigos_disciplinas_ordenada();
    void imprimir_alocacao_completa();
};
#endif