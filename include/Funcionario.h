#pragma once

#include "Pessoa.h"
#include <string>

class Funcionario : public Pessoa{

private: 
    int idFuncionario;
    std::string cargo;
    double salario;

public:
    Funcionario(int id, std::string nome, std::string cpf, std::string cargo, double salario); // construtor para funcionarios

    //Getters da classe funcionario, atributos específicos
    int getId() const;
    std::string getCargo() const;
    double getSalario() const;
    void exibirDetalhes() const override;
    friend std::ostream& operator<<(std::ostream& os, const Funcionario& f);
};