#include <stdio.h>
// Os valor 3 representado por #define NAVIO 3 irá aparecer nas coordenadas que as variaveis foram declaradas, mas precisamos criar estruturas de comparação para entender se está correto a posição e se ela comporta dentro do espaço do tabuleiro, por isso utilizei o IF. 
// Para que o tabuleiro exiba os valores dos navios e seu espaço ocupado, utilizei o laço de repetição for que permite  aninhar de forma mais pratica e limpa, posicionando-as agora também na diagonal.


// Definições para facilitar manutenção
#define TAMANHO_TABULEIRO 10  // Dimensão do tabuleiro (10x10)
#define TAMANHO_NAVIO 3        // Tamanho fixo dos navios
#define AGUA 0                 // Representação para água (espaços vazios)
#define NAVIO 3                // Representação para navio

int main() {
    // Inicializando o tabuleiro 10x10 com água (tudo começa com 0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {AGUA};

    // Definição das coordenadas iniciais para os navios
    int navio1Linha = 1, navio1Coluna = 3; // Navio horizontal
    int navio2Linha = 5, navio2Coluna = 5; // Navio vertical
    int navio3Linha = 0, navio3Coluna = 0; // Navio diagonal descendente
    int navio4Linha = 6, navio4Coluna = 3; // Navio diagonal ascendente

    // Posicionando o navio 1 (horizontal)
    if (navio1Coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio1Linha][navio1Coluna + i] = NAVIO;
        }
    }

    // Posicionando o navio 2 (vertical)
    if (navio2Linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio2Linha + i][navio2Coluna] = NAVIO;
        }
    }

    // Posicionando o navio 3 (diagonal descendente = esquerda p/ direita)
    if (navio3Linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && navio3Coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio3Linha + i][navio3Coluna + i] = NAVIO;
        }
    }

    // Posicionando o navio 4 (diagonal = direita p/ esquerda)
    if (navio4Linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && navio4Coluna - TAMANHO_NAVIO >= -1) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio4Linha + i][navio4Coluna - i] = NAVIO;
        }
    }

    // Exibindo o tabuleiro com os navios posicionados
    printf("Tabuleiro com os navios posicionados:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); // Mostra 0 para água e 3 para navios
        }
        printf("\n"); // Quebra de linha para visualizar o tabuleiro corretamente
    }

    return 0;
}
