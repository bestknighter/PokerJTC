#include "jogadores.h"
#include "baralho.h"

struct estatJogo{
    int nJogadoresTotal;
    int nJogadoresAtivo;
    int smallBlind;
    int bigBlind;
    int apostaAtual;
    int valorDaMesa;
    int rodadaAtual;
    struct jogador **jogadores;
    struct carta **maoMesa;
}Stats;


/*  Esta fun��o imprime todos os jogadores da lista.
*   Recebe Player **lj
*/
void imprimeJogadores(Player **lj);


/*  Esta fun��o imprime as estat�sticas do jogo.
*/
void imprimeJogo();


/*  Esta fun��o recebe um ponteiro para Carta e o imprime na tela
*/
void imprimeCarta(Carta *c);


/*  Esta fun��o recebe um ponteiro para uma lista de cartas (baralho)
*   e imprime, utilizando a fun��o imprimeCarta, todo o baralho na tela
*/
void imprimeBaralho(Carta **lc);
