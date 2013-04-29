enum naipe {
    COPAS,
    ESPADAS,
    OURO,
    PAUS
};

enum valor {
    JOKER = 11,
    QUEEN,
    KING,
    AS
};

typedef enum naipe tipo_naipe;
typedef enum valor tipo_valor;

struct carta{
    tipo_valor valor;
    tipo_naipe naipe;
    struct carta *prox;
};

/* Esta fun��o recebe um ponteiro para o baralho, o valor da carta a ser
*  adicionada e seu respectivo naipe e ent�o os adiciona no baralho.
*/
void addCarta(struct carta *, tipo_valor, tipo_naipe);

/* Esta fun��o retorna um endere�o de um ponteiro para struct carta. A fun��o
*  criar� uma fila organizada com todas as 52 cartas normais de um baralho.
*/
struct carta** criaBaralho();
