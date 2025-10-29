#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#define MAX_VELOCIDADE 3
#define MAX_CARROS_PISTA 4
#define LARGURA_JOGO 20

class Pista{
    public:
        int velocidade = 0;
        int numCarros = 0;
        std::vector<int> posicoesCarros;

    Pista() = default; //Cria a pista vazia

    void inicializa(int larguraJogo){
        velocidade = (rand() % MAX_VELOCIDADE + 1) * (rand() % 2 == 0? 1 : -1);
        numCarros = rand() % MAX_CARROS_PISTA + 1;
        posicoesCarros.clear(); //Tira todos os dados do vetor
        for(int i = 0; i < numCarros; i++){
            posicoesCarros.push_back(rand() % larguraJogo + 1);
        }
    }

    void imprime(){
        std::cout << "Velocidade da pista: " << velocidade << "\n";
        std::cout << "Numero de Carros: " << numCarros << "\n";
        std::cout << "Posições dos carros: ";
        for(int i = 0; i < numCarros; i++){
            std::cout << posicoesCarros[i] << " ";
        }
        std::cout << "\n";
    }
};

int main(){
    srand(time(nullptr));

    Pista pista;
    pista.inicializa(LARGURA_JOGO);
    pista.imprime();

    return 0;
}