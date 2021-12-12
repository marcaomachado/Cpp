#include "celular.hpp"
#include <iostream>
// TODO: Inicialize aqui sua variavel estatica. Caso tenha optado por essa
// solucao.
int Celular::totalDeCelularesRegistrados = 0;

Celular::Celular(std::string modelo,
                 std::string fabricante,
                 int armazenamento,
                 int memoria,
                 double peso,
                 std::string cor,
                 int qtd,
                 float valor) {
  // TODO: Implemente este metodo
  totalDeCelularesRegistrados++;
  this->cod = totalDeCelularesRegistrados;
  this->modelo = modelo;
  this->fabricante = fabricante;
  this->armazenamento = armazenamento;
  this->memoria = memoria;
  this->peso = peso;
  this->cor = cor;
  this->qtd = qtd;
  this->valor = valor;
}

bool Celular::operator<(const Celular& other) {
  // TODO: Implemente este metodo. 
  // Preste atencao no exemplo que a descricao utilizada na ordenacao considera
  // a fabricante antes do modelo do celular
  if (this->fabricante.compare(other.fabricante) < 0){
    return true;
  }
  else if (this->fabricante.compare(other.fabricante) == 0 && this->modelo.compare(other.modelo) < 0){
    return true;
  }
  return false;
}