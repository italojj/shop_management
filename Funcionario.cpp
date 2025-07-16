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
    // Implementação do método obrigatório exibirDetalhes
void Funcionario::exibirDetalhes() const {
    cout << "Detalhes do Funcionario" << endl;
    cout << "Nome: " << getNome() << endl;
    cout << "CPF: " << getCpf() << endl;
    cout << "Cargo: " << this->cargo << endl;
    cout << "Salario: R$ " << this->salario << endl;
}