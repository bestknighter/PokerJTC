#ifndef _BARALHO_C
#define _BARALHO_C
#include "baralho.h"

Carta* criaCarta(tipo_valor valor, tipo_naipe naipe){
      Carta *novo;

      novo = calloc(1, sizeof(Carta));
      novo->valor = valor;
      novo->naipe = naipe;
      novo->prox = NULL;
      novo->ant = NULL;

      return novo;
};

void addCarta(Carta **binicio, Carta* novo){
      Carta *fp;

      fp = *binicio;

    if (fp != NULL){
        while (fp->prox != NULL) fp = fp->prox;
        fp->prox = novo;
        novo->ant = fp;
    }else *binicio = (Carta*) novo;
};

void deletarCarta(Carta **lc, tipo_naipe naipe, tipo_valor valor){
    Carta *c;

    c = tirarCarta(lc, naipe, valor);
    free(c);
};

Carta* topCarta(Carta **lc){
    return tirarCarta(lc, (*(lc))->naipe, (*(lc))->valor);
};

Carta* tirarCarta(Carta **lc, tipo_naipe naipe, tipo_valor valor){
    Carta *c;

    c = *lc;

    if(c!= NULL){
        while(c->prox!=NULL && !(c->naipe == naipe && c->valor == valor)) c = c->prox;
        if(c->naipe == naipe && c->valor == valor){
            if (c->ant != NULL) c->ant->prox = c->prox;
            else *lc = c->prox;
            if (c->prox != NULL) c->prox->ant = c->ant;
            return c;
        };
    };
    return NULL;
};

Carta** criaBaralho(){
    Carta **binicio;
    int i, j;

    binicio = calloc(1, sizeof(Carta**));
    for(i=0; i<4; i++)
        for (j=2; j<15; j++){
            addCarta(binicio, criaCarta(j, i+3));
        };
    return binicio;
};

void destroiBaralho(Carta **lc){
    Carta *c, *aux;

    c = *lc;
    if(c!=NULL){
        while(c->prox!=NULL) c = c->prox;
        while(c->ant!=NULL){
            aux = c;
            c = c->ant;
            free(aux);
        };
        free(c);
        *lc = NULL;
    };
};

void emb(Carta **lc){
    Carta *c, **novo;
    int x, tam;

    srand(time(NULL));
    srand(rand());

    novo = calloc(1, sizeof(Carta**));

    c = *lc;
    while(c!=NULL){
        tam = tamanho(lc);
        for(x = rand()%tam; x>0; x--) c = c->prox;
        addCarta(novo, criaCarta(c->valor, c->naipe));
        deletarCarta(lc, c->naipe, c->valor);
        c = *lc;
    };
    *lc = *novo;
};

void embaralha(Carta **lc){
    emb(lc);
    emb(lc);
    emb(lc);
};

int tamanho(Carta **lc){
    Carta *c;
    int x;

    c = *lc;
    if (c == NULL) return 0;
    else{
        for(x = 0; c != NULL; x++, c = c->prox);
        return x;
    };
};
 #endif
