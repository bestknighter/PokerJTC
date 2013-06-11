#include "printer.h"

void imprimeJogadores(Player **lj){
    Player *aux;
    
    aux = *lj;
    if(aux == NULL) printf ("Sem jogadores na rodada!");
    else{
        printf("%s", aux->nome);
        while(aux->proximo != (*lj)){
            aux = aux->proximo;
            printf (", ");
            printf("%s", aux->nome);
        };
        printf (".");
    };
};

void imprimeJogo(Stats *stats){
    printf("\t\tRODADA:  %d\n", stats->rodadaAtual);
    printf(" - Jogadores na mesa:\t");
    imprimeJogadores(stats->jogadores);
    printf("\n - Numero de Jogadores na mesa (pote):\t\t%d\n", stats->nJogadoresTotal);
    printf(" - Numero de Jogadores na partida:\t%d\n", stats->nJogadoresAtivo);
    printf(" - Small Blind:\t\t%d\tBig Blind:\t%d\n", stats->smallBlind, stats->bigBlind);
    printf(" - Valor da aposta:\t%d\n", stats->apostaAtual);
    printf(" - Valor da mesa:\t%d\n", stats->valorDaMesa);
};

void imprimeCarta(Carta *c, int censurado){
    switch (c->valor){
        case AS:
            (censurado)?(printf("%c", 216)):(printf("A"));
            break;
        case JOKER:
            (censurado)?(printf("%c", 216)):(printf("J"));
            break;
        case KING:
            (censurado)?(printf("%c", 216)):(printf("K"));
            break;
        case QUEEN:
            (censurado)?(printf("%c", 216)):(printf("Q"));
            break;
        default:
            (censurado)?(printf("%c", 216)):(printf("%d", c->valor));
            break;
    };
    (censurado)?(printf("%c", 216)):(printf("%c", c->naipe));
};

void imprimeBaralho(Carta **lc, int censurado){
    Carta *c;
    
    c = *lc;
    
    if (c==NULL) printf("Nao ha cartas!");
    else while(c!=NULL){
        imprimeCarta(c, censurado);
        printf("  ");
        c = c->prox;
    };
};

void imprimeJogador(Player *player, int censurado){
    printf("%s", player->nome);
    switch (player->badge){
        case DEALER:
            printf(" (DEALER)\n");
            break;
        case SBLIND:
            printf(" (SMALL BLIND)\n");
            break;
        case BBLIND:
            printf(" (BIG BLIND)\n");
            break;
        default:
            break;
    };
    imprimeBaralho(player->mao, censurado);
};

void imprimeMesa(Stats *stats, int view){
    Player *plaux;
    Carta *caux;
    plaux = *(stats->jogadores);
    
    if(stats->nJogadoresTotal>0){
        while(plaux->proximo != (*(stats->jogadores))->proximo){
            imprimeJogador(plaux, (view==plaux->nJogador)?(0):(1));
            printf("\n\n");
            plaux = plaux->proximo;
        };
        printf("\n\n\nMesa:");
        imprimeBaralho(stats->maoMesa, 0);
    };
};
