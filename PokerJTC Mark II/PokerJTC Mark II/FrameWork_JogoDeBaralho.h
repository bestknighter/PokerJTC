#ifndef _FRAMEWORK_H
#define _FRAMEWORK_H
#include "jogador.h"
#include "baralho.h"

void resetJogador(PlayerBasic *player);

void resetJogadores(PlayerBasic **lp);

void darCarta(PlayerBasic *player, Carta *c);

Carta* tiraCarta(PlayerBasic *player);

#endif
