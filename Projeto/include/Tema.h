#ifndef TEMA_H
#define TEMA_H

#include <string>

class Tema {
private:
    int id;
    std::string nome;
    char tipo; // 'A' para acadêmico, 'P' para pessoal

public:
    // Construtor
    Tema(int id, std::string nome, char tipo);
    
    // Destrutor
    ~Tema();
    
    // Getters
    int getId() const;
    std::string getNome() const;
    char getTipo() const;
    
    // Setters
    void setNome(std::string nome);
    void setTipo(char tipo);
    
    // Métodos utilitários
    bool isAcademico() const;
    bool isPessoal() const;
};

#endif
