#ifndef _GAMELOGIC_C
#define _GAMELOGIC_C
#include "GameLogic.h"

void mainloop(){
      int esc = 1;
      Stats* stats;
      stats = initGame();
      do{
            system("CLS");
            switch(esc){
                  case 0:
                        break;
                  case 1:
                        esc = menuPrincipal();
                        break;
                  case 11:
                        esc = menuNovoJogo(stats);
                        break;
                  case 111:
                        menuNovoJogador(stats);
                        esc /= 10;
                        break;
                  case 112:
                        seletorRodada(stats);
                        esc = novaPartida();
                        if (esc == 11) resetGame(stats);
                        break;
                  case 10:
                  case 110:
                        esc = 0;
                        break;
            };
      }while(esc!=0);
};

void rodadaLoop(Stats *stats){
    PlayerBasic *plaux;
    Dados *dados;
    int esc;

    plaux = *(stats->jogadores);
    srand(time(NULL));
    srand(rand());
    while((!fimRodada(stats)) || (stats->nJogadoresAtivo>1)){
            dados = plaux->outrosDados;
        if(dados->estado==NOTPLAYED || dados->estado==CHECKED){
            if(dados->AI == HUMAN){
                esc = menuHumanos(stats, plaux);
            }else if(dados->AI == AI0){
                esc = rand()%4;
            }else{
                //TODO AI1
            };
            switch(esc){
                case 0:
                    fold(plaux);
                    stats->nJogadoresAtivo--;
                    break;
                case 1:
                    call(plaux, stats->apostaAtual);
                    break;
                case 2:
                    resetJogadores(stats);
                    stats->apostaAtual += raise(plaux, stats->apostaAtual);
                    break;
                case 3:     //TODO N�o permitido na primeira rodada!
                    check(plaux);
                    break;
                default:
                    //TODO opcao inexistente!
                    break;
            };
        };
        calculoPote(stats);
        plaux = plaux->prox;
    };
    resetJogadores(stats);
};

void seletorRodada(Stats *stats){
    do{
        switch (stats->rodadaAtual){
            case 0:
                prepR0(stats);
                calculoPote(stats);
                rodadaLoop(stats);
                (stats->nJogadoresAtivo>1)?(stats->rodadaAtual++):(stats->rodadaAtual = 7);
                break;
            case 1:
                prepR1(stats);
                novaRodada(stats);
                rodadaLoop(stats);
                (stats->nJogadoresAtivo>1)?(stats->rodadaAtual++):(stats->rodadaAtual = 7);
                break;
            case 2:
                prepR2(stats);
                novaRodada(stats);
                rodadaLoop(stats);
                (stats->nJogadoresAtivo>1)?(stats->rodadaAtual++):(stats->rodadaAtual = 7);
                break;
            case 3:
                prepR2(stats);
                novaRodada(stats);
                rodadaLoop(stats);
                (stats->nJogadoresAtivo>1)?(stats->rodadaAtual++):(stats->rodadaAtual = 7);
                break;
            case 4:
                showdown(stats);
                stats->rodadaAtual++;
                break;
            case 5:     //Showdown
                break;
            case 6:     //Desempate
                break;
            case 7:
                mostrarTelaFinal(stats);
                stats->rodadaAtual++;
                break;
        };
    }while(stats->rodadaAtual!=8);
};

void prepR0(Stats *stats){
    PlayerBasic*plaux;
    Carta *c;

    plaux = *(stats->jogadores);

    badgeSetter(stats);
    setBlind(stats);
    plaux = *(stats->jogadores);
    do{
        c = topCarta(stats->baralhoJogo);
        addCarta(plaux->mao, criaCarta(c->valor, c->naipe));
        plaux = plaux->prox;
    }while(plaux->prox != (*(stats->jogadores))->prox);
    do{
        c = topCarta(stats->baralhoJogo);
        addCarta(plaux->mao, criaCarta(c->valor, c->naipe));
        plaux = plaux->prox;
    }while(plaux->prox != (*(stats->jogadores))->prox);
};

void prepR1(Stats *stats){
    Carta *c;
    int x;

    c = topCarta(stats->baralhoJogo);
    free(c);
    for(x=0; x<3; x++){
        c = topCarta(stats->baralhoJogo);
        addCarta(stats->maoMesa, criaCarta(c->valor, c->naipe));
    };
};

void prepR2(Stats *stats){
    Carta *c;

    c = topCarta(stats->baralhoJogo);
    free(c);
    c = topCarta(stats->baralhoJogo);
    addCarta(stats->maoMesa, criaCarta(c->valor, c->naipe));
};

void showdown(Stats *stats){
    //TODO Show Down
};

void mostrarTelaFinal(Stats *stats){
    PlayerBasic *plaux;
    Dados *dados;

    plaux = *(stats->jogadores);
    dados = plaux->outrosDados;

    while(dados->estado > FOLDED){
            plaux = plaux->prox;
            dados = plaux->outrosDados;
    };
    dados->estado = WINNER;
    endScreen(stats);
};

#endif
