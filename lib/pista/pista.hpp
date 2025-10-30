// pista.hpp
#pragma once

namespace LibPista{
class Pista{
    public:
        int velocidade;
        int numCarros;
        std::vector<int> posicoesCarros; //Alocação dinâmica para o vetor

        Pista(); //Cria a pista vazia

    void inicializa(int larguraJogo);
    void imprime();
};
}