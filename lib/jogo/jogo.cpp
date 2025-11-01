// jogo/jogo.cpp
#include "jogo.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

namespace LibJogo {

void Jogo::inicializa() {
    std::srand(std::time(nullptr));

    largura = rand() % 11 + 10;        // 10 a 20
    num_pistas = rand() % 6 + 5;       // 5 a 10
    pontos = 0;

    pistas.clear();
    pistas.resize(num_pistas);

    for (int i = 0; i < num_pistas; ++i) {
        if (i == 0 || i == num_pistas - 1) {
            pistas[i].set_velocidade(0);
            pistas[i].get_posicoes_carros().clear();
        } else {
            pistas[i].set_velocidade((rand() % 2 == 0) ? 1 : -1);
            int num_carros = rand() % 3 + 1;
            pistas[i].get_posicoes_carros().clear();
            for (int c = 0; c < num_carros; ++c) {
                int pos = rand() % largura + 1;
                pistas[i].get_posicoes_carros().push_back(pos);
            }
        }
    }

    galinha.set_x(largura / 2 + 1);
    galinha.set_y(num_pistas - 1);
}

void Jogo::desenha_mapa() {
    std::vector<std::vector<char>> mapa(num_pistas, std::vector<char>(largura, ' '));

    // Colocar carros
    for (int i = 0; i < num_pistas; ++i) {
        for (int pos : pistas[i].get_posicoes_carros()) {
            if (pos >= 1 && pos <= largura) {
                mapa[i][pos - 1] = 'C';
            }
        }
    }

    // Colocar galinha
    if (galinha.get_y() >= 0 && galinha.get_y() < num_pistas && galinha.get_x() >= 1 && galinha.get_x() <= largura) {
        mapa[galinha.get_y()][galinha.get_x() - 1] = 'G';
    }

    std::cout << "Pontos: " << pontos << "\n";
    std::cout << std::string(largura + 2, '-') << "\n";
    for (int i = 0; i < num_pistas; ++i) {
        std::cout << "|";
        for (int j = 0; j < largura; ++j) {
            char c = mapa[i][j];
            if (c == 'C') std::cout << "C";
            else if (c == 'G') std::cout << "G";
            else std::cout << " ";
        }
        std::cout << "|\n";
    }
    std::cout << std::string(largura + 2, '-') << "\n";
}

void Jogo::atualiza_carros() {
    for (auto& pista : pistas) {
        for (int& pos : pista.get_posicoes_carros()) {
            pos += pista.get_velocidade();
            if (pos > largura) pos = 1;
            if (pos < 1) pos = largura;
        }
    }
}

} // namespace LibJogo