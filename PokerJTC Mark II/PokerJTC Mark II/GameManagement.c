#ifndef _POKERGAME_C
#define _POKERGAME_C
#include "GameManagement.h"

void initJogador(PlayerBasic *player){
      Dados *dados;

      dados = calloc(1, sizeof(dados));

      dados->nome = calloc(20, sizeof(char));
      dados->aposta = 0;
      dados->nJogador = 0;
      dados->estado = NOTPLAYED;
      dados->badge = OTHER;

      player->outrosDados = (Dados*) dados;
};

void setJogador(PlayerBasic *player, int mode){
      Dados *dados;

      dados = player->outrosDados;

      initJogador(player);
      system("CLS");
      strncpy(dados->nome, getNome(), 20);
      system("CLS");
      dados->AI = getAI();
      system("CLS");
      dados->dinheiro = (mode==PADRAO)?(500):(getDinheiro(), system("CLS"));
};

void fold(PlayerBasic *player){
      Dados *dados;

      dados = player->outrosDados;

      if(dados != NULL) dados->estado = FOLDED;
      else{
                  //TODO: Jogador n�o inicializado...
      };
};

void call(PlayerBasic *player, int valor_da_aposta){
      Dados *dados;

      dados = player->outrosDados;

      if(dados != NULL){
            if(dados->dinheiro >= dados->dinheiro + dados->aposta - valor_da_aposta){
                  dados->estado = CALLED;
                  dados->dinheiro += dados->aposta;
                  dados->dinheiro -= dados->aposta = valor_da_aposta;
            }else{
                  //TODO: Erro! Dinheiro n�o suficiente...
            };
      }else{
            //TODO: Jogador n�o inicializado...
      };
};

int raise(PlayerBasic *player, int valor_da_aposta){  //TODO: Raise invalido (menor que a Big Blind)
      int i;
      Dados *dados;

      dados = player->outrosDados;

      if(dados != NULL){
            i = getRaise();
            (i>=0)?(i=i):(i=-1*i);
            dados->aposta = valor_da_aposta+i;
            dados->dinheiro -= i;
            dados->estado = RAISED;
            return i;
      }else{
            //TODO: Jogador n�o inicializado...
      };
};

void check(PlayerBasic *player){
      Dados *dados;

      dados = player->outrosDados;

      if(dados != NULL) dados->estado = CHECKED;
      else{
            //TODO: Jogador n�o inicializado...
      };
};

Stats* initGame(){
      Stats *stats;

      stats = malloc(sizeof(Stats));

      stats->nJogadoresTotal = 0;
      stats->nJogadoresAtivo = 0;
      stats->smallBlind = 0;
      stats->bigBlind = 0;
      stats->apostaAtual = 0;
      stats->valorDaMesa = 0;
      stats->rodadaAtual = 0;
      stats->jogadores = calloc(1, sizeof(PlayerBasic*));
      stats->maoMesa = calloc(1, sizeof(Carta*));
      stats->baralhoJogo = calloc(1, sizeof(Carta*));
      stats->baralhoJogo = criaBaralho();
      embaralha(stats->baralhoJogo);
      return stats;
};

void resetGame(Stats *stats){
      PlayerBasic *player;
      Dados *dados;

      player = getVencedor(stats);
      dados = player->outrosDados;

      dados->dinheiro += stats->valorDaMesa;
      stats->nJogadoresAtivo = getNJogadores();
      stats->smallBlind = 0;
      stats->bigBlind = 0;
      stats->apostaAtual = 0;
      stats->valorDaMesa = 0;
      stats->rodadaAtual = 0;
      destroiBaralho(stats->baralhoJogo);
      stats->baralhoJogo = criaBaralho();

};

void badgeSetter(Stats *stats){
      PlayerBasic *plaux;
      Dados *dado;
      Carta *c;
      int max = 0, np = -1;

      plaux = *(stats->jogadores);
      do{
            c = topCarta(stats->baralhoJogo);
            addCarta(plaux->mao, c);
            if(c->valor>max){
                  max = c->valor;
                  dado = plaux->outrosDados;
                  np = dado->nJogador;
            };
            plaux = plaux->prox;
      }while(plaux->prox != (*(stats->jogadores))->prox);
      while(plaux->nJogador != np) plaux = plaux->prox;
      dado = plaux->outrosDados;
      dado->badge = DEALER;
      if(plaux->prox->prox != plaux){
            dado = plaux->prox->outrosDados;
            dado->badge = SBLIND;
            dado = plaux->prox->prox->outrosDados;
            dado->badge = BBLIND;
      } else{
            dado = plaux->prox->outrosDados;
            dado->badge = BBLIND;
      };
      restartGame(stats);
};

void calculoPote(Stats *stats){
      float pote = 0;
      PlayerBasic *plaux;
      Dados *dado;

      plaux = *(stats->jogadores);
      do{
            dado = plaux->outrosDados;
            pote += dado->aposta;
            plaux = plaux->prox;
      }while(plaux != *(stats->jogadores));
      stats->valorDaMesa = pote;
};

void setVencedor(PlayerBasic *player){                //Algoritmo pass�vel de altera��o
      Dados *dado;

      dado = player->outrosDados;
      dado->badge = WINNER;
};

PlayerBasic* getVencedor(Stats *stats){
      PlayerBasic *plaux;
      Dados *dado;
      int end = 0;

      plaux = *(stats->jogadores);
      do{
            dado = plaux->outrosDados;
            if (dado->badge == WINNER) end = 1;
            else{
                  plaux = plaux->prox;
                  if (plaux == *(stats->jogadores)) end = 2;
            };
      }while(end == 0);
      if(end == 1) return plaux;
      else return NULL;
};

#endif
