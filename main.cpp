// main.cpp

#include <iostream>
#include <vector> // Incluir para usar o vector
#include "Cliente.h"
#include "Funcionario.h" // Incluir o novo arquivo
#include "Pessoa.h"
#include "Produto.h"

using namespace std;

int main() {
    Produto p1(001, "Celular", 1000.50, 10);
    //teste de sobrecarga
    cout << p1 << endl << endl;

    //teste para remoção
    cout << "Removendo 15 unidades do estoque" << endl;

    //é pra a exceção funcionar
    try{
        p1.removerEstoque(9);
    }
    catch (const out_of_range& e){
        cout << "Erro detectado" << e.what() << endl << endl;
    }

    cout << "Quantidade atual em estoque: " << endl;
    cout << p1 << endl;
    // demonstração
    /*Ciente cliente1(101, "Joao da Silva", "111.222.333-44", "11/07/2025");
    Funcionario func1("Maria Souza", "444.555.666-77", "Gerente", 5000.00);

    cout << "--- DEMONSTRACAO INDIVIDUAL ---" << endl;
    cliente1.exibirDetalhes();
    func1.exibirDetalhes();

    cout << "--- DEMONSTRACAO DE POLIMORFISMO COM LISTA ---" << endl;
    
    // Criando um vetor de ponteiros da classe base Pessoa
    vector<Pessoa*> listaPessoas;
    listaPessoas.push_back(&cliente1); // Adiciona o endereço do objeto cliente
    listaPessoas.push_back(&func1);    // Adiciona o endereço do objeto funcionário

    // Usando um loop para chamar o mesmo método em objetos de tipos diferentes
    for (Pessoa* p : listaPessoas) {
        p->exibirDetalhes();
    }*/

    return 0;
}