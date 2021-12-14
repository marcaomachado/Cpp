#include "pedido.hpp"
#include <sstream>

Pedido::~Pedido() {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_produtos
   */
  for (auto it = m_produtos.begin(); it != m_produtos.end(); ++it) {
    delete *it;
  }
}

void Pedido::setEndereco(const std::string& endereco) {
  // TODO: Implemente este metodo.
  m_endereco = endereco;
}

float Pedido::calculaTotal() const {
  // TODO: Implemente este metodo.
  float total = 0;
  for (auto it = m_produtos.begin(); it != m_produtos.end(); ++it) {
    total += (*it)->getQtd() * (*it)->getValor();
  }
  return total;
}

void Pedido::adicionaProduto(Produto* p) {
  // TODO: Implemente este metodo.
  m_produtos.emplace_back(p);
}

std::string Pedido::resumo() const {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve percorrer a lista de produtos para criar um resumo completo
   * do pedido. A cada iteracao, utilize o metodo descricao de cada produto para
   * montar o resumo do pedido. Por fim, adicione o endereco de entrega.
   *
   */
  std::string os = "";
  std::ostringstream os_endereco;
  for (auto it = m_produtos.begin(); it != m_produtos.end(); ++it) {
    os.append((*it)->descricao());
  }
  os_endereco << "Endereco: " << m_endereco << std::endl;
  os.append(os_endereco.str());
  return os;
}