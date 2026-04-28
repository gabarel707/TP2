#include "../include/No.h"
#include <string>

// Construtor
// Complexidade: O(1) - Atribuições simples
No::No(int id, TipoNo tipo) {
    this->id = id;
    this->tipo = tipo;
}

// Destrutor
// Complexidade: O(1) - Nenhuma alocação dinâmica para liberar
No::~No() {
    // Não há alocação dinâmica para liberar
}

// Getters
// Complexidade: O(1) - Acesso direto ao atributo
int No::getId() const {
    return id;
}

// Complexidade: O(1) - Acesso direto ao atributo
TipoNo No::getTipo() const {
    return tipo;
}

// Setters
// Complexidade: O(1) - Atribuição simples
void No::setId(int id) {
    this->id = id;
}

// Complexidade: O(1) - Atribuição simples
void No::setTipo(TipoNo tipo) {
    this->tipo = tipo;
}

// Métodos utilitários
// Complexidade: O(1) - Comparação simples
bool No::isUsuario() const {
    return tipo == USUARIO;
}

// Complexidade: O(1) - Comparação simples
bool No::isTema() const {
    return tipo == TEMA;
}

// Complexidade: O(1) - Comparações e retorno de string constante
std::string No::getTipoString() const {
    if (tipo == USUARIO) {
        return "USUARIO";
    } else {
        return "TEMA";
    }
}
