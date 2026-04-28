#include "../include/Usuario.h"
#include "../include/Tema.h"
#include "../include/No.h"
#include "../include/Grafo.h"
#include "../include/Dicionario.h"
#include <iostream>

int main() {
    std::cout << "Testando TADS do projeto de rede social academica\n";
    
    // Testar TAD Usuario
    std::cout << "\nTestando Usuario:\n";
    Usuario* user1 = new Usuario(0, "Ana", 20);
    std::cout << "Usuario criado: " << user1->getNome() 
              << ", ID: " << user1->getId() 
              << ", Idade: " << user1->getIdade() << "\n";
    
    // Testar TAD Tema
    std::cout << "\nTestando Tema:\n";
    Tema* tema1 = new Tema(0, "Inteligencia Artificial", 'A');
    std::cout << "Tema criado: " << tema1->getNome() 
              << ", ID: " << tema1->getId() 
              << ", Tipo: " << tema1->getTipo() 
              << " (" << (tema1->isAcademico() ? "Academico" : "Pessoal") << ")\n";
    
    // Testar TAD Dicionario
    std::cout << "\nTestando Dicionario:\n";
    Dicionario* dicionario = new Dicionario(10, 10);
    dicionario->adicionarUsuario(user1);
    dicionario->adicionarTema(tema1);
    
    // Criar nós para o dicionário
    No* noUsuario = new No(0, USUARIO);
    No* noTema = new No(0, TEMA);
    dicionario->adicionarNoSocial(noUsuario);
    dicionario->adicionarNoTema(noTema);
    
    // Testar TAD No
    std::cout << "\nTestando No:\n";
    std::cout << "No usuario: " << noUsuario->getId() 
              << ", Tipo: " << noUsuario->getTipoString() << "\n";
    std::cout << "No tema: " << noTema->getId() 
              << ", Tipo: " << noTema->getTipoString() << "\n";
    
    // Testar TAD Grafo (com nós separados para evitar conflito)
    std::cout << "\nTestando Grafo:\n";
    Grafo* grafoSocial = new Grafo(10, true, LISTA_ADJACENCIA);
    No* noGrafo1 = new No(0, USUARIO);
    No* noGrafo2 = new No(1, USUARIO);
    grafoSocial->adicionarNo(noGrafo1);
    grafoSocial->adicionarNo(noGrafo2);
    grafoSocial->adicionarAresta(0, 1);
    std::cout << "Grafo social criado com " << grafoSocial->getNumNos() << " nos\n";
    std::cout << "Aresta 0->1 existe: " << (grafoSocial->existeAresta(0, 1) ? "Sim" : "Nao") << "\n";
    
    // Testar mudanca de representacao
    grafoSocial->mudarRepresentacao(MATRIZ_ADJACENCIA);
    std::cout << "Grafo migrado para matriz de adjacencia\n";
    std::cout << "Aresta 0->1 ainda existe: " << (grafoSocial->existeAresta(0, 1) ? "Sim" : "Nao") << "\n";
    
    std::cout << "Dicionario criado com:\n";
    std::cout << "- " << dicionario->getNumUsuarios() << " usuario(s)\n";
    std::cout << "- " << dicionario->getNumTemas() << " tema(s)\n";
    
    Usuario* userRecuperado = dicionario->getUsuario(0);
    if (userRecuperado) {
        std::cout << "Usuario recuperado: " << userRecuperado->getNome() << "\n";
    }
    
    Tema* temaRecuperado = dicionario->getTema(0);
    if (temaRecuperado) {
        std::cout << "Tema recuperado: " << temaRecuperado->getNome() << "\n";
    }
    
    std::cout << "\nTodos os TADS testados com sucesso!\n";
    
    // Limpar memoria
    // Nota: Dicionario ja deleta os objetos que ele gerencia
    delete grafoSocial;
    delete dicionario;
    
    return 0;
}
