#pragma once
#include "Pessoa.h"
#include <string>

class Cliente : public Pessoa {
private:
    int idCliente;
    std::string dataCadastro;

public:
    Cliente(int id, std::string nome, std:: string cpf, std::string dataCadastro);
    int getIdCliente() const;
    std::string getDatacadastro() const;
    friend std::ostream& operator<<(std::ostream& os, const Cliente& c); //função friend para sobrecarga e funcionamento do make
};