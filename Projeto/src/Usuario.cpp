#include "../include/Usuario.h"
#include <string>

// Construtor
// Complexidade: O(1) - Atribuições simples e cópia de string
Usuario::Usuario(int id, std::string nome, int idade) {
    this->id = id;
    this->nome = nome;
    this->idade = idade;
}

// Destrutor
// Complexidade: O(1) - Nenhuma alocação dinâmica para liberar
Usuario::~Usuario() {
    // Não há alocação dinâmica para liberar
}

// Getters
// Complexidade: O(1) - Acesso direto ao atributo
int Usuario::getId() const {
    return id;
}

// Complexidade: O(1) - Retorno de string (cópia)
std::string Usuario::getNome() const {
    return nome;
}

// Complexidade: O(1) - Acesso direto ao atributo
int Usuario::getIdade() const {
    return idade;
}

// Setters
// Complexidade: O(1) - Atribuição de string (cópia)
void Usuario::setNome(std::string nome) {
    this->nome = nome;
}

// Complexidade: O(1) - Atribuição simples
void Usuario::setIdade(int idade) {
    this->idade = idade;
}
