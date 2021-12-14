#include "japonesa.hpp"
#include <sstream>

std::string Japonesa::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da comida
   * japonesa.
   *
   * Exemplos:
   * 1X Comida japonesa - Combo 1, 4 sushis, 5 temakis e 6 hots.
   * 1X Comida japonesa - Combo 2, 5 sushis, 6 temakis e 8 hots.
   */
  std::ostringstream os;
  os << m_qtd << "X Comida japonesa - " << _combinado << ", " << _sushi
     << " sushis, " << _temaki << " temakis e " << _hot << " hots."
     << std::endl;

  return os.str();
}

Japonesa::Japonesa(const std::string& combinado,
                   int sushis,
                   int temakis,
                   int hots,
                   int qtd,
                   float valor_unitario) {
  // TODO: Implemente este metodo.
  this->_combinado = combinado;
  this->_sushi = sushis;
  this->_temaki = temakis;
  this->_hot = hots;
  m_qtd = qtd;
  m_valor_unitario = valor_unitario;
}