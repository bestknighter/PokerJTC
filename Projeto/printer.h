#ifndef _PRINTER
#define _PRINTER
#include <stdlib.h>
#include <stdio.h>
#include "core.h"
#include "jogadores.h"
#include "baralho.h"

/*  Esta função imprime todos os jogadores da lista.
*   Recebe Player **lj
*/
void imprimeJogadores(Player **lj);


/*  Esta função imprime as estatísticas do jogo.
*/
void imprimeJogo(Stats *stats);


/*  Esta função recebe um ponteiro para Carta e o imprime na tela
*/
void imprimeCarta(Carta *c, int censurado);


/*  Esta função recebe um ponteiro para uma lista de cartas (baralho)
*   e imprime, utilizando a função imprimeCarta, todo o baralho na tela
*/
void imprimeBaralho(Carta **lc, int censurado);

void imprimeJogador(Player *player, int censurado);

void imprimeMesa(Stats *stats, int view);

int menuHumanos(Stats *stats, Player *plaux);

void endScreen(Stats *stats);

int menuPrincipal();

int menuNovoJogo(Stats *stats);

void menuNovoJogador(Stats *stats);

void novaRodada(Stats *stats);

#endif
