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
    *(stats->jogadores) = NULL;
    *(stats->maoMesa) = NULL;
    return stats;
};

void resetGame(Stats *stats){
    stats->smallBlind = 0;
    stats->bigBlind = 0;
    stats->apostaAtual = 0;
    stats->valorDaMesa = 0;
    stats->rodadaAtual = 0;
    restartJogadores(stats->jogadores);
    destroiBaralho(stats->maoMesa);
};

void restartJogador(Player *player){
    if(player != NULL){
        player->estado = NOTPLAYED;
        destroiBaralho(player->mao);
    };
};

void resetJogador(Player *player){
    if(player != NULL){
        player->estado = NOTPLAYED;
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

void resetJogadores(Player **lp){
    Player *player;
    
    player = *lp;
    
    if(player != NULL){
        resetJogador(player);
        player = player->proximo;
        while(player!=*lp){
            resetJogador(player);
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
    novoJogador->AI = (mode==PADRAO)?(0):(getAI());
    novoJogador->badge = OTHER;
    novoJogador->mao = 0;
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
