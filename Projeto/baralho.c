#include <stdlib.h>
#include "baralho.h"

/* Esta função recebe um ponteiro para o baralho, o valor da carta a ser
*  adicionada e seu respectivo naipe e então os adiciona no baralho.
*/
void addCarta(struct carta *binicio, tipo_valor valor, tipo_naipe naipe){
    struct carta *novo, *fp;
    
    novo = (struct carta*) malloc(sizeof(struct carta));
    novo->valor = valor;
    novo->naipe = naipe;
    novo->prox = NULL;
    novo->ant = NULL;
    fp = binicio;
    if (fp != NULL){
        while (fp->prox != NULL) fp = fp->prox;
        fp->prox = novo;
        novo->ant = fp;
    }else binicio = novo;
}

/* Esta função retorna um endereço de um ponteiro para struct carta. A função
*  criará uma fila organizada com todas as 52 cartas normais de um baralho.
*/
struct carta** criaBaralho(){
    struct carta *binicio;
    int i, j;
    
    binicio = NULL;
    for(i=0; i<4; i++)
        for (j=0; j<13; j++){
            addCarta(binicio, j, i+3);
        };
};

void deletarCarta(struct carta **lc, tipo_naipe naipe, tipo_valor valor){
    struct carta *c;
    
    c = *lc;
    
    if(c!= NULL){
        while(c->prox!=NULL && c->naipe != naipe && c->valor != valor) c = c->prox;
        if(c->naipe == naipe && c->valor == valor){
            if (c->ant != NULL) c->ant->prox = c->prox;
            else *lc = c->prox;
            if (c->prox != NULL) c->prox->ant = c->ant;
            free(c);
            c = NULL;
        };
    };
};

struct carta* tirarCarta(struct carta **lc, tipo_naipe naipe, tipo_valor valor){
    struct carta *c;
    
    c = *lc;
    
    if(c!= NULL){
        while(c->prox!=NULL && c->naipe != naipe && c->valor != valor) c = c->prox;
        if(c->naipe == naipe && c->valor == valor){
            if (c->ant != NULL) c->ant->prox = c->prox;
            else *lc = c->prox;
            if (c->prox != NULL) c->prox->ant = c->ant;
            return c;
        };
    };
};

void destroiBaralho(struct carta **lc){
    struct carta *c, *aux;
    
    c = *lc;
    
    while(c!=NULL){
        aux = c;
        c = c->prox;
        free(aux);
    };
};
