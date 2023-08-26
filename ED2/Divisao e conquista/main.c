#include <stdio.h>
#include <stdlib.h>



int soma(int n, int size){

    if(n== size){
        return 0;


    }else {
        return  n +soma(n-1, size);

    }

}








int main()
{
    int n = 7, s1 = 0, s2 = 0;
    s1 = soma(n/2, 0);
    s2 = soma(n, n/2);
    printf("%d", s1+s2);

    return 0;
}
