#include "Funcionario.h"
#include <iostream>

using namespace std;

Funcionario::Funcionario(string nome, string cpf, string cargo, double salario) : Pessoa(nome, cpf), cargo(cargo), salario(salario){

}
// Implementação dos getters
string Funcionario::getCargo() const {  
    return this->cargo;
}

double Funcionario::getSalario() const {
    return this->salario;
}
    // atualização para friend
ostream& operator<<(std::ostream& os, const Funcionario& f) {
    os << "Detalhes do Funcionario" << endl;
    os << "Nome: " << f.nome << endl;
    os << "CPF: " << f.cpf << endl;
    os << "Cargo: " << f.cargo << endl;
    os << "Salario: R$ " << f.salario << endl;
}