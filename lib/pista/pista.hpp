// pista.hpp
#pragma once
#include <vector>

namespace LibPista{
class Pista{
public:
    Pista() = default;

    void inicializa(int larguraJogo);
    void imprime();

    int get_velocidade() const { return velocidade;}
    int get_num_carros() const { return numCarros;}
    std::vector<int>& get_posicoes_carros() {return posicoesCarros;}
    const std::vector<int>& get_posicoes_carros() const {return posicoesCarros;}

    void set_velocidade(int vel) {velocidade = vel;}
    void set_num_carros(int num) {numCarros = num;}

    void atualiza_posicoes_carros(const std::vector<int>& posicoes) {
        // realoca memoria se preciso
        if (posicoesCarros.max_size() >= posicoes.size()){
            posicoesCarros = posicoes;
        } else {
            posicoesCarros.resize(posicoes.size()+10);
            posicoesCarros = posicoes;
        }
    }

private:
    int velocidade = 0;
    int numCarros = 0;

    std::vector<int> posicoesCarros; //Alocação dinâmica para o vetor
};
}