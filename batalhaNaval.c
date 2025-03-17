#include <stdio.h>

#define TAMANHO 10
#define TAM_NAVIO 3
#define HABILIDADE 5

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
    
    // Definição das coordenadas iniciais das habilidades
    int origem_cone_x = 3, origem_cone_y = 5;
    int origem_cruz_x = 6, origem_cruz_y = 4;
    int origem_octaedro_x = 5, origem_octaedro_y = 7;
    
    // Aplicação da habilidade Cone (forma triangular para baixo)
    for (int i = 0; i < 3; i++) {
        for (int j = -i; j <= i; j++) {
            if (origem_cone_x + i < TAMANHO && origem_cone_y + j >= 0 && origem_cone_y + j < TAMANHO) {
                tabuleiro[origem_cone_x + i][origem_cone_y + j] = HABILIDADE;
            }
        }
    }
    
    // Aplicação da habilidade Cruz
    for (int i = -2; i <= 2; i++) {
        if (origem_cruz_x + i >= 0 && origem_cruz_x + i < TAMANHO) {
            tabuleiro[origem_cruz_x + i][origem_cruz_y] = HABILIDADE;
        }
        if (origem_cruz_y + i >= 0 && origem_cruz_y + i < TAMANHO) {
            tabuleiro[origem_cruz_x][origem_cruz_y + i] = HABILIDADE;
        }
    }
    
    // Aplicação da habilidade Octaedro
    for (int i = -2; i <= 2; i++) {
        for (int j = -2 + abs(i); j <= 2 - abs(i); j++) {
            if (origem_octaedro_x + i >= 0 && origem_octaedro_x + i < TAMANHO &&
                origem_octaedro_y + j >= 0 && origem_octaedro_y + j < TAMANHO) {
                tabuleiro[origem_octaedro_x + i][origem_octaedro_y + j] = HABILIDADE;
            }
        }
    }
    
    // Exibição do tabuleiro
    printf("Tabuleiro de Batalha Naval com Habilidades:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
