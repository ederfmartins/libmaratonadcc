#include <stdio.h>
using namespace std;

#define MAX_AEROPORTOS 100

int main()
{
	int a, v, x, y;
	int teste = 0;
	//os indices no problema vão de 1 a n...
	int trafego[MAX_AEROPORTOS+1];
	
	while (1)
	{
		scanf("%d %d", &a, &v);
		if (a == 0 && v == 0) break;
		
		for (int i = 1; i <= a; i++) trafego[i] = 0;
		
		//observe que eu não preciso caucular grau_entrada e grau_saida, mas apenas a soma deles.
		for (int i = 0; i < v; i++) {
			scanf("%d %d", &x, &y);
			trafego[x]++;
			trafego[y]++;
		}
		
		int max = 0;
		for (int i = 1; i <= a; i++)
		{
			if (max < trafego[i]) 
				max = trafego[i];
		}
		
		//imprimindo os aeroportos. Observe que pode haver mais de um aeroporto com o maior tráfego.
		printf("Teste %d\n", ++teste);
	
		bool primeiro = true;
		for (int i = 1; i <= a; i++)
		{
			if (max == trafego[i])
			{
				if (primeiro) printf("%d", i);
				else printf(" %d", i);
				primeiro = false;
			}
		}
		
		printf("\n\n");
	}
	return 0;
}
