#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#define TAM_HAB 5

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5
// Desafio Batalha Naval - MateCheck

int main() {
    // Nível Mestre - Habilidades Especiais com Matrizes

    int tabuleiro[TAM][TAM];
 
    // Inicializa tabuleiro com água
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
    // Coloca alguns navios fixos

    tabuleiro[2][2] = NAVIO;
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;

    tabuleiro[6][6] = NAVIO;
    tabuleiro[7][6] = NAVIO;
    tabuleiro[8][6] = NAVIO;

    // MATRIZES DE HABILIDADE (0 e 1)
    
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    int centro = TAM_HAB / 2;

    // CONSTRÓI HABILIDADE CONE (↓)

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i >= centro && j >= centro - (i - centro) && j <= centro + (i - centro)) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }


    // CONSTRÓI HABILIDADE CRUZ

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }


    // CONSTRÓI HABILIDADE OCTAEDRO
    // (losango)

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }


    // APLICA HABILIDADES NO TABULEIRO


    int origemConeL = 1, origemConeC = 5;
    int origemCruzL = 5, origemCruzC = 2;
    int origemOctL  = 6, origemOctC  = 7;

    // Função manual de sobreposição (cone)
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            int l = origemConeL + i - centro;
            int c = origemConeC + j - centro;

            if (l >= 0 && l < TAM && c >= 0 && c < TAM && cone[i][j] == 1) {
                if (tabuleiro[l][c] == AGUA) {
                    tabuleiro[l][c] = HABILIDADE;
                }
            }
        }
    }

    // Cruz
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            int l = origemCruzL + i - centro;
            int c = origemCruzC + j - centro;

            if (l >= 0 && l < TAM && c >= 0 && c < TAM && cruz[i][j] == 1) {
                if (tabuleiro[l][c] == AGUA) {
                    tabuleiro[l][c] = HABILIDADE;
                }
            }
        }
    }

    // Octaedro
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            int l = origemOctL + i - centro;
            int c = origemOctC + j - centro;

            if (l >= 0 && l < TAM && c >= 0 && c < TAM && octaedro[i][j] == 1) {
                if (tabuleiro[l][c] == AGUA) {
                    tabuleiro[l][c] = HABILIDADE;
                }
            }
        }
    }


    // EXIBE TABULEIRO FINAL

    printf("\n    ");
    for (char c = 'A'; c <= 'J'; c++) {
        printf("%c ", c);
    }
    printf("\n");

    printf("   --------------------\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d | ", i + 1);
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

