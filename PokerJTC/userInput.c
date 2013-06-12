#include "userInput.h"

char* getNome(){
    char *aux, *nome;
    aux = calloc(99, sizeof(char));
    nome = calloc(20, sizeof(char));
    fflush(stdin);
    printf("Digite o nome do Jogador: ");
    gets(aux);
    *aux = toupper(*aux);
    strncpy(nome, aux, 20);
    free(aux);
    return nome;
};

int getDinheiro(){
    int i;
    system("CLS");
    printf("Digite a quantidade de dinheiro inicial (valores inteiros): ");
    scanf("%d", &i);
    return i;
};

int getAI(){
    int i;
    system("CLS");
    printf("Escolha uma opcao\n0 - Humano\n1 - Inteligencia 0 (AI burra)\n2 - Inteligencia 1\nSua escolha: ");
    scanf("%d", &i);
    system("CLS");
    return --i;
};

int getRaise(){
    int i;
    system("CLS");
    printf("Digite a quantidade que deseja aumentar o valor da aposta: ");
    scanf("%d", &i);    //TODO: Raise zero?
    system("CLS");
    return i;
};

int getBBlind(){
    int i;
    system("CLS");
    printf("Digite o valor da Big Blind: ");
    scanf("%d", &i);    //TODO: E se for negativo?
    system("CLS");
    return i;
};

int getSBlind(){
    int i;
    system("CLS");
    printf("Digite o valor da Small Blind: ");
    scanf("%d", &i);    //TODO: E se for negativo?
    system("CLS");
    return i;
};
