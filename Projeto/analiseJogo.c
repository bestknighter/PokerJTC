#include <stdlib.h>
#include "jogadores.h"

struct estatJogo{
    int nJogadoresTotal;
    int nJogadoresAtivo;
    int smallBlind;
    int bigBlind;
    int apostaAtual;
    int valorDaMesa;
    int rodadaAtual;
    struct jogador **jogadores;
    struct carta *maoMesa;
}Stats;

void printJogadores(struct jogador **lj){
    struct jogador *aux;
    
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
}

void imprimeJogo(){
    printf("\tRODADA:  %d\n", Stats.rodadaAtual);
    printf(" - Jogadores na mesa:\td\n", Stats.nJogadoresTotal);
    printf(" - Jogadores na partida:\t%d\n", Stats.nJogadoresAtivo);
    printf(" - Small Blind:  %d\tBig Blind:   %d\n", Stats.smallBlind, Stats.bigBlind);
    printf(" - Valor da aposta:\t%d\n", Stats.apostaAtual);
    printf(" - Valor da mesa:\t%d\n", Stats.valorDaMesa);
    printf(" - Jogadores na mesa:");
    printJogadores(Stats.jogadores);
}
