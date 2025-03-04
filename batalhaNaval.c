#include <stdio.h>

int main() {
    // Definindo o tamanho do tabuleiro e o tamanho dos navios
    int TamanhoTabuleiro = 10;
    int TamanhoNavio = 3;

    // Inicializando o tabuleiro 10x10 com água (0)
    int tabuleiro[10][10] = {0};

    // Definindo as coordenadas e as orientações dos navios
    // Navio 1: Horizontal (posição inicial 2,3)
    int navio1Linha = 1;
    int navio1Coluna = 3;
    // Navio 2: Vertical (posição inicial 5,5)
    int navio2Linha = 5;
    int navio2Coluna = 5;

    // Colocando o navio 1 (horizontal)
    for (int i = 0; i < TamanhoNavio; i++) {
        tabuleiro[navio1Linha][navio1Coluna + i] = 3; // Marca as posições do navio 1
    }

    // Colocando o navio 2 (vertical)
    for (int i = 0; i < TamanhoNavio; i++) {
        tabuleiro[navio2Linha + i][navio2Coluna] = 3; // Marca as posições do navio 2
    }

    // Exibindo o tabuleiro com os navios posicionados
    printf("Tabuleiro com os navios posicionados:\n");
    for (int i = 0; i < TamanhoTabuleiro; i++) {
        for (int j = 0; j < TamanhoTabuleiro; j++) {
            printf("%d ", tabuleiro[i][j]); // Exibe 0 para água ou 3 para partes dos navios
        }
        printf("\n"); 
    }

    return 0;
}
