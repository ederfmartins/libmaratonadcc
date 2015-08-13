#include <stdio.h>
using namespace std;
#define MAX_VERTICES 150

int p;
int grafo[MAX_VERTICES][MAX_VERTICES];
int cor[MAX_VERTICES];

int numAlcancaveis[MAX_VERTICES];

void dfs(int s)
{
	cor[s] = 1;
	
	int maiorCaminho = 0;
	for (int i = 0; i < p; i++)
	{
		if (grafo[s][i] == 1)
		{
			//printf("%d->%d\n", s, i);
			if (cor[i] == 0) dfs(i);
			if (numAlcancaveis[i] > maiorCaminho) maiorCaminho = numAlcancaveis[i];
		}
	}

	cor[s] = 2;
	numAlcancaveis[s] = maiorCaminho + 1;
	//printf("n[%d]=%d\n", s, numAlcancaveis[s]);
	//return maiorCaminho + 1;
}

int main()
{
	int l, I, o, d;
	int teste = 0;
	int alt[150];
	
	while (1)
	{
		scanf("%d %d %d", &p, &l, &I);
		if (p == 0 && l == 0 && I == 0) break;
		
		for (int i = 0; i < p; i++)
		{
			scanf("%d", &alt[i]);
			numAlcancaveis[i] = 0;
			cor[i] = 0;
			for (int j = 0; j < p; j++)
				grafo[i][j] = 0;
		}
		
		for (int i = 0; i < l; i++) {
			scanf("%d %d", &o, &d);
			if (alt[o-1] > alt[d-1]) grafo[o-1][d-1] = 1;
		}

		dfs(I-1);
		printf("Teste %d\n%d\n\n", ++teste, numAlcancaveis[I-1] -1 );
	}
	return 0;
}

