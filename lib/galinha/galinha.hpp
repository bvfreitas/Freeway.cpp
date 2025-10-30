// galinha.hpp
#pragma once

namespace LibGalinha{
    class Galinha{
        public:
        int x;
        int y;
        int vidas;

        Galinha();

        void inicializa(int larguraJogo);
        void imprime();
    };
}