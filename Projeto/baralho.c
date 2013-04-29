#include <stdlib.h>
#include "baralho.h"

/* Esta fun��o recebe um ponteiro para o baralho, o valor da carta a ser
*  adicionada e seu respectivo naipe e ent�o os adiciona no baralho.
*/
void addCarta(struct carta *binicio, tipo_valor valor, tipo_naipe naipe){
    struct carta *novo, *fp;
    
    novo = (struct carta*) malloc(sizeof(struct carta));
    novo->valor = valor;
    novo->naipe = naipe;
    fp = binicio;
    if (fp != NULL){
        while (fp->prox != NULL) fp = fp->prox;
        fp->prox = novo;
    }else binicio = novo;
}

/* Esta fun��o retorna um endere�o de um ponteiro para struct carta. A fun��o
*  criar� uma fila organizada com todas as 52 cartas normais de um baralho.
*/
struct carta** criaBaralho(){
    struct carta *binicio;
    int i, j;
    char x;
    
    binicio = NULL;
    for(i=0; i<4; i++)
        for (j=0; j<13; j++){
            switch (j){
                case 0:
                    x = 'A';
                    break;
                case 9:
                    x = 48;
                    break;
                case 10:
                    x = 'J';
                    break;
                case 11:
                    x = 'Q';
                    break;
                case 12:
                    x = 'K';
                    break;
                default:
                    x = j+49;
                    break;
            };
            addCarta(binicio, x, (char)i+3);
        };
}
