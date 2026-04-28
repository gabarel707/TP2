#include "../include/Tema.h"
#include <string>

// Construtor
// Complexidade: O(1) - Atribuições simples e cópia de string
Tema::Tema(int id, std::string nome, char tipo) {
    this->id = id;
    this->nome = nome;
    this->tipo = tipo;
}

// Destrutor
// Complexidade: O(1) - Nenhuma alocação dinâmica para liberar
Tema::~Tema() {
    // Não há alocação dinâmica para liberar
}

// Getters
// Complexidade: O(1) - Acesso direto ao atributo
int Tema::getId() const {
    return id;
}

// Complexidade: O(1) - Retorno de string (cópia)
std::string Tema::getNome() const {
    return nome;
}

// Complexidade: O(1) - Acesso direto ao atributo
char Tema::getTipo() const {
    return tipo;
}

// Setters
// Complexidade: O(1) - Atribuição de string (cópia)
void Tema::setNome(std::string nome) {
    this->nome = nome;
}

// Complexidade: O(1) - Atribuição simples
void Tema::setTipo(char tipo) {
    this->tipo = tipo;
}

// Métodos utilitários
// Complexidade: O(1) - Comparação simples
bool Tema::isAcademico() const {
    return tipo == 'A';
}

// Complexidade: O(1) - Comparação simples
bool Tema::isPessoal() const {
    return tipo == 'P';
}
