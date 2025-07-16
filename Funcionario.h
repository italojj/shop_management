#pragma once

#include "Pessoa.h"
#include <string>

class Funcionario : public Pessoa{

private: 
    std::string cargo;
    double salario;

public:
    Funcionario(std::string nome, std::string cpf, std::string cargo, double salario); // construtor

    //Getters da classe funcionario, atributos específicos
    std::string getCargo() const;
    double getSalario() const;

    void exibirDetalhes() const override;
};