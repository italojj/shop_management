#include "Funcionario.h"
#include <iostream>

using namespace std;

Funcionario::Funcionario(int id, string nome, string cpf, string cargo, double salario)
    : Pessoa(nome, cpf), idFuncionario(id), cargo(cargo), salario(salario) {}
// Implementação dos getters
int Funcionario::getId() const { 
    return this->idFuncionario;
} 
string Funcionario::getCargo() const {  
    return this->cargo;
}

double Funcionario::getSalario() const {
    return this->salario;
}

void Funcionario::exibirDetalhes() const{
    cout << *this;
}
    // atualização para friend
ostream& operator<<(std::ostream& os, const Funcionario& f) {
    os << "Detalhes do Funcionario" << endl;
    os << "Nome: " << f.nome << endl;
    os << "CPF: " << f.cpf << endl;
    os << "Cargo: " << f.cargo << endl;
    os << "Salario: R$ " << f.salario << endl;
    return os;
}