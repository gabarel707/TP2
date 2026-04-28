#ifndef NO_H
#define NO_H

#include <string>

// Enum para definir o tipo do nó
enum TipoNo {
    USUARIO,
    TEMA
};

class No {
private:
    int id;
    TipoNo tipo;

public:
    // Construtor
    No(int id, TipoNo tipo);
    
    // Destrutor
    ~No();
    
    // Getters
    int getId() const;
    TipoNo getTipo() const;
    
    // Setters
    void setId(int id);
    void setTipo(TipoNo tipo);
    
    // Métodos utilitários
    bool isUsuario() const;
    bool isTema() const;
    std::string getTipoString() const;
};

#endif
