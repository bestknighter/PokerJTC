#ifndef _GUI_H
#define _GUI_H
#include "input.h"
#include "output.h"

char* getNome();

int getDinheiro();

int getAI();

int getRaise();

int getBBlind();

int getSBlind();

void imprimeJogadores(PlayerBasic **lj);

void imprimeJogo(Stats *stats);

void imprimeCarta(Carta *c, int censurado);

void imprimeBaralho(Carta **lc, int censurado);

void imprimeJogador(PlayerBasic *player, int censurado);

void imprimeMesa(Stats *stats, int view);

int menuHumanos(Stats *stats, Player *plaux);

void endScreen(Stats *stats);

int menuPrincipal();

int menuNovoJogo(Stats *stats);

void menuNovoJogador(Stats *stats);

void novaRodada(Stats *stats);

#endif
