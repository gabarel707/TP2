#ifndef DICIONARIO_H
#define DICIONARIO_H

#include "Usuario.h"
#include "Tema.h"
#include "No.h"

class Dicionario {
private:
    Usuario** usuarios;           // Array de ponteiros para usuários
    Tema** temas;                 // Array de ponteiros para temas
    No** nosSocial;               // Array de ponteiros para nós no grafo social
    No** nosTemas;                // Array de ponteiros para nós no grafo de temas
    
    int capacidadeUsuarios;       // Capacidade máxima de usuários
    int capacidadeTemas;          // Capacidade máxima de temas
    int numUsuarios;              // Número atual de usuários
    int numTemas;                 // Número atual de temas
    
public:
    // Construtor
    Dicionario(int capacidadeUsuarios, int capacidadeTemas);
    
    // Destrutor
    ~Dicionario();
    
    // Gerenciamento de usuários
    bool adicionarUsuario(Usuario* usuario);
    bool removerUsuario(int idUsuario);
    Usuario* getUsuario(int idUsuario);
    bool existeUsuario(int idUsuario);
    int getNumUsuarios() const;
    
    // Gerenciamento de temas
    bool adicionarTema(Tema* tema);
    bool removerTema(int idTema);
    Tema* getTema(int idTema);
    bool existeTema(int idTema);
    int getNumTemas() const;
    
    // Gerenciamento de nós no grafo social
    bool adicionarNoSocial(No* no);
    bool removerNoSocial(int idNo);
    No* getNoSocial(int idNo);
    bool existeNoSocial(int idNo);
    
    // Gerenciamento de nós no grafo de temas
    bool adicionarNoTema(No* no);
    bool removerNoTema(int idNo);
    No* getNoTema(int idNo);
    bool existeNoTema(int idNo);
    
    // Métodos utilitários
    bool estaVazio() const;
    void limpar();
};

#endif
