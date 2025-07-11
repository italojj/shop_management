#pragma once
#include <string>

class Pessoa{

protected:
    std::string nome;
    std::string cpf;
public:
    Pessoa(std::string nome, string cpf);   //Construtor para a classe pessoa 
    virtual ~Pessoa(){}                     //Destrutor virtual que garante a exclusão correta no polimorfismo
    std::string getNome()const;
    std::string getCpf()const;
    virtual void exibirDetalhes()const = 0; //Função que força classes filhas a implementarem sua própia versão do método
};