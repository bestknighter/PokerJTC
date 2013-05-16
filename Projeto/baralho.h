enum naipe {
    COPAS = 3,
    OUROS,
    PAUS,
    ESPADAS
};

enum valor {
    AS = 0,
    JOKER = 11,
    QUEEN,
    KING
};

typedef enum naipe tipo_naipe;
typedef enum valor tipo_valor;

struct carta{
    tipo_valor valor;
    tipo_naipe naipe;
    struct carta *prox;
    struct carta *ant;
};

/* Esta função recebe um ponteiro para o baralho, o valor da carta a ser
*  adicionada e seu respectivo naipe e então os adiciona no baralho.
*/
void addCarta(struct carta *, tipo_valor, tipo_naipe);

/* Esta função retorna um endereço de um ponteiro para struct carta. A função
*  criará uma fila organizada com todas as 52 cartas normais de um baralho.
*/
struct carta** criaBaralho();
