#include <stdio.h>
#include <stdlib.h>

using namespace std;

int conta(int n)
{
	int cnt = 1;

	while( 1 )
	{	
		if(n == 1) return cnt;
		else if( n % 2 ) { n = 3 * n + 1; cnt++;}
		else { n /= 2; cnt++; }
	}
	return -1;
}

int main()
{
	int i, j, maiorCiclo, aux;
	
	while( !feof(stdin))
	{
		scanf("%i %i\n", &i, &j);
		if ( i < j)
		{
			maiorCiclo = conta(i);
			for (int idx = i + 1; idx <= j; idx++)
			{
				aux = conta(idx);
				if( aux > maiorCiclo ) maiorCiclo = aux;
			}
		}
		else 
		{
			maiorCiclo = conta(j);
			for (int idx = j + 1; idx <= i; idx++)
			{
				aux = conta(idx);
				if( aux > maiorCiclo ) maiorCiclo = aux;
			}
		}
		printf("%i %i %i\n", i, j, maiorCiclo);
	}
}

