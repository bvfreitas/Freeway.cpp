//jogo.cpp
#include "jogo.hpp"
#include "../constates.hpp"
#include <cstdlib>
#include <iostream>

namespace LibJogo {

    void Jogo::inicializa(){
        largura = rand() % (MAX_LARGURA_JOGO - MIN_LARGURA_JOGO + 1) + MIN_LARGURA_JOGO;
        
        numPistas = rand() % (MAX_PISTAS - MIN_PISTAS + 1) + MIN_PISTAS;
        pistas.clear();

        for (int i = 0; i < numPistas; i++) {
            LibPista::Pista pistaAux;

            if (i == 0 || i == numPistas - 1){
                pistaAux.velocidade = 0;
                pistaAux.numCarros = 0;
                pistaAux.posicoesCarros.clear();
            } else {
                pistaAux.inicializa(largura);
            }

        pistas.push_back(pistaAux);
    }

        galinha.inicializa(largura, numPistas);
        pontos = 0;
    }

    void Jogo::desenhaMapa(){
        char mapa[numPistas][largura];
        std::cout << "Pontos: " << pontos << "\n";

        for(int i = 0; i < numPistas; i++){
            for(int j = 0; j < largura; j++){
                mapa[i][j] = ' ';
            }
        }

        for(int i = 0; i < numPistas; i++){
            for(int pos:pistas[i].posicoesCarros){
                if(pos >= 1 && pos <= largura){
                    mapa[i][pos - 1] = 'C';
                }
            }
        }

        if (galinha.y >= 0 && galinha.y < numPistas &&
            galinha.x >= 1 && galinha.x <= largura) {
            mapa[galinha.y][galinha.x] = 'G';
        }

        std::cout << "|";
        for (int j = 0; j < largura; ++j)
            std::cout << "--";

        std::cout << "|\n";

        for (int i = 0; i < numPistas; ++i) {
            std::cout << "|";
            for (int j = 0; j < largura; ++j) {
                if (mapa[i][j] == 'C')
                    std::cout << "🚗";
                else if (mapa[i][j] == 'G')
                    std::cout << "🐔";
                else
                    std::cout << "  ";
            }
            std::cout << "|\n";
        }

        std::cout << "|";
        for (int j = 0; j < largura; ++j)
            std::cout << "--";
        
        std::cout << "|\n";

    }

    void Jogo::atualizaPosicaoCarros() {
        for (int i = 0; i < numPistas; ++i) {
            int velocidade = pistas[i].velocidade;

            for (int& pos : pistas[i].posicoesCarros) {
                pos += velocidade;

                // Loop circular: se passar da largura, volta pro início
                if (pos > largura)
                    pos -= largura;
                else if (pos < 1)
                    pos += largura;
        }
    }
}

}