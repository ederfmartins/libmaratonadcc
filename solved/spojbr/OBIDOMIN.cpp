#include <stdio.h>
using namespace std;

#define SIZE 10

int degree[SIZE];
int grafo[SIZE][SIZE];
int visitado[SIZE];

void dsf(int no)
{
	visitado[no] = 1;
	
	for (int i = 0; i < degree[no]; i++)
	{
		int v = grafo[no][i];
		if (!visitado[v]) dsf(v);
	}
}

int main()
{
	int n, a, b, t = 0;
	
	while (1)
	{
		scanf("%d", &n);
		if (n == 0) break;
		
		for (int i = 0; i < 7; i++) {
			degree[i] = 0;
			visitado[i] = 0;
		}
		
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &a, &b);
			grafo[a][degree[a]++] = b;
			grafo[b][degree[b]++] = a;
		}
		
		int euleriano = 0;
		int no;
		bool conexo = true;
		
		for (int i = 0; i < 7; i++) {
			if (degree[i]%2 == 1) euleriano++;
			
			//qualquer vertice serve.
			if (degree[i] > 0) no = i;
		}
		
		if (euleriano > 2) printf("Teste %d\nnao\n\n", ++t);
		else {
			dsf(no);
			
			for (int i = 0; i < 7; i++) {
				if (degree[i] > 0 && !visitado[i]) {
					conexo = false;
					break;
				}
			}
			
			if (conexo) printf("Teste %d\nsim\n\n", ++t);
			else printf("Teste %d\nnao\n\n", ++t);
		}
	}
	
	return 0;
}

