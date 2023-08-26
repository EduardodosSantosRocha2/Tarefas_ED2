#include <stdio.h>
#include <stdlib.h>



int buscabinaria(int vet[], int posini, int posfim, int num){
    int meio = (posini + posfim)/2;
    if(vet[meio] == num){
        return meio;
    }

    if(vet[meio]< num)
        return buscabinaria(vet,meio+1,posfim, num);

    else if(vet[meio]> num)
        return buscabinaria(vet,posini,meio-1,num);



}






int main()

{
    int n = 4;
    int  posini = 0;
    int posfim = n-1;
    int vet[4] = {1,2,3,4};
    printf("%d",buscabinaria(vet, posini, posfim, 3));
    return 0;
}
