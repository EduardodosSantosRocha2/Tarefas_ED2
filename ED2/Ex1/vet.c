#include <stdio.h>
#include <stdlib.h>
#include "vet.h"

int mdiv(int valor){
    int Posiresto = valor%20;
    return Posiresto;
}

int sondagem(int pos, int vet[]){
    if(vet[pos] == NULL){
      return pos;
    }
    while(vet[pos]!=NULL){
        pos++;
    }
    return pos;
}
