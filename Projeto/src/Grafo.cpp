#include "Grafo.h"

Grafo::Grafo(){
    modo_grafo = 'N';
    tipo_grafo = 'N';
    quantidadeTemas = 0;
    quantidadeUsuarios = 0;
}

int Grafo::adiciona_no(char tipo_no){
    if(modo_grafo == 'M'){

        if(matriz == nullptr){ // Se a matriz for nula, inicializa com 1x1
            matriz = new bool[1 * 1];
            matriz[0] = 0;
        }

        if(tipo_grafo == 'U'){
            int q = ++quantidadeUsuarios;
            
            // Cria uma matriz com uma dimensão a mais e deleta a anterior
            bool* new_matriz = new bool[q * q];

            for(int i = 0; i < q*q; i++){
                new_matriz[i] = 0; // Inicializa a nova matriz com 0
            }
            
            for(int i = 0; i < q - 1; i++){
                for(int j = 0; j < q - 1; j++){
                    new_matriz[i * q + j] = matriz[i * q + j]; // Copia a matriz anterior
                }
                
                new_matriz[i * q + q] = 0; // Adiciona uma coluna vazia
            }
            
            delete[] matriz; // Deleta a matriz anterior
            matriz = new_matriz;

        }else if(tipo_grafo == 'T'){
            
            // Se o tipo do no for T, adiciona nova linha para tema
            if(tipo_no == 'T'){
                int t = ++quantidadeTemas;
                int u = quantidadeUsuarios;
                // Cria uma matriz com uma dimensão a mais e deleta a anterior
                bool* new_matriz = new bool[t * u];

                for(int i = 0; i < t - 1; i++){
                    for(int j = 0; j < u; j++){
                        new_matriz[i * u + j] = matriz[i * u + j]; // Copia a matriz anterior
                    } 
                }
                
                for(int i = 0; i < u; i++){
                    new_matriz[(t-1) * u + i] = 0; // Adiciona uma linha vazia
                }
                
                delete[] matriz; // Deleta a matriz anterior
                matriz = new_matriz;
                
            }
            // Se o tipo do no for U, adiciona nova coluna para usuario
            else if(tipo_no == 'U'){
                int t = quantidadeTemas;
                int u = ++quantidadeUsuarios;
                // Cria uma matriz com uma dimensão a mais e deleta a anterior
                bool* new_matriz = new bool[t * u];
                
                for(int i = 0; i < t; i++){
                    for(int j = 0; j < u - 1; j++){
                        new_matriz[i * u + j] = matriz[i * u + j]; // Copia a matriz anterior
                    }
                }

                for(int i = 0; i < t; i++){
                    new_matriz[i * u + (u - 1)] = 0; // Adiciona uma coluna vazia
                }
                
                delete[] matriz; // Deleta a matriz anterior
                matriz = new_matriz;
            }
        }
    }
    
    if(tipo_no == 'T'){
        return quantidadeTemas-1;
    }else if(tipo_no == 'U'){
        return quantidadeUsuarios-1;
    }
    return -1;
}

void Grafo::inicializaMatriz(){
    matriz = nullptr;
}

void Grafo::setTipo(char _tipo){
    tipo_grafo = _tipo;
}

void Grafo::setModo(char _modo){
    modo_grafo = _modo;
}