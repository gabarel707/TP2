#ifndef ARRAYDINAMICO_H
#define ARRAYDINAMICO_H
#include <iostream>

template <typename T>
class ArrayDinamico {
    T* array;
    int quantidade;
    int capacidade;
    
    public:
    
    ArrayDinamico();
    
    void adicionar_elemento(T item);
    
};

template <typename T>
ArrayDinamico<T>::ArrayDinamico(){
    array = new T[100];
    quantidade = 0;
    capacidade = 100;
}

template <typename T>
void ArrayDinamico<T>::adicionar_elemento(T item){
    // Redimensionando o array lista 
    if(quantidade >= capacidade){
        int nova_capacidade = capacidade * 2;
        T* novo_array = new T[nova_capacidade];
        
        for(int i = 0; i < quantidade; i++){
            novo_array[i] = array[i];
        }
        
        delete[] array;
        
        array = novo_array;
        capacidade = nova_capacidade;
    }
    
    array[quantidade] = item;
}

#endif