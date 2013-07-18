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
                  //TODO: Jogador não inicializado...
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
                  //TODO: Erro! Dinheiro não suficiente...
            };
      }else{
            //TODO: Jogador não inicializado...
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
            //TODO: Jogador não inicializado...
      };
};

void check(PlayerBasic *player){
      Dados *dados;

      dados = player->outrosDados;

      if(dados != NULL) dados->estado = CHECKED;
      else{
            //TODO: Jogador não inicializado...
      };
};

Stats* initGame(){
      Stats *stats;

      stats = calloc(sizeof(Stats), 1);

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

void restartJogador(PlayerBasic *player){
      Dados *dados;

      dados = player->outrosDados;

    if(player != NULL){
        dados->estado = NOTPLAYED;
        resetJogador(player);
    };
};

void restartJogadores(PlayerBasic **lp){
    PlayerBasic *player;

    player = *lp;

    if(player != NULL){
        restartJogador(player);
        player = player->prox;
        while(player!=*lp){
            restartJogador(player);
            player = player->prox;
        };
    };
};

PlayerBasic* criarJogador(int mode){
      PlayerBasic *novoJogador;
      Dados *dados;

      novoJogador = calloc(sizeof(PlayerBasic), 1);
      dados = calloc(sizeof(Dados), 1);

      novoJogador = createJogador(mode);
      dados->nome = calloc(20, sizeof(char));
      strcpy(dados->nome, getNome());
      dados->nJogador = 0;
      dados->dinheiro = (mode==PADRAO)?(500):(getDinheiro());
      dados->aposta = 0;
      dados->estado = NOTPLAYED;
      dados->AI = getAI();
      dados->badge = OTHER;
      novoJogador->outrosDados = dados;
      return novoJogador;
};

void insereJogadorLista(Stats *stats, PlayerBasic *jogador){
    PlayerBasic *plaux;
    Dados *dadosNovo, *dados;

    dadosNovo = jogador->outrosDados;

    plaux = *(stats->jogadores);
    if (plaux == NULL) *(stats->jogadores) = jogador;
    else {
        plaux = plaux->ant;
        jogador->prox = plaux->prox;
        jogador->ant = plaux;
        jogador->prox->ant = jogador;
        plaux->prox = jogador;
        dados = jogador->ant->outrosDados;
        dadosNovo->nJogador = dados->nJogador+1;
    };
};

void addJogador(Stats *stats, int mode){

    insereJogadorLista(stats, criarJogador(mode));
    stats->nJogadoresTotal += 1;
    stats->nJogadoresAtivo += 1;
};

void resetEstado(Stats *stats){
    PlayerBasic *plaux;
    Dados *dados;

    plaux = *(stats->jogadores);
    dados = plaux->outrosDados;
    do{
        if(dados->estado!=FOLDED) dados->estado = NOTPLAYED;
        plaux = plaux->prox;
        dados = plaux->outrosDados;
    }while(plaux->prox != (*(stats->jogadores))->prox);
};

void resetGame(Stats *stats){
      PlayerBasic *player;
      Dados *dados;

      player = getVencedor(stats);
      if(player != NULL){
            dados = player->outrosDados;
            dados->dinheiro += stats->valorDaMesa;
      };
      stats->nJogadoresAtivo = getNJogadores(stats);
      stats->smallBlind = 0;
      stats->bigBlind = 0;
      stats->apostaAtual = 0;
      stats->valorDaMesa = 0;
      stats->rodadaAtual = 0;
      destroiBaralho(stats->baralhoJogo);
      stats->baralhoJogo = criaBaralho();

};

int fimRodada(Stats *stats){
    PlayerBasic *plaux;
    Dados *dados;
    int i = 1;

    plaux = *(stats->jogadores);
    dados = plaux->outrosDados;

    do{
        if(dados->estado == NOTPLAYED || dados->estado == CHECKED) i = 0;
        plaux = plaux->prox;
        dados = plaux->outrosDados;
    }while(plaux != *(stats->jogadores));
    return i;
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
      dado = plaux->outrosDados;
      while(dado->nJogador != np){
                  plaux = plaux->prox;
                  dado = plaux->outrosDados;
      }
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
      resetGame(stats);
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

void setBlind(Stats *stats){
    PlayerBasic *plaux;
    Dados *dados;
    Carta *c;

    plaux = *(stats->jogadores);
    dados = plaux->outrosDados;

    while(dados->badge!=BBLIND){
            plaux = plaux->prox;
            dados = plaux->outrosDados;
    }
    stats->bigBlind = getBBlind();
    stats->apostaAtual = stats->bigBlind;
    call(plaux, stats->bigBlind);
    dados->estado = NOTPLAYED;
    stats->smallBlind = getSBlind();
    call(plaux->ant, stats->smallBlind);
    dados = plaux->ant->outrosDados;
    dados->estado = NOTPLAYED;
};

void setVencedor(PlayerBasic *player){                //Algoritmo passível de alteração
      Dados *dado;

      dado = player->outrosDados;
      dado->badge = WINNER;
};

PlayerBasic* getVencedor(Stats *stats){
      PlayerBasic *plaux;
      Dados *dado;
      int end = 0;

      plaux = *(stats->jogadores);
      if (plaux == NULL) return NULL;
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

int getNJogadores(Stats *stats){
      PlayerBasic *plaux, **lj;
      int x = 0;

      lj = stats->jogadores;
      plaux = *lj;
      if(plaux == NULL) return 0;
      else{
            do{
                  x++;
                  plaux = plaux->prox;
            }while(plaux!=*lj);
            return x;
      }
};

#endif
