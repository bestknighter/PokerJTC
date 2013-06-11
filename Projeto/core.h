#ifndef _CORE
#define _CORE
#include "userInput.h"
#include "jogadores.h"
#include "baralho.h"

enum mode {
    PADRAO = 0,
    PERSONALIZADO
};

typedef struct estatJogo{
    int nJogadoresTotal;
    int nJogadoresAtivo;
    int smallBlind;
    int bigBlind;
    int apostaAtual;
    int valorDaMesa;
    int rodadaAtual;
    struct jogador **jogadores;
    struct carta **maoMesa;
}Stats;

Stats* initGame();

void resetGame(Stats *stats);

void restartJogador(Player *player);

void resetJogador(Player *player);

void restartJogadores(Player **lp);

void resetJogadores(Player **lp);

Player* criarJogador(int mode);

void insereJogadorLista(Stats *stats, Player *jogador);

void addJogador(Stats *stats, int mode);

#endif
