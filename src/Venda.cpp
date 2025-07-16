#include "Venda.h"

using namespace std;

Venda::Venda(int id, Cliente* cliente, Funcionario* funcionario, string data)
    : id(id), cliente(cliente), funcionario(funcionario), dataVenda(data) {}

int Venda::getId() const {
    return this->id;
}

void Venda::adicionarItem(Produto* produto, int quantidade) {
    produto->removerEstoque(quantidade); // Esta linha pode lançar uma exceção se o estoque for insuficiente.
    
    
    ItemVenda novoItem(produto, quantidade); //Adiciona o novo item se der certo a remoção

    this->itensDaVenda.push_back(novoItem); //Adiciona o novo item ao "carrinho" da venda
}

double Venda::calcularTotal() const {
    double total = 0.0;
    // Irá iterar sobre cada ItemVenda na lista  somando o seu subtotal ao total geral da venda.
    for (const auto& item : this->itensDaVenda) {
        total += item.getSubtotal();
    }
    return total;
}

ostream& operator<<(ostream& os, const Venda& v) {
    os << "NOTA FISCAL " << endl;
    os << "ID da Venda: " << v.id << " | Data: " << v.dataVenda << endl;
    os << "Cliente: " << v.cliente->getNome() << " (CPF: " << v.cliente->getCpf() << ")" << endl;
    os << "Atendido por: " << v.funcionario->getNome() << endl;
    os << endl;
    os << "ITENS:" << endl;
    for (const auto& item : v.itensDaVenda) {
        os << item << endl;
    }
    os << "TOTAL DA VENDA: R$ " << v.calcularTotal() << endl;
    return os;
}