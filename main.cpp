#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#define MAX_VELOCIDADE 3
#define MAX_CARROS_PISTA 4
#define LARGURA_JOGO 20 //Também deve ser aleatório, mas vai ficar na classe do Jogo
#define MAX_VIDAS 3

class Pista{
    public:
        int velocidade = 0;
        int numCarros = 0;
        std::vector<int> posicoesCarros; //Alocação dinâmica para o vetor

        Pista() = default; //Cria a pista vazia

    void inicializa(int larguraJogo){
        velocidade = (rand() % MAX_VELOCIDADE + 1) * (rand() % 2 == 0? 1 : -1); 
        numCarros = rand() % MAX_CARROS_PISTA + 1;
        posicoesCarros.clear(); //Tira todos os dados do vetor
        for(int i = 0; i < numCarros; i++){
            posicoesCarros.push_back(rand() % larguraJogo + 1); //Adidiona um item aleatório ao vetor
        }
    }

    void imprime(){
        std::cout << "Velocidade da pista: " << velocidade << "\n";
        std::cout << "Numero de Carros: " << numCarros << "\n";
        std::cout << "Posições dos carros: ";
        for(int i = 0; i < numCarros; i++){
            std::cout << posicoesCarros[i] << " ";
        }
        std::cout << "\n\n";
    }
};

class Galinha{
    public:
        int x;
        int y;
        int vidas;

        Galinha() = default;
        
    void inicializa(int larguraJogo){
        y = 0; //Vai começar sempre no começo da avenida
        x = (rand() % larguraJogo + 1); //Posicao inicial aleatória
        vidas = MAX_VIDAS;
    }

    void imprime(){
        std::cout << "Posicao da galinha: (" << x << ',' << y << ")\n";
        std::cout << "Vidas restantes: " << vidas << "\n";
    }
};

int main(){
    srand(time(nullptr));

    Pista pista;
    Galinha galinha;
    pista.inicializa(LARGURA_JOGO);
    pista.imprime();

    galinha.inicializa(LARGURA_JOGO);
    galinha.imprime();

    return 0;
}