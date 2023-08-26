#include <stdio.h>
#include <stdlib.h>

int soma(int n, int s1, int s2){

    if(n == s1){
        return 0;
    }
    else if(n!= s1){
        return n + soma(n-1, s1, s2);
    }
    else if



}








int main()
{
    int n = 7, s1 = 0, s2 = n/2;
    printf("%d", soma(n, s1, s2));

    return 0;
}
