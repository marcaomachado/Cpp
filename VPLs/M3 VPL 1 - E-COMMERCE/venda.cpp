#include "venda.hpp"

#include <cmath>
#include <iomanip>
#include <iostream>
#include "celular.hpp"
using std::cout;
using std::toupper;
using std::endl;

void Venda::adicionaCelular(const Celular& celular) {
  // TODO: Implemente este metodo
  m_celulares.push_back(celular);
}

void Venda::ordena() {
  // TODO: Implemente este metodo
  // Preste atencao no exemplo que a descricao utilizada na ordenacao considera
  // a fabricante antes do modelo do celular
  m_celulares.sort();
}

void Venda::recarregaEstoque(int cod, int qtd) {
  // TODO: Implemente este metodo
  std::list<Celular>::iterator it = m_celulares.begin(); 
  for (it; it != m_celulares.end(); ++it){
    if (it->cod == cod){
      it->qtd += qtd;
      break;
    }
  }
}

void Venda::efetuaVenda(int cod, int qtd) {
  // TODO: Implemente este metodo
  /**
   * Observe na descricao do enunciado que nao e permita a venda de um modelo
   * cuja quantidade seja maior que a quantidade atual em estoque.
   * Ex: Se existirem apenas 5 celulares Motorola Moto G50 em estoque, vendas a
   * partir de 6 unidades devem ser ignoradas.
   */
  std::list<Celular>::iterator it = m_celulares.begin(); 
  for (it; it != m_celulares.end(); ++it){
    if (it->cod == cod && it->qtd >= qtd){
      it->qtd -= qtd;
      break;
    }
  }
}

void Venda::aplicaDesconto(const std::string& fabricante, float desconto) {
  // TODO: Implemente este metodo
  std::list<Celular>::iterator it = m_celulares.begin(); 
  for (it; it != m_celulares.end(); ++it){
    if (it->fabricante.compare(fabricante) == 0){
      it->valor *= (1.0 - desconto/100.0);
    }
  }
}

void Venda::removeModelo(int cod) {
  // TODO: Implemente este metodo
  std::list<Celular>::iterator it = m_celulares.begin(); 
  for (it; it != m_celulares.end(); ++it){
    if (it->cod == cod){
      m_celulares.erase(it);
      break;
    }
  }
}

void Venda::imprimeEstoque() const{
  // TODO: Implemente este metodo.
  /**
   * Aqui voce tera que imprimir a lista de celulares em estoque com as
   * restricoes descritas no enunciado do problema. Notem no exemplo que a
   * primeira letra da cor do celular fica maiuscula. Outra coisa, se houver
   * apenas um item em estoque de determinado modelo de celular, voce tera que
   * imprimir '1 restante' e nao '1 restantes'. Por ultimo, apenas modelos de
   * celulares com pelo menos um item em estoque deverao ser exibidos.
  */

  for (std::list<Celular>::const_iterator it = m_celulares.begin(); it != m_celulares.end(); ++it){
    if (it->qtd > 0){
      std::locale loc;
      cout << toupper(it->fabricante[0], loc);
      for (int i = 1; i < it->fabricante.size(); i++)
      {
        if (it->fabricante[i] == ' ')
        {
          i++;
          cout << " " << toupper(it->fabricante[i], loc);
        }
        else {
          cout << it->fabricante[i];
        }
      }
      
      cout << " ";

      cout << toupper(it->modelo[0], loc);
      for (int i = 1; i < it->modelo.size(); i++){
        if (it->modelo[i] == ' '){
          i++;
          cout << " " << toupper(it->modelo[i], loc);
        }
        else {
          cout << it->modelo[i];
        }
      }

      cout << ", ";
      
      cout << it->armazenamento << "GB, " 
           << it->memoria << "GB RAM, ";
      cout << std::fixed << std::setprecision(0) << it->peso * 1000 << " gramas, ";


      cout << toupper(it->cor[0], loc);
      for (int i = 1; i < it->cor.size(); i++){
        if (it->cor[i] == ' '){
          i++;
          cout << toupper(it->cor[i], loc);
        }
        else {
          cout << it->cor[i];
        }
      }
      cout << ", ";
           
      if (it->qtd == 1){
        cout << it->qtd << " restante, "; 
      }
      else {
        cout << it->qtd << " restantes, "; 
      }
      cout <<"R$ " << std::fixed << std::setprecision(2) << it->valor << std::endl;
    }
  }
}