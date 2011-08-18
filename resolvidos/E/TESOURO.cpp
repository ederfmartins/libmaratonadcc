#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define abs(x) ((x) > 0 ? (x) : -(x))

// testa se ha alguma soma de elementos do vetor que seja igual a valor
/*
int compare (const void * a, const void * b)
{
  return ( *(int*)b - *(int*)a );
}
bool testa(int s, int valor)
{



	if (s >= n) return false;

	for (int i = s; i < n; i++)
	{
		//printf("s=%d valor=%d t[%d]=%d\n", s, valor, i, tesouro[i]);
		if (tesouro[i] == valor) return true;
		else if (tesouro[i] < valor) {
			if (testa(i + 1, valor - tesouro[i])) return true;
		}
	}

	return false;
}
*/

int n;
int tesouro[101];
/*
bool C[101][10001];
bool subSetSum(int c)
{
	for (int i = 0; i <= n; i++) C[i][0] = true;
	
	for (int b = 1; b <= c; b++)
	{
		C[0][b] = false;
		for (int i = 1; i <= n; i++)
		{
			bool s = C[i-1][b];
			if (s == false && tesouro[i] <= b) s = C[i-1][b - tesouro[i]];
			C[i][b] = s;
		}
	}

	return C[n][c];
}*/

#define MAX_SUM 10000
bool m[MAX_SUM];
bool subSetSum(int M, int c)
{
	for (int i = 0; i <= M; i++) m[i] = false;
	m[0] = true;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = M; j >= tesouro[i]; j--)
		{
			m[j] |= m[j - tesouro[i]];
		}
	}
	
	return m[c];
}


int main()
{
	int x, y, acum, v;
	int teste = 0;
	bool igual;
	
	while (1)
	{
		scanf("%d %d %d", &x, &y, &n);
		if (x == 0 && y == 0 && n == 0) break;
		acum = 0;
		
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &tesouro[i]);
			acum += tesouro[i];
		}
		
		v = acum - abs(x - y);

		if (v == 0) igual = true;
		else if (v % 2 == 0 && n > 1) {
			//qsort (tesouro, n, sizeof(int), compare);
			//igual = subSetSum(v/2);
			igual = subSetSum(acum, v/2);
		}
		else igual = false;

		if (igual) printf("Teste %d\nS\n\n", ++teste);
		else printf("Teste %d\nN\n\n", ++teste);
	}

	return 0;
}

