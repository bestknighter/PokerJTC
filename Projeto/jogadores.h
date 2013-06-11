#ifndef _JOGADORES
#define _JOGADORES

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

typedef struct jogador{
    char *nome;
    int nJogador;
    int dinheiro;
    int apostaAtual;
    int estado;
    int AI;
    int badge;
    struct carta **mao;
    struct jogador *proximo;
    struct jogador *ant;
}Player;

void fold(Player *pl);

void call(Player *pl, int valorDaApostaAtual);

int raise(Player *pl, int inicial);

void check(Player *pl);

#endif
