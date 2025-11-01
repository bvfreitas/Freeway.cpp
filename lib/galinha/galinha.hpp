// galinha.hpp
#pragma once

namespace LibGalinha{
class Galinha{
public:

    Galinha() = default;

    void inicializa(int larguraJogo, int numPistas);
    void imprime();

    int get_x() {return x;}
    int get_y() {return y;}
    int get_vidas() {return vidas;}

    void set_x(int x_) {x = x_;}
    void set_y(int y_) {y = y_;}
    void set_vidas(int vidas_) {vidas = vidas_;}

private:
    int x;
    int y;
    int vidas;
};
}