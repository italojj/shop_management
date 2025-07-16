#include "ItemVenda.h"

using namespace std;

// Implementação do construtor de ItemVenda.
ItemVenda::ItemVenda(Produto* produto, int quantidade) : produtoVendido(produto), quantidade(quantidade) {
    // é importante salvar a operação como precoUnitarioSalvo para que o valor do item não mude após implementada essa lógica
    this->precoUnitarioSalvo = produto->getPrecoVenda();
}


double ItemVenda::getSubtotal() const {
    return this->quantidade * this->precoUnitarioSalvo;
}

ostream& operator<<(ostream& os, const ItemVenda& iv) {
    // Usa o ponteiro 'produtoVendido' para acessar o nome do produto original.
    os << "Produto: " << iv.produtoVendido->getNome() 
       << "Qtd: " << iv.quantidade 
       << "Preco Unit.: R$ " << iv.precoUnitarioSalvo
       << "Subtotal: R$ " << iv.getSubtotal();
    return os;
}