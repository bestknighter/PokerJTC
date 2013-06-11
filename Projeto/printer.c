#include "printer.h"

void imprimeJogadores(Player **lj){
    Player *aux;
    
    aux = *lj;
    if(aux == NULL) printf ("Sem jogadores!");
    else{
        printf("%s", aux->nome);
        switch (aux->AI){
            case AI0:
                printf(" (AI - 0)");
                break;
            case AI1:
                printf(" (AI - 1)");
                break;
            default:
                break;
        };
        aux = aux->proximo;
        while(aux != (*lj)){
            printf (", ");
            printf("%s", aux->nome);
            switch (aux->AI){
                case AI0:
                    printf(" (AI - 0)");
                    break;
                case AI1:
                    printf(" (AI - 1)");
                    break;
                default:
                    break;
            };
            aux = aux->proximo;
        };
        printf (".");
    };
};

void imprimeJogo(Stats *stats){
    printf("\t\tRODADA:  %d\n", (stats->rodadaAtual)+1);
    printf(" - Jogadores na mesa:\t");
    imprimeJogadores(stats->jogadores);
    printf("\n - Numero de Jogadores na mesa:\t\t%d\n", stats->nJogadoresTotal);
    printf(" - Numero de Jogadores na partida:\t%d\n", stats->nJogadoresAtivo);
    printf(" - Small Blind:\t\t%d\tBig Blind:\t%d\n", stats->smallBlind, stats->bigBlind);
    printf(" - Valor da aposta:\t\t%d\n", stats->apostaAtual);
    printf(" - Valor da mesa (pote):\t%d\n", stats->valorDaMesa);
};

void imprimeCarta(Carta *c, int censurado){
    switch (c->valor){
        case AS:
            (censurado)?(printf("%c", 219)):(printf("A"));
            break;
        case JOKER:
            (censurado)?(printf("%c", 219)):(printf("J"));
            break;
        case KING:
            (censurado)?(printf("%c", 219)):(printf("K"));
            break;
        case QUEEN:
            (censurado)?(printf("%c", 219)):(printf("Q"));
            break;
        default:
            (censurado)?(printf("%c", 219)):(printf("%d", c->valor));
            break;
    };
    (censurado)?(printf("%c", 219)):(printf("%c", c->naipe));
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
    printf("%s ", player->nome);
    switch (player->badge){
        case DEALER:
            printf("(DEALER)");
            break;
        case SBLIND:
            printf("(SMALL BLIND)");
            break;
        case BBLIND:
            printf("(BIG BLIND)");
            break;
        default:
            break;
    };
    switch (player->AI){
        case AI0:
            printf(" AI - 0");
            break;
        case AI1:
            printf(" AI - 1");
            break;
        default:
            break;
    };
    printf("\n");
    imprimeBaralho(player->mao, censurado);
    switch(player->estado){
        case FOLDED:
            printf("\t- FOLDED");
            break;
        case CALLED:
            printf("\t- CALLED");
            break;
        case RAISED:
            printf("\t- RAISED");
            break;
        case CHECKED:
            printf("\t- CHECKED");
            break;
        default:
            break;
    };
    printf("\nApostas: %d", player->apostaAtual);
};

void imprimeMesa(Stats *stats, int view){
    Player *plaux;
    Carta *caux;
    plaux = *(stats->jogadores);
    
    if(stats->nJogadoresTotal>0){
        do{
            imprimeJogador(plaux, (view == plaux->nJogador)?(0):(1));
            printf("\n\n");
            plaux = plaux->proximo;
        }while(plaux->proximo != (*(stats->jogadores))->proximo);
        printf("\n\nMesa: ");
        imprimeBaralho(stats->maoMesa, 0);
    };
};

int menuHumanos(Stats *stats, Player *plaux){
    int esc;
    imprimeJogo(stats);
    printf("\n");
    system("PAUSE");
    system("CLS");
    printf("\n\n\tJOGADOR %d\n", plaux->nJogador);
    printf("\t\"%s\"\n\n\n", plaux->nome);
    system("PAUSE");
    system("CLS");
    imprimeJogo(stats);
    printf("\n\n\tJOGADOR %d\n\n", plaux->nJogador);
    printf("\t\"%s\"\n\n", plaux->nome);
    imprimeMesa(stats, plaux->nJogador);
    printf("\n\nSeu dinheiro: %d\nSua aposta atual: %d\n\nEscolha sua opcao:\
    \n0 - Fold\n1 - Call\n2 - Raise\n3 - Check\nSua escolha: ", plaux->dinheiro, plaux->apostaAtual);
    scanf("%d", &esc);
    system("CLS");
    return esc;
};

void endScreen(Stats *stats){
    Player *plaux;
    imprimeJogo(stats);
    plaux = getVencedor(stats);
    printf("\n\n%s ganhou!\n\n", plaux->nome);
    system("PAUSE");
};

int menuPrincipal(){
    int esc;
    printf("\tPoker Modalidade Texas Holdem\nGrupo Engenharia de Computacao");
    printf("\n\n1 - Novo Jogo\n0 - Sair\n\nSua escolha: ");
    scanf("%d", &esc);
    return 10+esc;
};

int menuNovoJogo(Stats *stats){
    int esc;
    printf("\tNovo Jogo\nJogadores nessa partida: ");
    imprimeJogadores(stats->jogadores);
    printf("\n\n1 - Adicionar Jogador\n2 - Comecar Partida\n0 - Sair\n\nSua escolha: ");
    scanf("%d", &esc);
    return 110+esc;
};

void menuNovoJogador(Stats *stats){
    int esc;
    printf("Como deseja adicionar um novo jogador?\n1 - Padrao\n2 - Personalizado\nSua escolha: ");
    scanf("%d", &esc);
    system("CLS");
    esc--;
    (esc)?(addJogador(stats, PERSONALIZADO)):(addJogador(stats, PADRAO));
};

int novaPartida(){
    int esc;
    printf("\nDeseja uma nova partida?\n1 - Sim\n0 - Nao\nSua escolha: ");
    scanf("%d", &esc);
    return (esc)?(11):(0);
};

void novaRodada(Stats *stats){
    system("CLS");
    printf("\n\tFim da rodada\n\n\tRodada %d\n\n\n", stats->rodadaAtual+1);
    system("PAUSE");
    system("CLS");
};
