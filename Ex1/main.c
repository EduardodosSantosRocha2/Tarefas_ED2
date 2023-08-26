#include <stdio.h>
#include <stdlib.h>
#include "vet.h"




int main()
{
    int vet[20], valor, escolha, pos, pos1;
    for(int i= 0; i<20;i++){
        vet[i] = NULL;
    }
    do
    {
        printf("Digite (1) para adicionar valor ou (0) para sair: \n");
        scanf("%d",&escolha);

        if(escolha !=0)
        {
            switch(escolha)
            {
            case 1:

                pos = mdiv(23);
                pos1 = sondagem(pos, vet);
                vet[pos1] = 23;


                pos = mdiv(35);
                pos1 = sondagem(pos, vet);
                vet[pos1] = 35;

                pos = mdiv(42);
                pos1 = sondagem(pos, vet);
                vet[pos1] = 42;

                pos = mdiv(12);
                pos1 = sondagem(pos, vet);
                vet[pos1] = 12;

                pos = mdiv(7);
                pos1 = sondagem(pos, vet);
                vet[pos1] = 7;

                pos = mdiv(13);
                pos1 = sondagem(pos, vet);
                vet[pos1] = 13;


                pos = mdiv(6);
                pos1 = sondagem(pos, vet);
                vet[pos1] = 6;

                 pos = mdiv(49);
                pos1 = sondagem(pos, vet);
                vet[pos1] = 49;

                 pos = mdiv(72);
                pos1 = sondagem(pos, vet);
                vet[pos1] = 72;

                 pos = mdiv(3);
                pos1 = sondagem(pos, vet);
                vet[pos1] = 3;



                break;
            }
        }
    }
    while(escolha!=0);

    for(int i=0; i<20;i++){
        printf("Vet: pos %d  = [%d] \n", i,vet[i]);
    }


    return 0;
}
