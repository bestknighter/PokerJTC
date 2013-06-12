#include "jogadores.h"

void fold(Player *pl){
    pl->estado = FOLDED;
};

void call(Player *pl, int valorDaApostaAtual){
    if(pl->dinheiro >= pl->dinheiro + pl->apostaAtual - valorDaApostaAtual){
        pl->estado = CALLED;
        pl->dinheiro += pl->apostaAtual;
        pl->apostaAtual = valorDaApostaAtual;
        pl->dinheiro -= pl->apostaAtual;
    }else{
        //TODO: Erro! Dinheiro não suficiente...
    };
};

int raise(Player *pl, int inicial){  //TODO: Raise invalido (menor que a Big Blind)
    int i;
    i = getRaise();
    (i>=0)?(i=i):(i=-1*i);
    pl->apostaAtual = inicial+i;
    pl->dinheiro -= i;
    pl->estado = RAISED;
    return i;
};

void check(Player *pl){
    pl->estado = CHECKED;
};
