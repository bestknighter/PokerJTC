#ifndef _INPUT_C
#define _INPUT_C
#include "input.h"

char* inGetString(){
      char *aux;
      aux = calloc(99, sizeof(char));
      fflush(stdin);
      gets(aux);
      *aux = toupper(*aux);
      return aux;
};

int inGetInt(){
      int i;
      scanf("%d", &i);
      return i;
};

float inGetFloat(){
      int f;
      scanf("%f", &f);
      return f;
};

 #endif
