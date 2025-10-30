#include <iostream>
#include <vector>
#include "lib/constates.hpp"
#include "lib/galinha/galinha.hpp"
#include "lib/pista/pista.hpp"
#include "lib/jogo/jogo.hpp"


int main(){
    srand(time(nullptr));

    LibJogo::Jogo jogo;
    jogo.inicializa();
    jogo.desenhaMapa();

    return 0;
}