#ifndef _JOGADOR_C
#define _JOGADOR_C
#include "jogador.h"

PlayerBasic* creatingJogador(){
      PlayerBasic *novoJogador;

      novoJogador = calloc(1, sizeof(PlayerBasic));
      novoJogador->mao = calloc (1, sizeof(void*));
      novoJogador->outrosDados = calloc (1, sizeof(void*));
      *(novoJogador->mao) = NULL;
      novoJogador->prox = novoJogador;
      novoJogador->ant = novoJogador;
      return novoJogador;
};

void insereJogador(PlayerBasic **lp, PlayerBasic *player){
      PlayerBasic *plaux;

      plaux = *lp;

      if(plaux != NULL){
            while (plaux->prox != NULL) plaux = plaux->prox;
            player->prox = plaux->prox;
            player->ant = plaux;
            plaux->prox = player;
      }else *lp = player;
};

void removerJogador(PlayerBasic **lp, PlayerBasic *player){
      PlayerBasic *plaux;

      plaux = *lp;

      while(plaux != player && plaux->prox != NULL) plaux = plaux->prox;
      if (plaux == player){
            if(plaux->ant != NULL) plaux->ant->prox = plaux->prox;
            if(plaux->prox != NULL) plaux->prox->ant = plaux->ant;
            free(player);
            plaux = NULL;
      };
};

void removerJogadores(PlayerBasic **lp){
      PlayerBasic *plaux;

      plaux = *lp;

      while(plaux->prox != NULL) plaux = plaux->prox;
      while(plaux!=NULL){
            plaux = plaux->ant;
            free(plaux->prox);
      };
};

#endif
