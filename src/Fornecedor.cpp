#include "Fornecedor.h"

using namespace std;

Fornecedor::Fornecedor(int id, string nome, string cnpj) : id(id), nomeFantasia(nome), cnpj(cnpj){

}

int Fornecedor::getId() const{
    return this->id;
}

ostream& operator<<(ostream& os, const Fornecedor& f){
    os << "ID: " << f.id <<  "Fornecedor: " << f.nomeFantasia << "(CNPJ: " << f.cnpj << ")";
    return os;
}