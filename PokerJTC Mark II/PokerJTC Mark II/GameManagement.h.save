#ifndef _POKERGAME_H
#define _POKERGAME_H

enum mode {
    PADRAO = 0,
    PERSONALIZADO
};

enum estados {
    NOTPLAYED = -1,
    FOLDED = 0,
    CALLED,
    RAISED,
    CHECKED,
    WINNER
};

enum intel {
    HUMAN = -1,
    AI0 = 0,
    AI1
};

enum badges {
    DEALER = 0,
    SBLIND,
    BBLIND,
    OTHER
};

typedef struct estatJogo{
    int nJogadoresTotal;
    int nJogadoresAtivo;
    int smallBlind;
    int bigBlind;
    int apostaAtual;
    int valorDaMesa;
    int rodadaAtual;
    struct jogador **jogadores;
    struct carta **maoMesa;
    struct carta **baralhoJogo;
}Stats;

typedef struct playerData{
      char *nome;
      int AI;
      float dinheiro;
      float aposta;
      int estado;
      int badge;
      int nJogador;
}Dados;

void initJogador(PlayerBasic *player);

void setJogador(PlayerBasic *player, int mode);

void fold(PlayerBasic *player);

void call(PlayerBasic *player, int valor_da_aposta);

int raise(PlayerBasic *player, int valor_da_aposta);

void check(PlayerBasic *player);

Stats* initGame();

void resetGame(Stats *stats);

void badgeSetter(Stats *stats);

void calculoPote(Stats *stats);

void setVencedor(Stats *stats);

PlayerBasic* getVencedor(Stats *stats);

#endif
