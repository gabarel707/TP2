#ifndef DICIONARIO_H
#define DICIONARIO_H
#include "Usuario.h"
#include "Tema.h"
#include "No.h"
#include "ArrayDinamico.h"

class Dicionario {

    ArrayDinamico<Usuario*> users;
    ArrayDinamico<Tema*> temas;

    public:

    void adicionarUsuario(int id, const std::string& nome, int idade);

    void adicionarTema(int id, const std::string& , char tipo);
    
};

#endif