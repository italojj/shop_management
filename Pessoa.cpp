#include "Pessoa.h"
#include <iostream>

using namespace std;

Pessoa::Pessoa(string nome, string cpf) : nome(nome), cpf(cpf){

}

string Pessoa::getNome() const{
    return this->nome;
}
string Pessoa::getCpf() const{
    return this->cpf;
}