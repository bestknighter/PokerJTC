#ifndef _GAMELOGIC_H
#define _GAMELOGIC_H
#include "FrameWork_JogoDeBaralho.h"
#include "GameManagement.h"

void mainloop();

void rodadaLoop(Stats *stats);

void seletorRodada(Stats *stats);

void prepR0(Stats *stats);

void prepR1(Stats *stats);

void prepR2(Stats *stats);

void showdown(Stats *stats);

void mostrarTelaFinal(Stats *stats);

#endif
