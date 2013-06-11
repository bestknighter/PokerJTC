#include "core.h"

Stats* initGame(){
    Stats *stats;
    
    stats = malloc(sizeof(Stats));
    
    stats->nJogadoresTotal = 0;
    stats->nJogadoresAtivo = 0;
    stats->smallBlind = 0;
    stats->bigBlind = 0;
    stats->apostaAtual = 0;
    stats->valorDaMesa = 0;
    stats->rodadaAtual = 0;
    stats->jogadores = calloc(1, sizeof(Player*));
    stats->maoMesa = calloc(1, sizeof(Carta*));
    stats->baralhoJogo = calloc(1, sizeof(Carta*));
    stats->baralhoJogo = criaBaralho();
    embaralha(stats->baralhoJogo);
    *(stats->jogadores) = NULL;
    *(stats->maoMesa) = NULL;
    return stats;
};

void restartGame(Stats *stats){
    stats->smallBlind = 0;
    stats->bigBlind = 0;
    stats->apostaAtual = 0;
    stats->valorDaMesa = 0;
    stats->rodadaAtual = 0;
    restartJogadores(stats->jogadores);
    destroiBaralho(stats->maoMesa);
    destroiBaralho(stats->baralhoJogo);
    stats->baralhoJogo = criaBaralho();
    embaralha(stats->baralhoJogo);
};

void restartJogador(Player *player){
    if(player != NULL){
        player->estado = NOTPLAYED;
        destroiBaralho(player->mao);
    };
};

void restartJogadores(Player **lp){
    Player *player;
    
    player = *lp;
    
    if(player != NULL){
        restartJogador(player);
        player = player->proximo;
        while(player!=*lp){
            restartJogador(player);
            player = player->proximo;
        };
    };
};

Player* criarJogador(int mode){
    Player *novoJogador;
    
    novoJogador = malloc(sizeof(Stats));
    novoJogador->nome = calloc(20, sizeof(char));
    strcpy(novoJogador->nome, getNome());
    novoJogador->nJogador = 0;
    novoJogador->dinheiro = (mode==PADRAO)?(500):(getDinheiro());
    novoJogador->apostaAtual = 0;
    novoJogador->estado = NOTPLAYED;
    novoJogador->AI = getAI();
    novoJogador->badge = OTHER;
    novoJogador->mao = calloc (1, sizeof(Carta*));
    *(novoJogador->mao) = NULL;
    novoJogador->proximo = novoJogador;
    novoJogador->ant = novoJogador;
    return novoJogador;
};

void insereJogadorLista(Stats *stats, Player *jogador){
    Player *plaux;
    
    plaux = *(stats->jogadores);
    if (plaux == NULL) *(stats->jogadores) = jogador;
    else {
        plaux = plaux->ant;
        jogador->proximo = plaux->proximo;
        jogador->ant = plaux;
        jogador->proximo->ant = jogador;
        plaux->proximo = jogador;
        jogador->nJogador = jogador->ant->nJogador+1;
    };
};

void addJogador(Stats *stats, int mode){
    Player *novoJogador;
    
    novoJogador = criarJogador(mode);
    insereJogadorLista(stats, novoJogador);
    stats->nJogadoresTotal++;
    stats->nJogadoresAtivo++;
};

void resetJogadores(Stats *stats){
    Player *plaux;
    
    plaux = *(stats->jogadores);
    do{
        if(plaux->estado!=FOLDED) plaux->estado = NOTPLAYED;
        plaux = plaux->proximo;
    }while(plaux->proximo != (*(stats->jogadores))->proximo);
};

void calculoPote(Stats *stats){
    Player *plaux;
    int pote = 0;
    
    plaux = *(stats->jogadores);
    do{
        pote += plaux->apostaAtual;
        plaux = plaux->proximo;
    }while(plaux->proximo != (*(stats->jogadores))->proximo);
    stats->valorDaMesa = pote;
};

int fimRodada(Stats *stats){
    Player *plaux;
    int i = 1;
    
    plaux = *(stats->jogadores);
    do{
        if(plaux->estado == NOTPLAYED || plaux->estado == CHECKED) i = 0;
        plaux = plaux->proximo;
    }while(plaux != *(stats->jogadores));
    return i;
};

void badgeSetter(Stats *stats){
    Player *plaux;
    Carta *c;
    int max = 0, np = -1;
    
    plaux = *(stats->jogadores);
    do{
        c = topCarta(stats->baralhoJogo);
        addCarta(plaux->mao, c->valor, c->naipe);
        if(c->valor>max){
            max = c->valor;
            np = plaux->nJogador;
        };
        free(c);
        plaux = plaux->proximo;
    }while(plaux->proximo != (*(stats->jogadores))->proximo);
    while(plaux->nJogador != np) plaux = plaux->proximo;
    plaux->badge = DEALER;
    if(plaux->proximo->proximo != plaux){
        plaux->proximo->badge = SBLIND;
        plaux->proximo->proximo->badge = BBLIND;
    } else plaux->proximo->badge = BBLIND;
    restartGame(stats);
};

void setBlind(Stats *stats){
    Player *plaux;
    Carta *c;
    
    plaux = *(stats->jogadores);
    
    while(plaux->badge!=BBLIND) plaux = plaux->proximo;
    stats->bigBlind = getBBlind();
    stats->apostaAtual = stats->bigBlind;
    call(plaux, stats->bigBlind);
    plaux->estado = NOTPLAYED;
    stats->smallBlind = getSBlind();
    call(plaux->ant, stats->smallBlind);
    plaux->ant->estado = NOTPLAYED;
};

Player* getVencedor(Stats *stats){
    Player *plaux;
    
    plaux = (*(stats->jogadores));
    while(plaux->estado != WINNER) plaux = plaux->proximo;
    return plaux;
};
