#include "Estoque.hpp"
#include <iostream>
#include <list>
#include <string>
using namespace std;

void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  if (estoque.find(mercadoria) == estoque.end()) {
    estoque[mercadoria] = 0;
  }
  estoque[mercadoria] += qtd;
  // para atribuir valores, podemos usar essa forma parecida com a forma de
  // vectors.
}

void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  if (estoque.find(mercadoria) == estoque.end()) {
    cout << mercadoria << " inexistente" << endl;
  } else if (estoque[mercadoria] < qtd) {
    cout << mercadoria << " insuficiente" << endl;
  } else {
    estoque[mercadoria] -= qtd;
  }
}

unsigned int Estoque::get_qtd(const std::string& mercadoria) const {
  if (estoque.find(mercadoria) == estoque.end()) {
    return 0;
  }
  return estoque.find(mercadoria)->second;
}

void Estoque::imprime_estoque() const {
  list<string> listaDeMercadorias;
  for (auto it = estoque.begin(); it != estoque.end(); ++it) {
    listaDeMercadorias.push_back(it->first);
  }
  listaDeMercadorias.sort();
  for (auto it = listaDeMercadorias.begin(); it != listaDeMercadorias.end();
       ++it) {
    cout << *it << ", " << estoque.find(*it)->second << endl;
  }
}

// Precisei alterar o map para public para conseguir acessar os valores do map
// passado como parâmetro.

Estoque& Estoque::operator+=(const Estoque& rhs) {
  for (auto it = rhs.estoque.begin(); it != rhs.estoque.end(); ++it) {
    this->add_mercadoria(it->first, it->second);
  }
  return *this;
}

Estoque& Estoque::operator-=(const Estoque& rhs) {
  for (auto it = rhs.estoque.begin(); it != rhs.estoque.end(); ++it) {
    this->sub_mercadoria(it->first, it->second);
  }
  return *this;
}

bool operator<(Estoque& lhs, Estoque& rhs) {
  for (auto it = lhs.estoque.begin(); it != lhs.estoque.end(); ++it) {
    if (rhs.estoque.find(it->first) == rhs.estoque.end() ||
        it->second >= rhs.estoque.find(it->first)->second)
      return false;
  }
  return true;
}

bool operator>(Estoque& lhs, Estoque& rhs) {
  for (auto it = rhs.estoque.begin(); it != rhs.estoque.end(); ++it) {
    if (lhs.estoque.find(it->first) == lhs.estoque.end() ||
        it->second >= lhs.estoque.find(it->first)->second)
      return false;
  }
  return true;
}


auto getEstoque(){
  return estoque;
}