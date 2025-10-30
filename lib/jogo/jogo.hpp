//jogo.hpp
#pragma once
#include <vector>
#include "../pista/pista.hpp"
#include "../galinha/galinha.hpp"

namespace LibJogo{
    class Jogo{
        public:
            int largura;
            std::vector<LibPista::Pista> pistas;
            LibGalinha::Galinha galinha;
            int pontos;

            void inicializa();
            void imprimeDados();
            void desenhaMapa();
            void atualizaPosicaoCarros();
            void moveGalinha();
            bool confereColisao();
            bool acabou();
            void roda();
    };
}