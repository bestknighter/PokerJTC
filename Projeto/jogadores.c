#include "jogadores.h"

void fold(Player *pl){
    pl->estado = FOLDED;
};

void call(Player *pl, int valorDaApostaAtual){
    if(pl->dinheiro >= pl->dinheiro + pl->apostaAtual - valorDaApostaAtual){
        pl->dinheiro += pl->apostaAtual;
        pl->apostaAtual = valorDaApostaAtual;
        pl->dinheiro -= pl->apostaAtual;
        pl->estado = PLAYED;
    }else{
        //TODO: Erro! Dinheiro não suficiente...
    };
};

int raise(Player *pl){
    int i;
    i = getRaise();
    (i>0)?:((i==0)?(/*Error(RAISE_INVALIDO),*/ system("PAUSE"), exit(1)):(i=-1*i));
    pl->apostaAtual += i;
    pl->dinheiro -= i;
    pl->estado = PLAYED;
    return i;
};

void check(Player *pl){
    pl->estado = CHECKED;
};
