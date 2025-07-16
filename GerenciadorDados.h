#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

//Template será uma classe genérica. T é apelido para qualquer tipo que usarmos
template <typename T>
class GerenciadorDados {
private:
    std::vector<T> itens;

public:
    void adicionar(const T& item){
        itens.push_back(item); // adiciona ao final do vetor
    }

    void listarTodos() const {
        if (itens.empty()){
            std::cout << "Não há item cadastrado." << std::endl;        
    }       return;
    for (const T& item : itens) {
        std:: cout << item << std::endl;
    }
}
// retorna ponteiro para o objeto para que se possa modificar ele depois
T* buscarPorId(int id){
    for(T& item : itens){ // isso fará com que qualquer tipo T usado terá um metodo publico chamado getID()
        if (item.getId() == id){
            return &item;
        }
    }
    throw std::runtime_error("Erro: O item com esse ID não foi encontrado.");
}

    bool remover(int id){
        for (auto it = itens.begin(); it != itens.end(); ++it){
            if (it->getId() == id){
                itens.erase(it);
                return true;
            }
        }
        return false;
    }

    bool atualizar(int id, const T& novosDados){
        try{
            T* itemExistente = buscarPorId(id);
            *itemExistente = novosDados;
            return true;
        } catch (const std::runtime_error& e){
            std::cerr << e.what() << std::endl;
            return false;
        }
    }
};