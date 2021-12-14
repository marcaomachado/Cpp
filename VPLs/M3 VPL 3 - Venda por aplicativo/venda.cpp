#include "venda.hpp"

#include <iomanip>

Venda::~Venda() {
  // TODO: Implemente este metodo
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_pedidos
   */
  for (auto it = m_pedidos.begin(); it != m_pedidos.end(); ++it) {
    delete *it;
  }
}

void Venda::adicionaPedido(Pedido* p) {
  // TODO: Implemente este metodo
  m_pedidos.emplace_back(p);
}

void Venda::imprimeRelatorio() const {
  // TODO: Implemente este metodo
  /**
   * Aqui voce tem que percorrer a lista de todos os pedidos e imprimir o resumo
   * de cada um. Por ultimo, devera ser exibido o total de venda e a quantidade
   * de pedidos processados.
   */
  float totalVenda = 0;
  int totalPedidosProcessados = 0;
  for (auto it = m_pedidos.begin(); it != m_pedidos.end(); ++it) {
    totalPedidosProcessados++;
    std::cout << "Pedido " << totalPedidosProcessados << std::endl;
    std::cout << (*it)->resumo();
    totalVenda += (*it)->calculaTotal();
  }
  std::cout << "Relatorio de Vendas" << std::endl;
  std::cout << "Total de vendas: R$ " << std::fixed << std::setprecision(2)
            << totalVenda << std::endl;
  std::cout << "Total de pedidos: " << totalPedidosProcessados << std::endl;
}