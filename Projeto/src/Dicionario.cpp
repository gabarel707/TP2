#include "Dicionario.h"
#include "Usuario.h"
#include "Tema.h"

void Dicionario::adicionarUsuario(int id, const std::string& nome, int idade){
    Usuario* user = new Usuario(id, nome, idade);
    users.adicionar_elemento(user);
}

void Dicionario::adicionarTema(int id, const std::string& nome, char tipo){
    Tema* tema = new Tema(id, nome, tipo);
    temas.adicionar_elemento(tema);
}