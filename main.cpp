#include <iostream>
#include <vector>
#include "lib/constates.hpp"
#include "lib/galinha/galinha.hpp"
#include "lib/pista/pista.hpp"


int main(){
    srand(time(nullptr));

    LibPista::Pista pista;
    LibGalinha::Galinha galinha;
    pista.inicializa(LARGURA_JOGO);
    pista.imprime();

    galinha.inicializa(LARGURA_JOGO);
    galinha.imprime();

    return 0;
}