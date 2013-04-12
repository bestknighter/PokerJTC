struct jogador{
    char nome[20];
    int nJogador;
    int dinheiro;
    int apostaAtual;
    int estado;
    int AI;
    struct carta *mao;
    struct jogador *proximo;
};
