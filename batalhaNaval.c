#include <stdio.h>

/*
PROGRAMA FINAL DESAFIO NÍVEL MESTRE
*/

#define TAMANHO_TABULEIRO 10  // Define o tamanho do tabuleiro como 10x10
#define TAMANHO_NAVIO 3       // Define o tamanho dos navios como 3 espaços
#define AGUA 0                // Representa água no tabuleiro
#define NAVIO 3               // Representa um navio no tabuleiro
#define HABILIDADE 4          // Representa uma habilidade aplicada no tabuleiro

// Função para aplicar uma habilidade ao tabuleiro
void aplicar_habilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[5][5], int origem_linha, int origem_coluna) {
    int tamanho_habilidade = 5;  // As habilidades têm sempre um tamanho 5x5
    int deslocamento = tamanho_habilidade / 2;  // Calcula o deslocamento para centralizar a habilidade
    
    // Percorre a matriz da habilidade
    for (int i = 0; i < tamanho_habilidade; i++) {
        for (int j = 0; j < tamanho_habilidade; j++) {
            if (habilidade[i][j] == 1) {  // Verifica se a célula da habilidade deve ser aplicada
                int linha = origem_linha + i - deslocamento;
                int coluna = origem_coluna + j - deslocamento;
                
                // Garante que a habilidade seja aplicada dentro dos limites do tabuleiro
                if (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO) {
                    if (tabuleiro[linha][coluna] == AGUA) {
                        tabuleiro[linha][coluna] = HABILIDADE;  // Aplica a habilidade somente onde há água
                    }
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {AGUA}; // Inicializa o tabuleiro todo com água

    // Definição das posições iniciais dos navios
    int navio1Linha = 1, navio1Coluna = 7;
    int navio2Linha = 3, navio2Coluna = 0;
    int navio3Linha = 7, navio3Coluna = 5;
    int navio4Linha = 3, navio4Coluna = 6;

    // Posiciona o primeiro navio (horizontalmente para a direita)
    if (navio1Coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio1Linha][navio1Coluna + i] = NAVIO;
        }
    }

    // Posiciona o segundo navio (verticalmente para baixo)
    if (navio2Linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio2Linha + i][navio2Coluna] = NAVIO;
        }
    }

    // Posiciona o terceiro navio (diagonalmente da esquerda para a direita para baixo)
    if (navio3Linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && navio3Coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio3Linha + i][navio3Coluna + i] = NAVIO;
        }
    }
    
    // Posiciona o quarto navio (diagonalmente da direita para a esquerda para baixo)
    if (navio4Linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && navio4Coluna - (TAMANHO_NAVIO - 1) >= 0) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio4Linha + i][navio4Coluna - i] = NAVIO;
        }
    }

    // Definição das habilidades
    // Poderia criar uma função utilizando void para gerar as habilidades mas eu preferi fazer conforme aprendi nas aulas
    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    int octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Aplica as habilidades em pontos específicos do tabuleiro
    aplicar_habilidade(tabuleiro, cone, 2, 3);
    aplicar_habilidade(tabuleiro, cruz, 5, 7);
    aplicar_habilidade(tabuleiro, octaedro, 7, 2);

    // Exibe o tabuleiro final com os navios e habilidades aplicadas
    printf("Tabuleiro com habilidades aplicadas:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}