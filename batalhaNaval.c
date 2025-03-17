#include <stdio.h>

#define TAMANHO 10
#define TAM_NAVIO 3

int main() {
    // Inicializando o tabuleiro com água (0)
    int tabuleiro[TAMANHO][TAMANHO] = {0};
    
    // Definição das coordenadas iniciais dos navios
    int linha_horizontal = 2, coluna_horizontal = 3; // Navio horizontal
    int linha_vertical = 5, coluna_vertical = 6; // Navio vertical
    int linha_diagonal1 = 1, coluna_diagonal1 = 1; // Navio diagonal principal (↘)
    int linha_diagonal2 = 7, coluna_diagonal2 = 7; // Navio diagonal secundária (↙)
    
    // Posicionando o navio horizontalmente
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;
    }
    
    // Posicionando o navio verticalmente
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = 3;
    }
    
    // Posicionando o navio diagonalmente (↘)
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_diagonal1 + i][coluna_diagonal1 + i] = 3;
    }
    
    // Posicionando o navio diagonalmente (↙)
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_diagonal2 - i][coluna_diagonal2 - i] = 3;
    }
    
    // Exibição do tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
