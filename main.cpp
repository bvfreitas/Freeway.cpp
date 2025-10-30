#include <iostream>
#include <vector>
#include "lib/constates.hpp"
#include "lib/galinha/galinha.hpp"
#include "lib/pista/pista.hpp"
#include "lib/jogo/jogo.hpp"
#include <thread>
#include <chrono>

int main(){
    srand(time(nullptr));

    LibJogo::Jogo jogo;
    jogo.inicializa();
   
    while(true){
        jogo.atualizaPosicaoCarros();
        jogo.desenhaMapa();

        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //Espera 1s
    }

    return 0;
}