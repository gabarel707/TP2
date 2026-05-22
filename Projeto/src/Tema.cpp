#include "../include/Tema.h"
#include <string>

Tema::Tema() {
    id = -1;
    nome = "NULL";
    tipo = -1;
}

Tema::Tema(int _id, const std::string& _nome, char _tipo) {
    id = _id;
    nome = _nome;
    tipo = _tipo;
}

int Tema::getId() const{
    return id;
}

std::string Tema::getNome() const{
    return nome;
}

char Tema::getTipo() const{
    return tipo;
}