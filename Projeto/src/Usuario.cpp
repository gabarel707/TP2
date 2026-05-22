#include "Usuario.h"

Usuario::Usuario(){
    id = -1;
    nome = "NULL";
    idade = -1;
}

Usuario::Usuario(int _id, const std::string& _nome, int _idade){
    id = _id;
    nome = _nome;
    idade = _idade;
}

int Usuario::getId() const{
    return id;
}
std::string Usuario::getNome() const{
    return nome;
}
int Usuario::getIdade() const{
    return idade;
}