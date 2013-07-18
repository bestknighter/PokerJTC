#ifndef _FRAMEWORK_C
#define _FRAMEWORK_C
#include "FrameWork_JogoDeBaralho.h"

PlayerBasic* createJogador(int mode){
    PlayerBasic *novoJogador;

    novoJogador = calloc(sizeof(PlayerBasic), 1);
    novoJogador->mao = calloc (1, sizeof(Carta*));
    novoJogador->prox = novoJogador;
    novoJogador->ant = novoJogador;
    return novoJogador;
};

void resetJogador(PlayerBasic *player){
      destroiBaralho(player->mao);
      player->mao = calloc(1, sizeof(Carta*));
};

void resetJogadores(PlayerBasic **lp){
      PlayerBasic *plaux;

      plaux = *lp;

      while(plaux->prox != NULL) plaux = plaux->prox;
      while(plaux!=NULL){
            plaux = plaux->ant;
            resetJogador(plaux->prox);
      };
};

void darCarta(PlayerBasic *player, Carta *c){
      addCarta(player->mao, c);
};

Carta* tiraCarta(PlayerBasic *player){
      return topCarta(player->mao);
};

#endif
