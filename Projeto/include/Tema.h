#ifndef TEMA_H
#define TEMA_H

#include <string>

class Tema {
private:
    int id;
    std::string nome;
    char tipo;

public:
    Tema();
    Tema(int _id, const std::string& _nome, char _tipo);

    int getId() const;
    std::string getNome() const;
    char getTipo() const;
};

#endif
