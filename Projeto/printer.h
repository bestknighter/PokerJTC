#ifndef _PRINTER
#define _PRINTER
#include <stdlib.h>
#include <stdio.h>
#include "core.h"
#include "jogadores.h"
#include "baralho.h"

/*  Esta fun��o imprime todos os jogadores da lista.
*   Recebe Player **lj
*/
void imprimeJogadores(Player **lj);


/*  Esta fun��o imprime as estat�sticas do jogo.
*/
void imprimeJogo(Stats *stats);


/*  Esta fun��o recebe um ponteiro para Carta e o imprime na tela
*/
void imprimeCarta(Carta *c, int censurado);


/*  Esta fun��o recebe um ponteiro para uma lista de cartas (baralho)
*   e imprime, utilizando a fun��o imprimeCarta, todo o baralho na tela
*/
void imprimeBaralho(Carta **lc, int censurado);

void imprimeJogador(Player *player, int censurado);

void imprimeMesa(Stats *stats, int view);

#endif
