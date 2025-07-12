#include <iostream>
#include "Cliente.h"
#include "Pessoa.h"

using namespace std;

int main() {
    cout << "Criando um objeto Cliente" << endl;
    
    Cliente cliente1(101, "Joao da Silva", "111.222.333-44", "11/07/2025");
    cliente1.exibirDetalhes();

    cout << endl;
    cout << "Demonstrando o polimorfismo com um ponteiro de Pessoa:" << endl;

    Pessoa* ponteiroPessoa = &cliente1;    
    ponteiroPessoa->exibirDetalhes();

    return 0;
}