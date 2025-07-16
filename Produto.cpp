#include "Produto.h"
#include <stdexcept>

using namespace std;

Produto::Produto(int id, string nome, double precoVenda, int quantidadeEstoque) : id(id), nome(nome), precoVenda(precoVenda), quantidadeEstoque(quantidadeEstoque){

}

int Produto::getId() const {return this->id;}
string Produto::getNome() const {return this->nome;}
double Produto::getPrecoVenda() const {return this->precoVenda;}
int Produto::getQuantidadeEstoque() const {return this->quantidadeEstoque;}
