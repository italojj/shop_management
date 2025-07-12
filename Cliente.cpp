#include "Cliente.h"
#include <iostream>

using namespace std;

Cliente::Cliente(int id, string nome, string cpf, string dataCadastro) : Pessoa(nome,cpf), idCliente(id), dataCadastro(dataCadastro){

}

int Cliente::getIdCliente() const{
    return this->idCliente;
}
string Cliente::getDatacadastro() const{
    return this->dataCadastro;
}

void Cliente::exibirDetalhes() const{
    cout << "Detalhes do cliente: " << endl;
    cout << "ID do cliente: " << this->idCliente << endl;
    cout << "Nome: " << getNome() << endl;
    cout << "CPF: " << getCpf() <<endl;
    cout << "Data de cadastro" << this-> dataCadastro << endl;
}