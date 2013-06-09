#include <stdlib.h>
#include <stdio.h>
#include "analiseJogo.h"

void imprimeJogadores(Player **lj){
    Player *aux;
    
    aux = *lj;
    if(aux == NULL) printf ("Sem jogadores na rodada!");
    else if(aux->proximo == NULL) puts(aux->nome);
    else{
        puts(aux->nome);
        while(aux->proximo != NULL){
            printf (", ");
            puts(aux->nome);
        }
        printf (".\n");
    }
};

void imprimeJogo(){
    printf("\tRODADA:  %d\n", Stats.rodadaAtual);
    printf(" - Jogadores na mesa:");
    imprimeJogadores(Stats.jogadores);
    printf(" - Numero de Jogadores na mesa:\td\n", Stats.nJogadoresTotal);
    printf(" - Numero de Jogadores na partida:\t%d\n", Stats.nJogadoresAtivo);
    printf(" - Small Blind:  %d\tBig Blind:   %d\n", Stats.smallBlind, Stats.bigBlind);
    printf(" - Valor da aposta:\t%d\n", Stats.apostaAtual);
    printf(" - Valor da mesa:\t%d\n", Stats.valorDaMesa);
};

void imprimeCarta(Carta *c){
    switch (c->valor){
        case AS:
            printf("A");
            break;
        case JOKER:
            printf("J");
            break;
        case KING:
            printf("K");
            break;
        case QUEEN:
            printf("Q");
            break;
        default:
            printf("%d", c->valor);
            break;
    };
    printf("%c", c->naipe);
};

void imprimeBaralho(Carta **lc){
    Carta *c;
    
    c = *lc;
    
    if (c==NULL) printf("Nao ha cartas!");
    else while(c!=NULL){
        imprimeCarta(c);
        printf("  ");
        c = c->prox;
    };
};
