#include <iostream>
#include <vector>
#include <stdexcept>
#include <vector>
#include "Cliente.h"
#include "Funcionario.h"
#include "Pessoa.h"
#include "Produto.h"
#include "GerenciadorDados.h"

using namespace std;

int main() {
    cout << "Testes: " << endl;

    //Testando com Clientes
    cout << "\n Gerenciando Clientes" << endl;
    GerenciadorDados<Cliente> gerenciador_clientes;

    Cliente c1(1, "Joao da Silva", "111.222.333-44", "11/07/2025");
    Cliente c2(2, "Italo Nascimento", "555.666.777-88", "11/07/2025");
    
    cout << "Adicionando clientes." << endl;
    gerenciador_clientes.adicionar(c1);
    gerenciador_clientes.adicionar(c2);

    cout << "\nListando todos os clientes:" << endl;
    gerenciador_clientes.listarTodos();

    return 0;
}
