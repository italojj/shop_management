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
//implementando função friend
ostream& operator<<(ostream& os, const Cliente& c){
    os << "Detalhes do cliente: " << endl;
    os << "ID do cliente: " << c.idCliente << endl;
    os << "Nome: " << c.nome << endl;
    os << "CPF: " << c.cpf <<endl;
    os << "Data de cadastro: " << c.dataCadastro << endl;
    return os;
}