#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <ArrayDinamico.h>
#include "Dicionario.h"
#include "No.h"

class Grafo {
    // Tipo do Grafo - 'U' para usuarios e 'T' para temas
    char tipo_grafo;
    // Modo de representação interna (M ou L)
    char modo_grafo;

    // Lista de Adjacência
    //ArrayDinamico<No*> lista;
    // Matriz de Adjacência
    bool* matriz;
    
    // Quantidade de nós no grafo
    int quantidadeTemas;
    int quantidadeUsuarios;

    public:

    Grafo();

    int adiciona_no(char tipo_no);

    void setTipo(char _tipo);

    void setModo(char _modo);

    void inicializaMatriz();

};

#endif