// galinha.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "galinha.hpp"
#include "../constates.hpp"

namespace LibGalinha{
    Galinha::Galinha() = default;

    void Galinha::inicializa(int larguraJogo, int numPistas){
        y = numPistas - 1; //Vai começar sempre no começo da avenida
        x = (rand() % larguraJogo); //Posicao inicial aleatória
        vidas = MAX_VIDAS;
    }

    void Galinha::imprime(){
        std::cout << "Posicao da galinha: (" << x << ',' << y << ")\n";
        std::cout << "Vidas restantes: " << vidas << "\n";
    }
};
