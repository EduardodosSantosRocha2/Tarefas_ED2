#include <stdio.h>
#include <stdlib.h>






void forcaBruta(char a[], char p[])
{
    int i, cont = 0, j;
    for (i = 0; a[i] != '\0'; i++)
    {
        for (j = 0; p[j] != '\0'; j++)
        {

            if (a[i+j] != p[j]){
                break;
            }

            if (p[j+1] == '\0'){
                 printf("%d ", i);
            }
            cont++;
        }

    }
    printf("\n cont:%d", cont);

}






int main()
{
    char a[] = "hsabdfkasndafeahweijabiufhsjfnaskjefkashfkjnasbkjdfasdhkjasdfnkjsadbfkashdfkjbsdkhfgawuehsdhflkjsheiruhaiusef";
    char p[] = "feahwei";
    forcaBruta(a, p);
    return 0;
}
