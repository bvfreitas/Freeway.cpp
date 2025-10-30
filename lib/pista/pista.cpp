// pista.cpp
#include <iostream>
#include <vector>
#include "pista.hpp"
#include <cstdlib>
#include "../constates.hpp"

namespace LibPista{
    Pista::Pista() = default;

    void Pista::inicializa(int larguraJogo){
        velocidade = (rand() % MAX_VELOCIDADE + 1) * (-1); 
        numCarros = rand() % MAX_CARROS_PISTA + 1;
        posicoesCarros.clear(); //Tira todos os dados do vetor
        for(int i = 0; i < numCarros; i++){
            posicoesCarros.push_back(rand() % larguraJogo + 1); //Adidiona um item aleatório ao vetor
        }
    }

    void Pista::imprime(){
        std::cout << "Velocidade da pista: " << velocidade << "\n";
        std::cout << "Numero de Carros: " << numCarros << "\n";
        std::cout << "Posições dos carros: ";
        for(int i = 0; i < numCarros; i++){
            std::cout << posicoesCarros[i] << " ";
        }
        std::cout << "\n\n";
    }
};
