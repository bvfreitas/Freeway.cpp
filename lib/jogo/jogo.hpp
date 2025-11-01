// jogo/jogo.hpp
#pragma once
#include <vector>
#include <string>
#include "../galinha/galinha.hpp"
#include "../pista/pista.hpp"

namespace LibJogo {

class Jogo {
public:
    Jogo() = default;

    void inicializa();
    void desenha_mapa();
    void atualiza_carros();

    int get_pontos() const {return pontos;}
    int get_largura() const {return largura;}
    int get_num_pistas() const {return num_pistas;}

    void set_pontos(int pontos) const {pontos = pontos;}
    void set_largura(int largura) const {largura = largura;}
    void set_num_pistas(int num_pistas) const {num_pistas = num_pistas;}

private:
    int largura = 0;
    int num_pistas = 0;
    int pontos = 0;

    std::vector<LibPista::Pista> pistas;
    LibGalinha::Galinha galinha;
};

} // namespace LibJogo