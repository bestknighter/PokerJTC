#ifndef _OUTPUT_C
#define _OUTPUT_C
#include "output.h"

void outGetNome(){
      printf("Digite o nome do Jogador: ");
};

void outGetDinheiro(){
      printf("Digite a quantidade de dinheiro inicial (valores inteiros): ");
};

void outGetAI(){
      printf("Escolha uma opcao\n0 - Humano\n1 - Inteligencia 0 (AI burra)\n2 - Inteligencia 1\nSua escolha: ");
};

void outGetRaise(){
      printf("Em quanto deseja aumentar o valor da aposta:? ");
};

void outGetBBlind(){
      printf("Digite o valor da Big Blind: ");
};

void outGetSBlind(){
      printf("Digite o valor da Small Blind: ");
};

void outSemJogadores(){
      printf ("Sem jogadores!");
};

#endif
