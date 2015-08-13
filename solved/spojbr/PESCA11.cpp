#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define SIZE 101

int mar[SIZE][SIZE];

void imprime()
{
	for (int x = 0; x < SIZE; x++)
	{
		for (int y = 0; y < SIZE; y++)
		{
			printf("%d ", mar[x][y]);
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	int n, xi, xf, yi, yf, cnt = 0;
	
	for (int x = 0; x < SIZE; x++)
	{
		for (int y = 0; y < SIZE; y++)
		{
			mar[x][y] = 0;
		}
	}
	
	scanf("%d\n", &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d\n", &xi, &xf, &yi, &yf);
		for (int x = xi; x < xf; x++)
		{
			for (int y = yi; y < yf; y++)
			{
				mar[x][y] = 1;
			}
		}
		//imprime();
	}
	
	for (int x = 0; x < SIZE; x++)
	{
		for (int y = 0; y < SIZE; y++)
		{
			cnt += mar[x][y];
		}
	}
	
	printf("%d\n", cnt);
	return 0;
}
