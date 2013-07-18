#ifndef _GUI_H
#define _GUI_H
#include "input.h"
#include "output.h"
#include "GameManagement.h"
#include "FrameWork_JogoDeBaralho.h"

char* getNome();

float getDinheiro();

int getAI();

float getRaise();

float getBBlind();

float getSBlind();

void imprimeJogadores(PlayerBasic **lj);

void imprimeJogo(Stats *stats);

void imprimeCarta(Carta *c, int censurado);

void imprimeBaralho(Carta **lc, int censurado);

void imprimeJogador(PlayerBasic *player, int censurado);

void imprimeMesa(Stats *stats, int view);

int menuHumanos(Stats *stats, PlayerBasic *plaux);

void endScreen(Stats *stats);

int menuPrincipal();

int menuNovoJogo(Stats *stats);

void menuNovoJogador(Stats *stats);

int novaPartida();

void novaRodada(Stats *stats);

#endif
