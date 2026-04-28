#include "../include/Dicionario.h"

// Construtor
// Complexidade: O(U + T) - Onde U é capacidade de usuários e T é capacidade de temas
// Inicialização: O(U + T) para arrays e ponteiros
Dicionario::Dicionario(int capacidadeUsuarios, int capacidadeTemas) {
    this->capacidadeUsuarios = capacidadeUsuarios;
    this->capacidadeTemas = capacidadeTemas;
    this->numUsuarios = 0;
    this->numTemas = 0;
    
    // Inicializar arrays - O(U + T)
    usuarios = new Usuario*[capacidadeUsuarios];
    temas = new Tema*[capacidadeTemas];
    nosSocial = new No*[capacidadeUsuarios];  // Mesma capacidade de usuários
    nosTemas = new No*[capacidadeUsuarios + capacidadeTemas];  // Usuários + temas
    
    // Inicializar ponteiros como nullptr - O(U + T)
    for (int i = 0; i < capacidadeUsuarios; i++) {
        usuarios[i] = nullptr;
        nosSocial[i] = nullptr;
        nosTemas[i] = nullptr;
    }
    
    for (int i = 0; i < capacidadeTemas; i++) {
        temas[i] = nullptr;
        nosTemas[capacidadeUsuarios + i] = nullptr;
    }
}

// Destrutor
// Complexidade: O(U + T) - Libera todos os arrays e objetos gerenciados
Dicionario::~Dicionario() {
    limpar(); // O(U + T)
    
    delete[] usuarios;  // O(1)
    delete[] temas;      // O(1)
    delete[] nosSocial;  // O(1)
    delete[] nosTemas;   // O(1)
}

// Gerenciamento de usuários
// Complexidade: O(1) - Verificação e atribuição
bool Dicionario::adicionarUsuario(Usuario* usuario) {
    if (usuario == nullptr || usuario->getId() >= capacidadeUsuarios || usuarios[usuario->getId()] != nullptr) {
        return false;
    }
    
    usuarios[usuario->getId()] = usuario;
    numUsuarios++;
    return true;
}

// Complexidade: O(1) - Verificação, deleção e atribuição
bool Dicionario::removerUsuario(int idUsuario) {
    if (idUsuario >= capacidadeUsuarios || usuarios[idUsuario] == nullptr) {
        return false;
    }
    
    delete usuarios[idUsuario];
    usuarios[idUsuario] = nullptr;
    numUsuarios--;
    return true;
}

// Complexidade: O(1) - Acesso direto ao array
Usuario* Dicionario::getUsuario(int idUsuario) {
    if (idUsuario >= capacidadeUsuarios) {
        return nullptr;
    }
    return usuarios[idUsuario];
}

// Complexidade: O(1) - Verificações constantes
bool Dicionario::existeUsuario(int idUsuario) {
    return idUsuario < capacidadeUsuarios && usuarios[idUsuario] != nullptr;
}

// Complexidade: O(1) - Acesso direto ao atributo
int Dicionario::getNumUsuarios() const {
    return numUsuarios;
}

// Gerenciamento de temas
// Complexidade: O(1) - Verificação e atribuição
bool Dicionario::adicionarTema(Tema* tema) {
    if (tema == nullptr || tema->getId() >= capacidadeTemas || temas[tema->getId()] != nullptr) {
        return false;
    }
    
    temas[tema->getId()] = tema;
    numTemas++;
    return true;
}

// Complexidade: O(1) - Verificação, deleção e atribuição
bool Dicionario::removerTema(int idTema) {
    if (idTema >= capacidadeTemas || temas[idTema] == nullptr) {
        return false;
    }
    
    delete temas[idTema];
    temas[idTema] = nullptr;
    numTemas--;
    return true;
}

// Complexidade: O(1) - Acesso direto ao array
Tema* Dicionario::getTema(int idTema) {
    if (idTema >= capacidadeTemas) {
        return nullptr;
    }
    return temas[idTema];
}

// Complexidade: O(1) - Verificações constantes
bool Dicionario::existeTema(int idTema) {
    return idTema < capacidadeTemas && temas[idTema] != nullptr;
}

// Complexidade: O(1) - Acesso direto ao atributo
int Dicionario::getNumTemas() const {
    return numTemas;
}

// Gerenciamento de nós no grafo social
// Complexidade: O(1) - Verificação e atribuição
bool Dicionario::adicionarNoSocial(No* no) {
    if (no == nullptr || no->getId() >= capacidadeUsuarios || nosSocial[no->getId()] != nullptr) {
        return false;
    }
    
    nosSocial[no->getId()] = no;
    return true;
}

// Complexidade: O(1) - Verificação, deleção e atribuição
bool Dicionario::removerNoSocial(int idNo) {
    if (idNo >= capacidadeUsuarios || nosSocial[idNo] == nullptr) {
        return false;
    }
    
    delete nosSocial[idNo];
    nosSocial[idNo] = nullptr;
    return true;
}

// Complexidade: O(1) - Acesso direto ao array
No* Dicionario::getNoSocial(int idNo) {
    if (idNo >= capacidadeUsuarios) {
        return nullptr;
    }
    return nosSocial[idNo];
}

// Complexidade: O(1) - Verificações constantes
bool Dicionario::existeNoSocial(int idNo) {
    return idNo < capacidadeUsuarios && nosSocial[idNo] != nullptr;
}

// Gerenciamento de nós no grafo de temas
// Complexidade: O(1) - Verificação e atribuição
bool Dicionario::adicionarNoTema(No* no) {
    int capacidadeTotal = capacidadeUsuarios + capacidadeTemas;
    
    if (no == nullptr || no->getId() >= capacidadeTotal || nosTemas[no->getId()] != nullptr) {
        return false;
    }
    
    nosTemas[no->getId()] = no;
    return true;
}

// Complexidade: O(1) - Verificação, deleção e atribuição
bool Dicionario::removerNoTema(int idNo) {
    int capacidadeTotal = capacidadeUsuarios + capacidadeTemas;
    
    if (idNo >= capacidadeTotal || nosTemas[idNo] == nullptr) {
        return false;
    }
    
    delete nosTemas[idNo];
    nosTemas[idNo] = nullptr;
    return true;
}

// Complexidade: O(1) - Acesso direto ao array
No* Dicionario::getNoTema(int idNo) {
    int capacidadeTotal = capacidadeUsuarios + capacidadeTemas;
    
    if (idNo >= capacidadeTotal) {
        return nullptr;
    }
    return nosTemas[idNo];
}

// Complexidade: O(1) - Verificações constantes
bool Dicionario::existeNoTema(int idNo) {
    int capacidadeTotal = capacidadeUsuarios + capacidadeTemas;
    return idNo < capacidadeTotal && nosTemas[idNo] != nullptr;
}

// Métodos utilitários
// Complexidade: O(1) - Comparação simples
bool Dicionario::estaVazio() const {
    return numUsuarios == 0 && numTemas == 0;
}

// Complexidade: O(U + T) - Libera todos os objetos gerenciados
void Dicionario::limpar() {
    // Limpar usuários - O(U)
    for (int i = 0; i < capacidadeUsuarios; i++) {
        if (usuarios[i] != nullptr) {
            delete usuarios[i];
            usuarios[i] = nullptr;
        }
    }
    
    // Limpar temas - O(T)
    for (int i = 0; i < capacidadeTemas; i++) {
        if (temas[i] != nullptr) {
            delete temas[i];
            temas[i] = nullptr;
        }
    }
    
    // Limpar nós do grafo social - O(U)
    for (int i = 0; i < capacidadeUsuarios; i++) {
        if (nosSocial[i] != nullptr) {
            delete nosSocial[i];
            nosSocial[i] = nullptr;
        }
    }
    
    // Limpar nós do grafo de temas - O(U + T)
    int capacidadeTotal = capacidadeUsuarios + capacidadeTemas;
    for (int i = 0; i < capacidadeTotal; i++) {
        if (nosTemas[i] != nullptr) {
            delete nosTemas[i];
            nosTemas[i] = nullptr;
        }
    }
    
    numUsuarios = 0;
    numTemas = 0;
}
