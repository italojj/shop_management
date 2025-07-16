#pragma once

#include <string>
#include <iostream>

class Fornecedor {
private:
    int id;
    std::string nomeFantasia;
    std::string cnpj;

public:
    //construtor
    Fornecedor(int id, std::string nome, std::string cnpj);
    int getId()const; //getter publico que lê o id do fornecedor 
    friend std::ostream& operator<<(std::ostream& os, const Fornecedor& f);
};