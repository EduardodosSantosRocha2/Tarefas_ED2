#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int  boyermoorematch(char S[ ], char P[ ])
{
	int n, m, i= 0, j = 0, lastch;
	n = strlen(S);
	m = strlen(P);


	i = m – 1;
	j = m – 1;

	while  (i < n)
		if  (P[j] == S[i])
			if  (j == 0)
				return  i;
			else
			{
				j--;  i--;
			}
		else
		{
			lastch = find(P, S[i]);
			if  (lastch == -1)
				i = i + m;
			else
				i = i + j – lastch;
			j = m – 1;
		}
	return  -1;
}

int  find(char P[ ], char  ch)
{
	int m, i;  m = length(P);
	for  (i = m – 2; i >= 0; i--)
	{
		if  (ch == P[i])
		{
			return  i;
		}
	}
	return  -1;
}

int main()
{
    int retorno;
    char a[] = "hsabdfkasndafeahweijabiufhsjfnaskjefkashfkjnasbkjdfasdhkjasdfnkjsadbfkashdfkjbsdkhfgawuehsdhflkjsheiruhaiusef";
    char p[] = "feahwei";
    forcaBruta(a, p);
    retorno =  boyermoorematch();
    return 0;
}
