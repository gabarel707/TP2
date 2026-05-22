#include <Grafo.h>
#include <Usuario.h>
#include <Tema.h>
#include "Dicionario.h"
#include "Grafo.h"
#include "Usuario.h"
#include "Tema.h"

int main() {
    
    Dicionario dict;
    Grafo grafo_temas = Grafo();
    grafo_temas.setTipo('T');
    Grafo grafo_social = Grafo();
    grafo_temas.setTipo('U'); 
    
    std::string comando;
    
    std::cin >> comando;
    while(comando != "A"){
        std::cout << "Primeiro comando deve ser A" << std::endl;
        std::cin >> comando;
    }
    
    if(comando == "A"){
        std::string arg;
        std::cin >> arg;
        if(arg == "M"){
            grafo_temas.setModo('M');
            grafo_social.setModo('M');
        }
        else if(arg == "L"){
            grafo_social.setModo('L');
            grafo_temas.setModo('L');
        }
    }
    
    while(std::cin >> comando){
        if(comando == "A"){
            std::string arg;
            std::cin >> arg;
            if(arg == "M"){
                grafo_temas.setModo('M');
                grafo_social.setModo('M');
            }
            else if(arg == "M"){
                grafo_social.setModo('L');
                grafo_temas.setModo('L');
            }
        }
        else if(comando == "T"){
            std::string nome;
            char tipo;
            std::cin >> nome >> tipo;

            int id = grafo_temas.adiciona_no('T');
            dict.adicionarTema(id, nome, tipo);
        }
        else if(comando == "U"){
            std::string nome;
            int idade;
            std::cin >> nome >> idade;

            int id = grafo_social.adiciona_no('U');
            grafo_temas.adiciona_no('U');
            dict.adicionarUsuario(id, nome, idade);
        }
        else if(comando == "S"){
            
        }
        else if(comando == "R"){

        }
        else if(comando == "LT"){
            // Adiciona user
        }
        else if(comando == "LC"){
            // Adiciona Tema
        }
        else if(comando == "LS"){

        }
        else if(comando == "LA"){
            
        }
        else if(comando == "Q"){
            // Consulta de relaçaõ
        }
        else if(comando == "G"){
            // Consulta de interesse
        }
        else if(comando == "F"){
            // COnsulta de popularidade
        }
    }
}