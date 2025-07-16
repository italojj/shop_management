#include "Produto.h"
#include <stdexcept>

using namespace std;

Produto::Produto(int id, string nome, double precoVenda, int quantidadeEstoque) : id(id), nome(nome), precoVenda(precoVenda), quantidadeEstoque(quantidadeEstoque){

}

int Produto::getId() const {return this->id;}
string Produto::getNome() const {return this->nome;}
double Produto::getPrecoVenda() const {return this->precoVenda;}
int Produto::getQuantidadeEstoque() const {return this->quantidadeEstoque;}

void Produto::setPrecoVenda(double novoPreco){
    if (novoPreco > 0){
        this->precoVenda = novoPreco;
    }
}
void Produto::adicionarEstoque(int quantidade){
    if (quantidade > 0){
        this->quantidadeEstoque += quantidade;
    }
}

void Produto::removerEstoque(int quantidade){
    if (quantidade > this-> quantidadeEstoque){
        throw out_of_range("Estoque e insuficiente para remover a quantidade solicitada.");
    }
    this->quantidadeEstoque -= quantidade;
}

//função 'friend' com sobrecarga, usa-se o friend para não ter nenhum problema de compatibilidade, já que ela pode acessar o private e o public
ostream& operator<<(ostream& os, const Produto& produto) {
    os << "Detalhes do Produto" << endl;
    os << "ID: " << produto.id << endl;
    os << "Nome: " << produto.nome << endl;
    os << "Preco: R$ " << produto.precoVenda << endl;
    os << "Estoque: " << produto.quantidadeEstoque << " unidades" << endl;
    return os;
}