#include "gameLogic.h"

void rodadaLoop(Stats *stats){
    Player *plaux;
    int esc;
    
    plaux = *(stats->jogadores);
    srand(time(NULL));
    srand(rand());
    while((!fimRodada(stats)) || (stats->nJogadoresAtivo>1)){
        if(plaux->estado==NOTPLAYED || plaux->estado==CHECKED){
            if(plaux->AI == HUMAN){
                esc = menuHumanos(stats, plaux);
            }else if(plaux->AI == AI0){
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
        plaux = plaux->proximo;
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
    Player *plaux;
    Carta *c;
    
    plaux = *(stats->jogadores);
    
    badgeSetter(stats);
    setBlind(stats);
    plaux = *(stats->jogadores);
    do{
        c = topCarta(stats->baralhoJogo);
        addCarta(plaux->mao, c->valor, c->naipe);
        plaux = plaux->proximo;
    }while(plaux->proximo != (*(stats->jogadores))->proximo);
    do{
        c = topCarta(stats->baralhoJogo);
        addCarta(plaux->mao, c->valor, c->naipe);
        plaux = plaux->proximo;
    }while(plaux->proximo != (*(stats->jogadores))->proximo);
};

void prepR1(Stats *stats){
    Carta *c;
    int x;
    
    c = topCarta(stats->baralhoJogo);
    free(c);
    for(x=0; x<3; x++){
        c = topCarta(stats->baralhoJogo);
        addCarta(stats->maoMesa, c->valor, c->naipe);
    };
};

void prepR2(Stats *stats){
    Carta *c;
    
    c = topCarta(stats->baralhoJogo);
    free(c);
    c = topCarta(stats->baralhoJogo);
    addCarta(stats->maoMesa, c->valor, c->naipe);
};

void showdown(Stats *stats){
    //TODO Show Down
};

void mostrarTelaFinal(Stats *stats){
    Player *plaux;
    
    plaux = *(stats->jogadores);
    
    while(plaux->estado > FOLDED) plaux = plaux->proximo;
    plaux->estado = WINNER;
    endScreen(stats);
};

void mainLoop(){
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
                restartGame(stats);
                esc = menuNovoJogo(stats);
                break;
            case 111:
                menuNovoJogador(stats);
                esc /= 10;
                break;
            case 112:
                seletorRodada(stats);
                esc = novaPartida();
                break;
            case 10:
            case 110:
                esc = 0;
                break;
        };
    }while(esc!=0);
};
