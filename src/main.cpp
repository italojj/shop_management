// Arquivo: src/main.cpp
// Esta é a versão do seu main.cpp, ajustada para funcionar com as nossas classes.

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <stdexcept>

// Incluindo todas as nossas classes
#include "Cliente.h"
#include "Funcionario.h"
#include "Produto.h"
#include "Fornecedor.h"
#include "Venda.h"
#include "ItemVenda.h"
#include "GerenciadorDados.h"

using namespace std;

// --- Protótipos das Funções do Menu ---
void mostrarMenuPrincipal();
void menuClientes(GerenciadorDados<Cliente>& gerenciador);
void menuFuncionarios(GerenciadorDados<Funcionario>& gerenciador);
void menuProdutos(GerenciadorDados<Produto>& gerenciador);
void menuFornecedores(GerenciadorDados<Fornecedor>& gerenciador);
void menuVendas(GerenciadorDados<Venda>& gVendas, GerenciadorDados<Cliente>& gClientes, GerenciadorDados<Funcionario>& gFuncionarios, GerenciadorDados<Produto>& gProdutos);

// Função auxiliar para limpar o buffer de entrada do 'cin', evitando bugs.
void limparBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    // Instanciando um gerenciador para cada entidade do nosso sistema
    GerenciadorDados<Cliente> gerenciadorClientes;
    GerenciadorDados<Funcionario> gerenciadorFuncionarios;
    GerenciadorDados<Produto> gerenciadorProdutos;
    GerenciadorDados<Fornecedor> gerenciadorFornecedores;
    GerenciadorDados<Venda> gerenciadorVendas;

    // Populando o sistema com alguns dados iniciais para facilitar a demonstração
    gerenciadorClientes.adicionar(Cliente(1, "Joao da Silva", "111.222.333-44", "15/07/2025"));
    gerenciadorFuncionarios.adicionar(Funcionario(1, "Carlos Andrade", "888.999.000-11", "Vendedor", 2500.00));
    gerenciadorProdutos.adicionar(Produto(101, "Teclado Mecanico", 250.50, 15));
    gerenciadorFornecedores.adicionar(Fornecedor(1, "Compubras", "11.222.333/0001-44"));

    int opcao;
    do {
        system("clear || cls"); // Limpa a tela do console
        mostrarMenuPrincipal();
        cin >> opcao;

        // Validação de entrada para garantir que o usuário digitou um número
        if (cin.fail()) {
            cout << "Opcao invalida! Por favor, digite um numero." << endl;
            cin.clear();
            limparBuffer();
            opcao = -1; // Força a continuação do loop
        } else {
            limparBuffer(); // Limpa o buffer se a leitura foi bem sucedida
        }

        switch(opcao) {
            case 1:
                menuClientes(gerenciadorClientes);
                break;
            case 2:
                menuFuncionarios(gerenciadorFuncionarios);
                break;
            case 3:
                menuProdutos(gerenciadorProdutos);
                break;
            case 4:
                menuFornecedores(gerenciadorFornecedores);
                break;
            case 5:
                menuVendas(gerenciadorVendas, gerenciadorClientes, gerenciadorFuncionarios, gerenciadorProdutos);
                break;
            case 0:
                cout << "Saindo do sistema..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
                break;
        }

        if (opcao != 0) {
            cout << "\nPressione Enter para continuar...";
            cin.get();
        }

    } while(opcao != 0);

    return 0;
}


void mostrarMenuPrincipal() {
    cout << "╔════════════════════════════╗" << endl;
    cout << "║      SISTEMA DE GESTÃO     ║" << endl;
    cout << "╠════════════════════════════╣" << endl;
    cout << "║ 1 - Gerenciar Clientes     ║" << endl;
    cout << "║ 2 - Gerenciar Funcionarios ║" << endl;
    cout << "║ 3 - Gerenciar Produtos     ║" << endl;
    cout << "║ 4 - Gerenciar Fornecedores ║" << endl;
    cout << "║ 5 - Realizar Venda         ║" << endl;
    cout << "║ 0 - Sair                   ║" << endl;
    cout << "╚════════════════════════════╝" << endl;
    cout << "Escolha uma opção: ";
}


void menuClientes(GerenciadorDados<Cliente>& gerenciador) {
    int opcao;
    do {
        system("clear || cls");
        cout << "\n╔════════════════════╗\n";
        cout << "║  MENU - CLIENTES   ║\n";
        cout << "╠════════════════════╣\n";
        cout << "║ 1 - Adicionar      ║\n";
        cout << "║ 2 - Listar         ║\n";
        cout << "║ 3 - Atualizar      ║\n";
        cout << "║ 4 - Remover        ║\n";
        cout << "║ 0 - Voltar         ║\n";
        cout << "╚════════════════════╝\n";
        cout << "Opção: ";
        cin >> opcao;
        limparBuffer();

        if (opcao == 1) {
            int id; string nome, cpf, dataCadastro;
            cout << "ID: "; cin >> id; limparBuffer();
            cout << "Nome: "; getline(cin, nome);
            cout << "CPF: "; getline(cin, cpf);
            cout << "Data de Cadastro: "; getline(cin, dataCadastro);
            gerenciador.adicionar(Cliente(id, nome, cpf, dataCadastro));
            cout << "Cliente adicionado com sucesso!" << endl;
        } else if (opcao == 2) {
            cout << "\n--- Lista de Clientes ---\n";
            gerenciador.listarTodos();
        } else if (opcao == 3) {
            int id;
            cout << "ID do cliente para atualizar: "; cin >> id; limparBuffer();
            try {
                gerenciador.buscarPorId(id); // Valida se existe
                string nome, cpf, dataCadastro;
                cout << "Novo Nome: "; getline(cin, nome);
                cout << "Novo CPF: "; getline(cin, cpf);
                cout << "Nova Data de Cadastro: "; getline(cin, dataCadastro);
                gerenciador.atualizar(id, Cliente(id, nome, cpf, dataCadastro));
                cout << "Cliente atualizado com sucesso!" << endl;
            } catch (const exception& e) {
                cout << "Erro: " << e.what() << endl;
            }
        } else if (opcao == 4) {
            int id;
            cout << "ID do cliente para remover: "; cin >> id; limparBuffer();
            if (gerenciador.remover(id)) {
                cout << "Cliente removido com sucesso!" << endl;
            } else {
                cout << "Erro: Cliente não encontrado." << endl;
            }
        }
        if(opcao != 0) { cout << "\nPressione Enter para continuar..."; cin.get(); }
    } while (opcao != 0);
}

void menuFuncionarios(GerenciadorDados<Funcionario>& gerenciador) {
    int opcao;
    do {
        system("clear || cls");
        cout << "\n╔══════════════════════╗\n";
        cout << "║  MENU - FUNCIONÁRIOS ║\n";
        cout << "╠══════════════════════╣\n";
        cout << "║ 1 - Adicionar        ║\n";
        cout << "║ 2 - Listar           ║\n";
        cout << "║ 3 - Atualizar        ║\n";
        cout << "║ 4 - Remover          ║\n";
        cout << "║ 0 - Voltar           ║\n";
        cout << "╚══════════════════════╝\n";
        cout << "Opção: ";
        cin >> opcao;
        limparBuffer();

        if (opcao == 1) {
            int id; string nome, cpf, cargo; double salario;
            cout << "ID: "; cin >> id; limparBuffer();
            cout << "Nome: "; getline(cin, nome);
            cout << "CPF: "; getline(cin, cpf);
            cout << "Cargo: "; getline(cin, cargo);
            cout << "Salario: "; cin >> salario; limparBuffer();
            gerenciador.adicionar(Funcionario(id, nome, cpf, cargo, salario));
            cout << "Funcionário adicionado com sucesso!" << endl;
        } else if (opcao == 2) {
            cout << "\n--- Lista de Funcionários ---\n";
            gerenciador.listarTodos();
        } else if (opcao == 3) {
            int id;
            cout << "ID do funcionário para atualizar: "; cin >> id; limparBuffer();
            try {
                gerenciador.buscarPorId(id);
                string nome, cpf, cargo; double salario;
                cout << "Novo Nome: "; getline(cin, nome);
                cout << "Novo CPF: "; getline(cin, cpf);
                cout << "Novo Cargo: "; getline(cin, cargo);
                cout << "Novo Salário: "; cin >> salario; limparBuffer();
                gerenciador.atualizar(id, Funcionario(id, nome, cpf, cargo, salario));
                cout << "Funcionário atualizado com sucesso!" << endl;
            } catch (const exception& e) {
                cout << "Erro: " << e.what() << endl;
            }
        } else if (opcao == 4) {
            int id;
            cout << "ID do funcionário para remover: "; cin >> id; limparBuffer();
            if (gerenciador.remover(id)) {
                cout << "Funcionário removido com sucesso!" << endl;
            } else {
                cout << "Erro: Funcionário não encontrado." << endl;
            }
        }

        if(opcao != 0) { cout << "\nPressione Enter para continuar..."; cin.get(); }
    } while (opcao != 0);
}



void menuProdutos(GerenciadorDados<Produto>& gerenciador) {
    int opcao;
    do {
        system("clear || cls");
        cout << "\n╔══════════════════╗\n";
        cout << "║  MENU - PRODUTOS ║\n";
        cout << "╠══════════════════╣\n";
        cout << "║ 1 - Adicionar    ║\n";
        cout << "║ 2 - Listar       ║\n";
        cout << "║ 3 - Atualizar    ║\n";
        cout << "║ 4 - Remover      ║\n";
        cout << "║ 0 - Voltar       ║\n";
        cout << "╚══════════════════╝\n";
        cout << "Opção: ";
        cin >> opcao;
        limparBuffer();

        if (opcao == 1) {
            int id, estoque; string nome; double preco;
            cout << "ID: "; cin >> id; limparBuffer();
            cout << "Nome: "; getline(cin, nome);
            cout << "Preço: "; cin >> preco;
            cout << "Estoque inicial: "; cin >> estoque; limparBuffer();
            gerenciador.adicionar(Produto(id, nome, preco, estoque));
            cout << "Produto adicionado com sucesso!" << endl;
        } else if (opcao == 2) {
            cout << "\n--- Lista de Produtos ---\n";
            gerenciador.listarTodos();
        } else if (opcao == 3) {
            int id;
            cout << "ID do produto para atualizar: "; cin >> id; limparBuffer();
            try {
                gerenciador.buscarPorId(id);
                string nome; double preco; int estoque;
                cout << "Novo Nome: "; getline(cin, nome);
                cout << "Novo Preço: "; cin >> preco;
                cout << "Novo Estoque: "; cin >> estoque; limparBuffer();
                gerenciador.atualizar(id, Produto(id, nome, preco, estoque));
                cout << "Produto atualizado com sucesso!" << endl;
            } catch (const exception& e) {
                cout << "Erro: " << e.what() << endl;
            }
        } else if (opcao == 4) {
            int id;
            cout << "ID do produto para remover: "; cin >> id; limparBuffer();
            if (gerenciador.remover(id)) {
                cout << "Produto removido com sucesso!" << endl;
            } else {
                cout << "Erro: Produto não encontrado." << endl;
            }
        }

        if(opcao != 0) { cout << "\nPressione Enter para continuar..."; cin.get(); }
    } while (opcao != 0);
}


void menuFornecedores(GerenciadorDados<Fornecedor>& gerenciador) {
    int opcao;
    do {
        system("clear || cls");
        cout << "\n╔═══════════════════════╗\n";
        cout << "║  MENU - FORNECEDORES  ║\n";
        cout << "╠═══════════════════════╣\n";
        cout << "║ 1 - Adicionar         ║\n";
        cout << "║ 2 - Listar            ║\n";
        cout << "║ 3 - Atualizar         ║\n";
        cout << "║ 4 - Remover           ║\n";
        cout << "║ 0 - Voltar            ║\n";
        cout << "╚═══════════════════════╝\n";
        cout << "Opção: ";
        cin >> opcao;
        limparBuffer();

        if (opcao == 1) {
            int id; string nome, cnpj;
            cout << "ID: "; cin >> id; limparBuffer();
            cout << "Nome Fantasia: "; getline(cin, nome);
            cout << "CNPJ: "; getline(cin, cnpj);
            gerenciador.adicionar(Fornecedor(id, nome, cnpj));
            cout << "Fornecedor adicionado com sucesso!" << endl;
        } else if (opcao == 2) {
            cout << "\n--- Lista de Fornecedores ---\n";
            gerenciador.listarTodos();
        } else if (opcao == 3) {
            int id;
            cout << "ID do fornecedor para atualizar: "; cin >> id; limparBuffer();
            try {
                gerenciador.buscarPorId(id);
                string nome, cnpj;
                cout << "Novo Nome Fantasia: "; getline(cin, nome);
                cout << "Novo CNPJ: "; getline(cin, cnpj);
                gerenciador.atualizar(id, Fornecedor(id, nome, cnpj));
                cout << "Fornecedor atualizado com sucesso!" << endl;
            } catch (const exception& e) {
                cout << "Erro: " << e.what() << endl;
            }
        } else if (opcao == 4) {
            int id;
            cout << "ID do fornecedor para remover: "; cin >> id; limparBuffer();
            if (gerenciador.remover(id)) {
                cout << "Fornecedor removido com sucesso!" << endl;
            } else {
                cout << "Erro: Fornecedor não encontrado." << endl;
            }
        }

        if(opcao != 0) { cout << "\nPressione Enter para continuar..."; cin.get(); }
    } while (opcao != 0);
}


void menuVendas(GerenciadorDados<Venda>& gVendas, GerenciadorDados<Cliente>& gClientes, GerenciadorDados<Funcionario>& gFuncionarios, GerenciadorDados<Produto>& gProdutos) {
    system("clear || cls");
    cout << "\n--- Nova Venda ---" << endl;
    
    int idCliente, idFunc;
    string dataVenda; 
    Cliente* clienteVenda = nullptr;
    Funcionario* funcionarioVenda = nullptr;

    try {
        cout << "Clientes disponiveis:" << endl;
        gClientes.listarTodos();
        cout << "Digite o ID do Cliente: ";
        cin >> idCliente;
        clienteVenda = gClientes.buscarPorId(idCliente);

        cout << "\nFuncionarios disponiveis:" << endl;
        gFuncionarios.listarTodos();
        cout << "Digite o ID do Funcionario: ";
        cin >> idFunc;
        funcionarioVenda = gFuncionarios.buscarPorId(idFunc);

        cout << "\nDigite a data da venda (DD/MM/AAAA): ";
        limparBuffer();
        getline(cin, dataVenda);

    } catch (const exception& e) {
        cout << "Erro ao iniciar venda: " << e.what() << endl;
        return; 
    }

    int idVenda = rand(); 
    Venda novaVenda(idVenda, clienteVenda, funcionarioVenda, dataVenda);

    int idProduto, qtdProduto;
    char continuar;
    do {
        system("clear || cls");
        cout << "--- Itens da Venda (ID: " << idVenda << ") ---" << endl;
        cout << novaVenda << endl;
        
        cout << "\n--- Produtos Disponiveis ---" << endl;
        gProdutos.listarTodos();
        cout << "--------------------------" << endl;
        
        cout << "Digite o ID do produto a adicionar: ";
        cin >> idProduto;
        cout << "Digite a quantidade: ";
        cin >> qtdProduto;

        try {
            Produto* produtoVenda = gProdutos.buscarPorId(idProduto);
            novaVenda.adicionarItem(produtoVenda, qtdProduto);
            cout << "Item adicionado com sucesso!" << endl;
        } catch (const exception& e) {
            cout << "\nERRO AO ADICIONAR ITEM: " << e.what() << endl;
        }

        cout << "\nDeseja adicionar outro produto? (s/n): ";
        cin >> continuar;
        limparBuffer();

    } while (continuar == 's' || continuar == 'S');
    
    system("clear || cls");
    cout << "\n--- VENDA FINALIZADA ---" << endl;
    cout << novaVenda << endl;
    gVendas.adicionar(novaVenda);
    cout << "\nVenda registrada no sistema com sucesso!" << endl;
}
