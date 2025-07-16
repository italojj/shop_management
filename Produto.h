#pragma once

#include <string>
#include <iostream>

class Produto {
private:
    int id;
    std::string nome;
    double precoVenda;
    int quantidadeEstoque;

public:
    // Construtor
    Produto(int id, std::string nome, double precoVenda, int quantidadeEstoque);

    // Getters
    int getId() const;
    std::string getNome() const;
    double getPrecoVenda() const;
    int getQuantidadeEstoque() const;

    // Setters
    void setPrecoVenda(double novoPreco);

    // Métodos para manipular o estoque
    void adicionarEstoque(int quantidade);
    void removerEstoque(int quantidade); // Esta função deve poder lançar uma exceção

    // Sobrecarga do operador << que facilita a exibição
    // A palavra 'friend' permite que esta função acesse os membros privados de Produto.
    friend std::ostream& operator<<(std::ostream& os, const Produto& produto);
};