#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Cliente.h"
#include "Funcionario.h"
#include "ItemVenda.h"

/* A classe Venda orquestra a transação de venda completa, com isso ela estará unindo as outras entidades 
e demonstrando os relacionamentos 1:1, 1:N e N:M. */

class Venda {
private:
    int id;
    std::string dataVenda;
    // Ponteiro para o Cliente. Demonstra o relacionamento 1:N (Um cliente pode ter N vendas).
    Cliente* cliente;
    // Ponteiro para o Funcionário. Demonstra o relacionamento 1:1 (Uma venda é feita por 1 funcionário).
    Funcionario* funcionario;
    // Vetor de ItemVenda. Demonstra o relacionamento 1:N (Uma venda tem N itens).
    std::vector<ItemVenda> itensDaVenda;

public:
    Venda(int id, Cliente* cliente, Funcionario* funcionario, std::string data);
    int getId() const;
    // Adiciona um novo item (Produto e quantidade) à lista de itens desta venda.
    void adicionarItem(Produto* produto, int quantidade);
    double calcularTotal() const; // soma tudo
    
    friend std::ostream& operator<<(std::ostream& os, const Venda& v);
};