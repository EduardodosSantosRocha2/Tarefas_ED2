#include <stdio.h>
#include <stdlib.h>


int fatorial(int n){
    if(n > 1){
        return fatorial(n-1) * n ;
    }
    return 1;
}







int main()
{
   printf("%d",fatorial(4));
    return 0;
}
