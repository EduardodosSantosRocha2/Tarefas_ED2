#include <stdio.h>
#include <stdlib.h>



int buscaBinaria(int a[], int tamA, int elementoProcurado, int vet[]){
    int posIni = 0;
    int posFim = tamA - 1;
    int tamVet = 0;
    int i, j;
    while(posFim >= posIni){
        int m = (posIni + posFim) / 2;
        if(elementoProcurado == a[m]){
            if(a[m-1] == a[m]){
                i = m-1;
                while(a[i] == a[m]){
                    vet[tamVet] = i;
                    i--;
                    tamVet++;
                }
            }
            if(a[m+1] == a[m]){
                    j = m+1;
                    while(a[j] == a[m]){
                        vet[tamVet] = j;
                        j++;
                        tamVet++;
                    }
            }
            vet[tamVet] = m;
            tamVet++;
            return tamVet;
        }
        if(elementoProcurado < vet[m]){
            posFim = m-1;
        } else{
            posIni = m+1;
        }
    }
    return -1;
}


int main()
{

    int vet[10], tamVet=10, vetPosicoes[10], tamVetPosicoes, vetPosicoesBin[10], tamVetBin;

    for(int i=0; i<10; i++){
        vet[i] = 3;
    }






    tamVetBin = buscaBinaria(vet, tamVet, 3, vetPosicoesBin);

    for(int i=0;i<tamVetBin;i++){
        printf("%d\n", vetPosicoesBin[i]);
    }

    return 0;
}

