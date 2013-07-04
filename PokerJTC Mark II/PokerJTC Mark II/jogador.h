#ifndef _JOGADOR_H
#define _JOGADOR_H
#include <stdlib.h>

typedef struct jogador{
    void *outrosDados;
    struct carta **mao;
    struct jogador *prox;
    struct jogador *ant;
}PlayerBasic;

PlayerBasic* criarJogador();

void insereJogador(PlayerBasic **lp, PlayerBasic *player);

void removerJogador(PlayerBasic **lp, PlayerBasic *player);

void removerJogadores(PlayerBasic **lp);

#endif
