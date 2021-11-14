#include "QuadroAlocacao.hpp"
#include <map>
#include "Disciplina.hpp"
#include <set>

QuadroAlocacao::QuadroAlocacao(){
    this->numero_maximo_alocacoes = 0;
};

void QuadroAlocacao::inserir_alocacao(std::string codigo, std::string nome, std::string dia, std::string horario, std::string sala)
{
    std::map<std::string, Disciplina>::iterator it;
    it = disciplinas.find(codigo);
    if( it != disciplinas.end())
    {
        it->second.inserir_alocacao(dia, horario, sala);
    }
    else
    {
        Disciplina disciplina(codigo, nome);
        disciplina.inserir_alocacao(dia, horario, sala);
        this->disciplinas.insert(std::pair<std::string, Disciplina>(codigo, disciplina));
    }
}

void QuadroAlocacao::remover_alocacao_disciplina(std::string codigo, std::string horario)
{
    std::map<std::string, Disciplina>::iterator it;
    it = disciplinas.find(codigo);
    if (it != disciplinas.end())
    {
        it->second.remover_alocacao(horario);
    }
}
    
void QuadroAlocacao::recupera_numero_maximo_alocacoes()
{
    int max = 0;
    for (std::map<std::string, Disciplina>::iterator it = disciplinas.begin(); it != disciplinas.end(); it++)
    {
        if (it->second.numero_alocacoes > max)
        {
            max = it->second.numero_alocacoes;
        }
    }

    this->numero_maximo_alocacoes = max;
}

std::vector<Disciplina> QuadroAlocacao::recuperar_disciplinas_mais_ofertadas()
{
    std::vector<Disciplina> vector;
    std::map<std::string, Disciplina>::iterator it = disciplinas.begin();

    recupera_numero_maximo_alocacoes();

    for ( ; it != disciplinas.end(); ++it)
    {
        if (it->second.numero_alocacoes == this->numero_maximo_alocacoes)
        {
            vector.push_back(it->second);
        }
    }
    return vector;
}

void QuadroAlocacao:: recuperar_codigos_disciplinas_ordenada()
{
    lista_ordenada_codigos.clear();
    for (std::map<std::string, Disciplina>::iterator it = disciplinas.begin(); it != disciplinas.end(); ++it)
    {
        lista_ordenada_codigos.push_back(it->second.codigo);
    }
    lista_ordenada_codigos.sort([] (std::string a, std::string b){return a.compare(b) < 0;});
}

void QuadroAlocacao::imprimir_alocacao_completa()
{
    //std::cout<<"entrou2"<<std::endl;
    recuperar_codigos_disciplinas_ordenada();
    for (std::list<std::string>::iterator it0 = lista_ordenada_codigos.begin(); it0 != lista_ordenada_codigos.end(); ++it0)
    {
        //std::cout<<"entrou3"<<std::endl;
        std::map<std::string, Disciplina>::iterator it;
        it = disciplinas.find(*it0);
        it->second.imprimir_alocacao();
    } 
}