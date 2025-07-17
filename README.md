#  Sistema de Gestão de Loja em C++

Este projeto é uma aplicação de console desenvolvida em C++ como trabalho final para a disciplina de Linguagem de Programação I. O sistema simula as operações de gerenciamento de uma pequena loja, permitindo o controle de clientes, funcionários, produtos, fornecedores e o registro de vendas.

O principal objetivo foi aplicar de forma prática os conceitos fundamentais da Programação Orientada a Objetos (POO), criando um software bem estruturado e modular.

##  Tabela de Conteúdos
- Funcionalidades
- Conceitos de POO Aplicados
- Estrutura do Projeto
- Como Compilar e Executar
- Visão Geral das Classes
- Autor

##  Funcionalidades
O sistema oferece uma interface de menu baseada em texto que permite ao usuário:

### Gerenciamento de Entidades (CRUD)
- **Clientes**: Adicionar, listar, atualizar e remover clientes.
- **Funcionários**: Adicionar e listar funcionários.
- **Produtos**: Adicionar e listar produtos, com controle de estoque.
- **Fornecedores**: Adicionar e listar fornecedores.

### Registro de Vendas
- Uma interface passo a passo para criar uma nova venda.
- Seleção de cliente e funcionário para a venda.
- Adição de múltiplos produtos ao "carrinho" da venda.
- Validação de estoque em tempo real com tratamento de erros.
- Geração de uma "nota fiscal" formatada ao final da venda.

## Conceitos de POO Aplicados
Este projeto foi cuidadosamente estruturado para atender a todos os requisitos da avaliação, demonstrando a aplicação dos seguintes conceitos:

- **Herança**: Classe base `Pessoa`, da qual `Cliente` e `Funcionario` herdam.
- **Polimorfismo**: Uso de funções `virtual` para comportamentos específicos.
- **Encapsulamento**: Atributos `private`/`protected`, com acesso controlado via métodos `public`.
- **Templates (Classes Genéricas)**: `GerenciadorDados<T>` para lógica de CRUD reutilizável.

### Relacionamentos de Classes
- **1:1**: Uma `Venda` é associada a um `Funcionario`.
- **1:N**: Uma `Venda` contém múltiplos `ItemVenda`.
- **N:M**: Relacionamento `Venda`-`Produto` mediado por `ItemVenda`.

- **Tratamento de Exceções**: `try-catch` para controlar erros (ex: estoque insuficiente).
- **Sobrecarga de Operadores**: `operator<<` sobrecarregado para facilitar impressão com `std::cout`.

##  Estrutura do Projeto

```
SHOP_MANAGEMENT/
│
├── include/              # Arquivos de cabeçalho (.h)
│   ├── Cliente.h
│   ├── Funcionario.h
│   ├── Produto.h
│   └── ...
│
├── src/                  # Arquivos de implementação (.cpp)
│   ├── main.cpp
│   ├── Cliente.cpp
│   ├── Funcionario.cpp
│   └── ...
│
├── build/                # (gerado automaticamente) arquivos .o
│
├── Makefile              # Script de compilação
├── GerenciarLoja.exe     # (gerado automaticamente) executável
└── README.md             # Este arquivo
```

##  Como Compilar e Executar

### Passo 1: Clone o Repositório
```bash
git clone https://github.com/italojj/shop_management
cd shop_management
```

### Passo 2: Compile o Projeto
```bash
make
```

### Passo 3: Execute o Programa
```bash
./GerenciarLoja.exe
```

### Passo 4: Limpar os Arquivos de Compilação (Opcional)
```bash
make clean
```

##  Visão Geral das Classes
- `Pessoa`: Classe base abstrata para `Cliente` e `Funcionario`.
- `Cliente`: Possui ID e data de cadastro.
- `Funcionario`: Possui cargo e salário.
- `Produto`: Contém preço e quantidade.
- `Fornecedor`: Representa o fornecedor de produtos.
- `ItemVenda`: Relaciona produto e quantidade com uma venda.
- `Venda`: Representa uma venda completa.
- `GerenciadorDados<T>`: Template para operações CRUD genéricas.

##  Autores
- Autores: Italo Nascimento e Alvaro Feliphe
- Universidade: Universidade Federal do Rio Grande do Norte
- Curso: Tecnologia da Informação
