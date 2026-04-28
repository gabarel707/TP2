#ifndef GRAFO_H
#define GRAFO_H

#include "No.h"

// Enum para definir o tipo de representação
enum TipoRepresentacao {
    LISTA_ADJACENCIA,
    MATRIZ_ADJACENCIA
};

// Estrutura para lista de adjacência
struct NoAdjacencia {
    int idNo;
    NoAdjacencia* proximo;
    
    NoAdjacencia(int id) : idNo(id), proximo(nullptr) {}
};

class Grafo {
private:
    No** nos;                    // Array de ponteiros para nós
    NoAdjacencia** listaAdj;     // Lista de adjacência
    bool** matrizAdj;            // Matriz de adjacência
    int numNos;                  // Número de nós
    int capacidade;              // Capacidade máxima de nós
    bool direcionado;           // Indica se o grafo é direcionado
    TipoRepresentacao representacao; // Tipo de representação atual
    
    // Métodos privados auxiliares
    void inicializarListaAdjacencia();
    void inicializarMatrizAdjacencia();
    void liberarListaAdjacencia();
    void liberarMatrizAdjacencia();
    void migrarParaListaAdjacencia();
    void migrarParaMatrizAdjacencia();
    
public:
    // Construtor
    Grafo(int capacidade, bool direcionado, TipoRepresentacao representacao = LISTA_ADJACENCIA);
    
    // Destrutor
    ~Grafo();
    
    // Gerenciamento de nós
    bool adicionarNo(No* no);
    bool removerNo(int idNo);
    No* getNo(int idNo);
    bool existeNo(int idNo);
    int getNumNos() const;
    
    // Gerenciamento de arestas
    bool adicionarAresta(int idOrigem, int idDestino);
    bool removerAresta(int idOrigem, int idDestino);
    bool existeAresta(int idOrigem, int idDestino);
    
    // Mudança de representação
    void mudarRepresentacao(TipoRepresentacao novaRepresentacao);
    TipoRepresentacao getRepresentacao() const;
    
    // Consultas
    void getVizinhos(int idNo, int* vizinhos, int& numVizinhos);
    int getGrau(int idNo);  // Para grafos não direcionados
    int getGrauEntrada(int idNo);  // Para grafos direcionados
    int getGrauSaida(int idNo);   // Para grafos direcionados
    
    // Métodos utilitários
    bool isDirecionado() const;
    bool isVazio() const;
    void imprimir();
};

#endif
