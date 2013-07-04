#ifndef _BARALHO_H
#define _BARALHO_H
#include <stdlib.h>
#include <time.h>

enum naipe {
    COPAS = 3,
    OUROS,
    PAUS,
    ESPADAS
};

enum valor {
    JOKER = 11,
    QUEEN,
    KING,
    AS
};

typedef enum naipe tipo_naipe;
typedef enum valor tipo_valor;

typedef struct carta{
    tipo_valor valor;
    tipo_naipe naipe;
    struct carta *prox;
    struct carta *ant;
}Carta;

/*    Esta função recebe um valor e um
*     naipe para e gera a carta desejada
*/
Carta* criaCarta(tipo_valor valor, tipo_naipe naipe);

/*    Esta função recebe um ponteiro para
*     o baralho e a carta a ser adicionada
*/
void addCarta(Carta **binicio, Carta* novo);

/*  Esta função recebe um ponteiro para lista de Carta (baralho), um naipe
*   e um valor, procura a carta no baralho e, se a encontrar, a deleta
*/
void deletarCarta(Carta **lc, tipo_naipe naipe, tipo_valor valor);

/*  Esta função recebe um ponteiro para lista de
*   Carta(baralho), remove a primeira carta e a retorna
*/
Carta* topCarta(Carta **lc);

/* Esta função recebe um ponteiro para lista de Carta (baralho), um naipe e um
*  valor, procura a carta no baralho e, se a encontrar, a remove e a retorna
*/
Carta* tirarCarta(Carta **lc, tipo_naipe naipe, tipo_valor valor);

/*  Esta função retorna um ponteiro para lista de Carta (baralho). A função
*   criará uma fila organizada com todas as 52 cartas normais de um baralho
*/
Carta** criaBaralho();

/*  Esta função recebe um ponteiro para lista de
*   Carta (baralho) e destroi o baralho por completo
*/
void destroiBaralho(Carta **lc);

/*  Esta função recebe um ponteiro para lista de
*   Carta (baralho) e a embaralha por completo
*   ATENÇÃO: SOMENTE USE A FUNÇÃO EMBARALHA, MOTIVO EXPLICADO NO COMENTÁRIO DELA
*/
void emb(Carta **lc);

/*  Esta função recebe um ponteiro para lista de Carta (baralho)
*   e a embaralha por completo
*   ATENÇÃO: USE ESSA FUNÇÃO PARA EMBARALHA, POIS ELA IMPLEMENTA UM
*   UM ALGORITMO DE EMBARALHAMENTO QUE UTILIZA A FUNÇÃO EMB E A DEIXA
*   MELHOR EMBARALHADA
*/
void embaralha(Carta **lc);

/*  Esta função recebe um ponteiro para lista de Carta (baralho)
*   e retorna a quantidade de cartas que ela possui
*/
int tamanho(Carta **lc);

#endif
