#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
private:
    int id;
    std::string nome;
    int idade;

public:
    // Construtor
    Usuario(int id, std::string nome, int idade);
    
    // Destrutor
    ~Usuario();
    
    // Getters
    int getId() const;
    std::string getNome() const;
    int getIdade() const;
    
    // Setters
    void setNome(std::string nome);
    void setIdade(int idade);
};

#endif
