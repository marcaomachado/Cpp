#include "pizza.hpp"
#include <sstream>

std::string Pizza::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da pizza.
   *
   * Exemplos:
   * 2X Pizza Calabresa, 4 pedacos e borda recheada.
   * 2X Pizza Calabresa, 4 pedacos sem borda recheada.
   */
  std::ostringstream os;

  if (this->_borda_recheada) {
    os << m_qtd << "X Pizza " << _sabor << ", " << _pedacos
       << " pedacos e borda recheada." << std::endl;
    return os.str();
  }

  os << m_qtd << "X Pizza " << _sabor << ", " << _pedacos
     << " pedacos e sem borda recheada." << std::endl;

  return os.str();
}

Pizza::Pizza(const std::string& sabor,
             int pedacos,
             bool borda_recheada,
             int qtd,
             float valor_unitario) {
  // TODO: Implemente este metodo.
  this->_sabor = sabor;
  this->_pedacos = pedacos;
  this->_borda_recheada = borda_recheada;
  m_qtd = qtd;
  m_valor_unitario = valor_unitario;
}