#pragma once
#include "Produto.h"
#include <iostream>

// A classe ItemVenda irá representar uma linha de uma nota fiscal
// Ela serve como uma junção que há entre um objeto Venda e um objeto Produto
class ItemVenda {
private:
    Produto* produtoVendido;   // Ponteiro para o objeto Produto original do estoque.
    int quantidade;            
    double precoUnitarioSalvo; 

public:
    // Construtor que recebe um ponteiro para o produto e a quantidade vendida.
    ItemVenda(Produto* produto, int quantidade);

   
    double getSubtotal() const; // será quantidade * valor salvo

    // Função friend para que o cout iprima corretamente
    friend std::ostream& operator<<(std::ostream& os, const ItemVenda& iv);
};