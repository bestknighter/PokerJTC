enum naipe {
    COPAS = 3,
    OUROS,
    PAUS,
    ESPADAS
};

enum valor {
    AS = 0,
    KING = 11,
    QUEEN,
    JOKER
};

typedef enum naipe tipo_naipe;
typedef enum valor tipo_valor;

typedef struct carta{
    tipo_valor valor;
    tipo_naipe naipe;
    struct carta *prox;
    struct carta *ant;
}Carta;


/* Esta função recebe um ponteiro para o baralho, o valor da carta a ser
*  adicionada e seu respectivo naipe e então os adiciona no baralho
*/
void addCarta(Carta **, tipo_valor, tipo_naipe);


/* Esta função retorna um ponteiro para lista de Carta (baralho). A função
*  criará uma fila organizada com todas as 52 cartas normais de um baralho
*/
Carta** criaBaralho();


/* Esta função recebe um ponteiro para lista de Carta (baralho), um naipe
*  e um valor, procura a carta no baralho e, se a encontrar, a deleta
*/
void deletarCarta(Carta **lc, tipo_naipe naipe, tipo_valor valor);


/* Esta função recebe um ponteiro para lista de Carta (baralho), um naipe e um 
*  valor, procura a carta no baralho e, se a encontrar, a remove e a retorna
*/
Carta* tirarCarta(Carta **lc, tipo_naipe naipe, tipo_valor valor);


/*  Esta função recebe um ponteiro para lista de
*   Carta (baralho) e destroi o baralho por completo
*/
void destroiBaralho(Carta **lc);


/*  Esta função recebe um ponteiro para lista de Carta (baralho)
*   e retorna a quantidade de cartas que ela possui
*/
int tamanho(Carta **lc);


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
