#include "analiseJogo.h"

int main(int argc, char *argv[]){
    Carta **teste, *aux;
    
    printf("Testado baralho.c:\n\nCriando baralho:\n");
    teste = criaBaralho();
    imprimeBaralho(teste);
    printf("\n\nEmbaralha:\n");
    embaralha(teste);
    imprimeBaralho(teste);
    printf("\n\nDestruindo:\n");
    destroiBaralho(teste);
    imprimeBaralho(teste);
    printf("\n\n");
    system("PAUSE");
    return 0;
}
