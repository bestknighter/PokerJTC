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


/*  FUNÇÃO AINDA NÃO IMPLEMENTADA
*   realiza as operações necessárias quando algum jogador dá fold
*/
void fold(void);


/*  FUNÇÃO AINDA NÃO IMPLEMENTADA
*   realiza as operações necessárias quando algum jogador dá call
*/
void call(void);


/*  FUNÇÃO AINDA NÃO IMPLEMENTADA
*   realiza as operações necessárias quando algum jogador dá raise
*/
void raise(void);


/*  FUNÇÃO AINDA NÃO IMPLEMENTADA
*   realiza as operações necessárias quando algum jogador dá check
*/
void check(void);
