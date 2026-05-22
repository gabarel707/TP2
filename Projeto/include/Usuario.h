#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
private:
    int id;
    std::string nome;
    int idade;

public:
    Usuario();
    Usuario(int _id, const std::string& _nome, int _idade);

    int getId() const;
    std::string getNome() const;
    int getIdade() const;
};

#endif
