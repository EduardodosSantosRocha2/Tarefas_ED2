#include <stdio.h>
#include <stdlib.h>



int fibo(int n){
    if(n == 1){
        return 1;
    }
    if(n == 0){
        return 0;
    }
   return fibo(n-1) + fibo(n-2);

}



int main()
{
    for(int i=0; i<5; i++){
        printf("%d\n", fibo(i));
    }

    return 0;
}
