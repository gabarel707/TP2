#include "../include/Grafo.h"
#include <iostream>
#include <cstring>

// Construtor
// Complexidade: O(V) - Onde V é a capacidade máxima de vértices
// Inicialização: O(V) para arrays de nós e representação
Grafo::Grafo(int capacidade, bool direcionado, TipoRepresentacao representacao) {
    this->capacidade = capacidade;
    this->numNos = 0;
    this->direcionado = direcionado;
    this->representacao = representacao;
    
    // Inicializar array de nós - O(V)
    nos = new No*[capacidade];
    for (int i = 0; i < capacidade; i++) {
        nos[i] = nullptr;
    }
    
    // Inicializar representação - O(V) ou O(V²) dependendo do tipo
    if (representacao == LISTA_ADJACENCIA) {
        inicializarListaAdjacencia();
        matrizAdj = nullptr;
    } else {
        inicializarMatrizAdjacencia();
        listaAdj = nullptr;
    }
}

// Destrutor
Grafo::~Grafo() {
    // Liberar nós
    for (int i = 0; i < capacidade; i++) {
        if (nos[i] != nullptr) {
            delete nos[i];
        }
    }
    delete[] nos;
    
    // Liberar representação
    if (representacao == LISTA_ADJACENCIA) {
        liberarListaAdjacencia();
    } else {
        liberarMatrizAdjacencia();
    }
}

// Métodos privados auxiliares
// Complexidade: O(V) - Inicialização de ponteiros
void Grafo::inicializarListaAdjacencia() {
    listaAdj = new NoAdjacencia*[capacidade];
    for (int i = 0; i < capacidade; i++) {
        listaAdj[i] = nullptr;
    }
}

// Complexidade: O(V²) - Inicialização de matriz VxV
void Grafo::inicializarMatrizAdjacencia() {
    matrizAdj = new bool*[capacidade];
    for (int i = 0; i < capacidade; i++) {
        matrizAdj[i] = new bool[capacidade];
        memset(matrizAdj[i], 0, capacidade * sizeof(bool));
    }
}

// Complexidade: O(V + E) - Onde V é número de vértices e E é número de arestas
void Grafo::liberarListaAdjacencia() {
    for (int i = 0; i < capacidade; i++) {
        NoAdjacencia* atual = listaAdj[i];
        while (atual != nullptr) {
            NoAdjacencia* proximo = atual->proximo;
            delete atual;
            atual = proximo;
        }
    }
    delete[] listaAdj;
}

// Complexidade: O(V²) - Liberação de matriz VxV
void Grafo::liberarMatrizAdjacencia() {
    for (int i = 0; i < capacidade; i++) {
        delete[] matrizAdj[i];
    }
    delete[] matrizAdj;
}

// Complexidade: O(V²) - Pior caso: todos os vértices conectados
void Grafo::migrarParaListaAdjacencia() {
    if (representacao == LISTA_ADJACENCIA) return;
    
    inicializarListaAdjacencia();
    
    // Copiar arestas da matriz para a lista - O(V²)
    for (int i = 0; i < capacidade; i++) {
        if (nos[i] != nullptr) {
            for (int j = 0; j < capacidade; j++) {
                if (nos[j] != nullptr && matrizAdj[i][j]) {
                    // Adicionar aresta i -> j na lista
                    NoAdjacencia* novo = new NoAdjacencia(j);
                    novo->proximo = listaAdj[i];
                    listaAdj[i] = novo;
                }
            }
        }
    }
    
    liberarMatrizAdjacencia();
    representacao = LISTA_ADJACENCIA;
}

// Complexidade: O(V + E) - Onde V é número de vértices e E é número de arestas
void Grafo::migrarParaMatrizAdjacencia() {
    if (representacao == MATRIZ_ADJACENCIA) return;
    
    inicializarMatrizAdjacencia();
    
    // Copiar arestas da lista para a matriz - O(V + E)
    for (int i = 0; i < capacidade; i++) {
        if (nos[i] != nullptr) {
            NoAdjacencia* atual = listaAdj[i];
            while (atual != nullptr) {
                matrizAdj[i][atual->idNo] = true;
                atual = atual->proximo;
            }
        }
    }
    
    liberarListaAdjacencia();
    representacao = MATRIZ_ADJACENCIA;
}

// Gerenciamento de nós
// Complexidade: O(1) - Verificação e atribuição
bool Grafo::adicionarNo(No* no) {
    if (no == nullptr || no->getId() >= capacidade || nos[no->getId()] != nullptr) {
        return false;
    }
    
    nos[no->getId()] = no;
    numNos++;
    return true;
}

// Complexidade: O(V + E) - Onde V é número de vértices e E é número de arestas
// Lista: O(V + E) para remover todas as arestas incidentes
// Matriz: O(V) para limpar linha e coluna
bool Grafo::removerNo(int idNo) {
    if (idNo >= capacidade || nos[idNo] == nullptr) {
        return false;
    }
    
    // Remover todas as arestas incidentes ao nó
    if (representacao == LISTA_ADJACENCIA) {
        // Remover arestas de saída - O(grau_saida)
        NoAdjacencia* atual = listaAdj[idNo];
        while (atual != nullptr) {
            NoAdjacencia* proximo = atual->proximo;
            delete atual;
            atual = proximo;
        }
        listaAdj[idNo] = nullptr;
        
        // Remover arestas de entrada - O(V + E)
        for (int i = 0; i < capacidade; i++) {
            if (nos[i] != nullptr) {
                NoAdjacencia* anterior = nullptr;
                NoAdjacencia* atual = listaAdj[i];
                while (atual != nullptr) {
                    if (atual->idNo == idNo) {
                        if (anterior == nullptr) {
                            listaAdj[i] = atual->proximo;
                        } else {
                            anterior->proximo = atual->proximo;
                        }
                        NoAdjacencia* proximo = atual->proximo;
                        delete atual;
                        atual = proximo;
                    } else {
                        anterior = atual;
                        atual = atual->proximo;
                    }
                }
            }
        }
    } else {
        // Matriz de adjacência - O(V)
        for (int i = 0; i < capacidade; i++) {
            matrizAdj[idNo][i] = false;
            matrizAdj[i][idNo] = false;
        }
    }
    
    delete nos[idNo];
    nos[idNo] = nullptr;
    numNos--;
    return true;
}

// Complexidade: O(1) - Acesso direto ao array
No* Grafo::getNo(int idNo) {
    if (idNo >= capacidade) {
        return nullptr;
    }
    return nos[idNo];
}

// Complexidade: O(1) - Verificações constantes
bool Grafo::existeNo(int idNo) {
    return idNo < capacidade && nos[idNo] != nullptr;
}

// Complexidade: O(1) - Acesso direto ao atributo
int Grafo::getNumNos() const {
    return numNos;
}

// Gerenciamento de arestas
// Complexidade: O(grau_saida) - Lista: busca na lista; Matriz: O(1)
bool Grafo::adicionarAresta(int idOrigem, int idDestino) {
    if (!existeNo(idOrigem) || !existeNo(idDestino)) {
        return false;
    }
    
    if (representacao == LISTA_ADJACENCIA) {
        // Verificar se aresta já existe - O(grau_saida)
        NoAdjacencia* atual = listaAdj[idOrigem];
        while (atual != nullptr) {
            if (atual->idNo == idDestino) {
                return false; // Aresta já existe
            }
            atual = atual->proximo;
        }
        
        // Adicionar nova aresta - O(1)
        NoAdjacencia* novo = new NoAdjacencia(idDestino);
        novo->proximo = listaAdj[idOrigem];
        listaAdj[idOrigem] = novo;
        
        // Se não for direcionado, adicionar aresta inversa - O(grau_saida_destino)
        if (!direcionado) {
            NoAdjacencia* novoInverso = new NoAdjacencia(idOrigem);
            novoInverso->proximo = listaAdj[idDestino];
            listaAdj[idDestino] = novoInverso;
        }
    } else {
        // Matriz de adjacência - O(1)
        if (matrizAdj[idOrigem][idDestino]) {
            return false; // Aresta já existe
        }
        
        matrizAdj[idOrigem][idDestino] = true;
        
        // Se não for direcionado, adicionar aresta inversa - O(1)
        if (!direcionado) {
            matrizAdj[idDestino][idOrigem] = true;
        }
    }
    
    return true;
}

// Complexidade: O(grau_saida) - Lista: busca e remoção; Matriz: O(1)
bool Grafo::removerAresta(int idOrigem, int idDestino) {
    if (!existeNo(idOrigem) || !existeNo(idDestino)) {
        return false;
    }
    
    if (representacao == LISTA_ADJACENCIA) {
        // Remover aresta idOrigem -> idDestino - O(grau_saida)
        NoAdjacencia* anterior = nullptr;
        NoAdjacencia* atual = listaAdj[idOrigem];
        while (atual != nullptr) {
            if (atual->idNo == idDestino) {
                if (anterior == nullptr) {
                    listaAdj[idOrigem] = atual->proximo;
                } else {
                    anterior->proximo = atual->proximo;
                }
                delete atual;
                
                // Se não for direcionado, remover aresta inversa - O(grau_saida_destino)
                if (!direcionado) {
                    NoAdjacencia* anteriorInv = nullptr;
                    NoAdjacencia* atualInv = listaAdj[idDestino];
                    while (atualInv != nullptr) {
                        if (atualInv->idNo == idOrigem) {
                            if (anteriorInv == nullptr) {
                                listaAdj[idDestino] = atualInv->proximo;
                            } else {
                                anteriorInv->proximo = atualInv->proximo;
                            }
                            delete atualInv;
                            break;
                        }
                        anteriorInv = atualInv;
                        atualInv = atualInv->proximo;
                    }
                }
                
                return true;
            }
            anterior = atual;
            atual = atual->proximo;
        }
    } else {
        // Matriz de adjacência - O(1)
        if (!matrizAdj[idOrigem][idDestino]) {
            return false; // Aresta não existe
        }
        
        matrizAdj[idOrigem][idDestino] = false;
        
        // Se não for direcionado, remover aresta inversa - O(1)
        if (!direcionado) {
            matrizAdj[idDestino][idOrigem] = false;
        }
        
        return true;
    }
    
    return false;
}

// Complexidade: O(grau_saida) - Lista: busca na lista; Matriz: O(1)
bool Grafo::existeAresta(int idOrigem, int idDestino) {
    if (!existeNo(idOrigem) || !existeNo(idDestino)) {
        return false;
    }
    
    if (representacao == LISTA_ADJACENCIA) {
        // Busca na lista de adjacência - O(grau_saida)
        NoAdjacencia* atual = listaAdj[idOrigem];
        while (atual != nullptr) {
            if (atual->idNo == idDestino) {
                return true;
            }
            atual = atual->proximo;
        }
        return false;
    } else {
        // Acesso direto na matriz - O(1)
        return matrizAdj[idOrigem][idDestino];
    }
}

// Mudança de representação
// Complexidade: O(V²) - Lista→Matriz ou O(V + E) - Matriz→Lista
void Grafo::mudarRepresentacao(TipoRepresentacao novaRepresentacao) {
    if (novaRepresentacao == representacao) {
        return;
    }
    
    if (novaRepresentacao == LISTA_ADJACENCIA) {
        migrarParaListaAdjacencia(); // O(V²)
    } else {
        migrarParaMatrizAdjacencia(); // O(V + E)
    }
}

// Complexidade: O(1) - Acesso direto ao atributo
TipoRepresentacao Grafo::getRepresentacao() const {
    return representacao;
}

// Consultas
// Complexidade: O(grau_saida) - Lista: percorre lista; Matriz: O(V)
void Grafo::getVizinhos(int idNo, int* vizinhos, int& numVizinhos) {
    numVizinhos = 0;
    
    if (!existeNo(idNo)) {
        return;
    }
    
    if (representacao == LISTA_ADJACENCIA) {
        // Percorrer lista de adjacência - O(grau_saida)
        NoAdjacencia* atual = listaAdj[idNo];
        while (atual != nullptr) {
            vizinhos[numVizinhos++] = atual->idNo;
            atual = atual->proximo;
        }
    } else {
        // Percorrer linha da matriz - O(V)
        for (int i = 0; i < capacidade; i++) {
            if (matrizAdj[idNo][i]) {
                vizinhos[numVizinhos++] = i;
            }
        }
    }
}

// Complexidade: O(grau_saida) - Lista: percorre lista; Matriz: O(V)
int Grafo::getGrau(int idNo) {
    if (!existeNo(idNo)) {
        return -1;
    }
    
    if (direcionado) {
        return -1; // Para grafos direcionados, usar getGrauEntrada e getGrauSaida
    }
    
    int grau = 0;
    
    if (representacao == LISTA_ADJACENCIA) {
        // Percorrer lista de adjacência - O(grau_saida)
        NoAdjacencia* atual = listaAdj[idNo];
        while (atual != nullptr) {
            grau++;
            atual = atual->proximo;
        }
    } else {
        // Percorrer linha da matriz - O(V)
        for (int i = 0; i < capacidade; i++) {
            if (matrizAdj[idNo][i]) {
                grau++;
            }
        }
    }
    
    return grau;
}

// Complexidade: O(V + E) - Percorrer todas as listas do grafo
int Grafo::getGrauEntrada(int idNo) {
    if (!existeNo(idNo) || !direcionado) {
        return -1;
    }
    
    int grau = 0;
    
    if (representacao == LISTA_ADJACENCIA) {
        // Percorrer todas as listas procurando arestas que chegam em idNo - O(V + E)
        for (int i = 0; i < capacidade; i++) {
            if (nos[i] != nullptr) {
                NoAdjacencia* atual = listaAdj[i];
                while (atual != nullptr) {
                    if (atual->idNo == idNo) {
                        grau++;
                    }
                    atual = atual->proximo;
                }
            }
        }
    } else {
        // Percorrer coluna da matriz - O(V)
        for (int i = 0; i < capacidade; i++) {
            if (matrizAdj[i][idNo]) {
                grau++;
            }
        }
    }
    
    return grau;
}

// Complexidade: O(grau_saida) - Lista: percorre lista; Matriz: O(V)
int Grafo::getGrauSaida(int idNo) {
    if (!existeNo(idNo) || !direcionado) {
        return -1;
    }
    
    int grau = 0;
    
    if (representacao == LISTA_ADJACENCIA) {
        // Percorrer lista de adjacência - O(grau_saida)
        NoAdjacencia* atual = listaAdj[idNo];
        while (atual != nullptr) {
            grau++;
            atual = atual->proximo;
        }
    } else {
        // Percorrer linha da matriz - O(V)
        for (int i = 0; i < capacidade; i++) {
            if (matrizAdj[idNo][i]) {
                grau++;
            }
        }
    }
    
    return grau;
}

// Métodos utilitários
// Complexidade: O(1) - Acesso direto ao atributo
bool Grafo::isDirecionado() const {
    return direcionado;
}

// Complexidade: O(1) - Comparação simples
bool Grafo::isVazio() const {
    return numNos == 0;
}

// Complexidade: O(V + E) - Percorrer todos os nós e arestas
void Grafo::imprimir() {
    std::cout << "Grafo (" << (direcionado ? "direcionado" : "não direcionado") 
              << ", " << (representacao == LISTA_ADJACENCIA ? "lista" : "matriz") 
              << "):\n";
    
    // Percorrer todos os nós - O(V)
    for (int i = 0; i < capacidade; i++) {
        if (nos[i] != nullptr) {
            std::cout << "Nó " << i << ": ";
            
            if (representacao == LISTA_ADJACENCIA) {
                // Percorrer lista de adjacência - O(grau_saida)
                NoAdjacencia* atual = listaAdj[i];
                while (atual != nullptr) {
                    std::cout << atual->idNo << " ";
                    atual = atual->proximo;
                }
            } else {
                // Percorrer linha da matriz - O(V)
                for (int j = 0; j < capacidade; j++) {
                    if (matrizAdj[i][j]) {
                        std::cout << j << " ";
                    }
                }
            }
            std::cout << "\n";
        }
    }
    // Total: O(V + E) para lista, O(V²) para matriz
}
