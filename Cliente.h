#pragma once
#include "Pessoa.h"
#include <string>

class Cliente :: public Pessoa {
private:
    int idCLiente;
    std::string dataCadastro;

public:
    Cliente(int id, std::string nome, std:: string cpf, std::string dataCadastro);
    int getIdCliente() const;
    std::string getDatacadastro() const;
    void exibirDetalhes() const override;    
};