#include "hamburguer.hpp"
#include <sstream>

std::string Hamburguer::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada do Hamburguer.
   *
   * Exemplos:
   * 1X Hamburguer X-tudo artesanal.
   * 1X Hamburguer X-tudo simples.
   */
  std::ostringstream os;
  if (this->_artesanal) {
    os << m_qtd << "X Hamburguer " << _tipo << " artesanal." << std::endl;
    return os.str();
  }
  os << m_qtd << "X Hamburguer " << _tipo << " simples." << std::endl;
  return os.str();
}

Hamburguer::Hamburguer(const std::string& tipo,
                       bool artesanal,
                       int qtd,
                       float valor_unitario) {
  // TODO: Implemente este metodo.
  this->_tipo = tipo;
  this->_artesanal = artesanal;
  m_qtd = qtd;
  m_valor_unitario = valor_unitario;
}