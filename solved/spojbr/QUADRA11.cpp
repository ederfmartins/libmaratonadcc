#include <stdio.h>
#include <stdlib.h>
#include<set>

using namespace std;

#define SIZE 1000

int quadrado[SIZE][SIZE];

void imprime(int n)
{
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			printf("%d ", quadrado[x][y]);
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	int n, S, cnt = 1;
	scanf("%d %d", &n, &S);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			quadrado[i][j] = cnt++;
		}
	}
	
	cnt = 0;
	for (int i = 0; i < n; i++) cnt += quadrado[i][i];
	
	if (S < cnt)
	{
		for (int i = 0; i < n; i++) quadrado[0][i] -= cnt - S;
	}
	else if (S > cnt)
	{
		for (int i = 0; i < n; i++) quadrado[0][i] += S - cnt;
	}
	
	
	imprime(n);
	return 0;
}
