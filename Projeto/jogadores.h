typedef struct jogador{
    char nome[20];
    int nJogador;
    int dinheiro;
    int apostaAtual;
    int estado;
    int AI;
    struct carta **mao;
    struct jogador *proximo;
}Player;


/*  FUN��O AINDA N�O IMPLEMENTADA
*   realiza as opera��es necess�rias quando algum jogador d� fold
*/
void fold(void);


/*  FUN��O AINDA N�O IMPLEMENTADA
*   realiza as opera��es necess�rias quando algum jogador d� call
*/
void call(void);


/*  FUN��O AINDA N�O IMPLEMENTADA
*   realiza as opera��es necess�rias quando algum jogador d� raise
*/
void raise(void);


/*  FUN��O AINDA N�O IMPLEMENTADA
*   realiza as opera��es necess�rias quando algum jogador d� check
*/
void check(void);
