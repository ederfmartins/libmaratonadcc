#include <stdio.h>
#include <map>
using namespace std;

int c(int n, int k)
{
	int ret = 1;
	
	if (k > n/2) k = n - k;
	
	for (int i = n; i >= n-k+1; i--) ret *= i;
	
	return ret;
}

int main()
{
	int n, x;
	int numeros[30];
	for (int i = 0; i < 30; i++) numeros[i] = 0;
	
	for (int i = 0; i < 15; i++) {
		scanf("%d", &n);
		numeros[n] = 1;
	}
	
	int aposta = 1;
	
	while (scanf("%d", &n) == 1)
	{
		int acertos = 0;
		
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			if (numeros[x] == 1) acertos++;
		}
		
		printf("Aposta %d\n", aposta++);
		
		if (acertos < 11) printf("nenhum premio aqui\n");
		else {
			int erros = n - acertos;
			int numBilhetes[20];
			
			//printf("%d - %d\n", acertos, erros);
			for (int i = 11; i <= 15; i++)
			{
				if (acertos >= i && erros >= 15 -i) numBilhetes[i] = c(acertos, i) * c(erros, 15-i);
				else numBilhetes[i] = 0;
				
				printf("c(%d, %d) * c(%d, %d) = %d * %d = %d\n", acertos, i, erros, 15-i, c(acertos, i), c(erros, 15-i), numBilhetes[i]);
			}
			
			for (int i = 11; i <= 15; i++) {
				int soma = 0;
				
				//for (int j = i; j <= 15; j++) soma += numBilhetes[j] * c(j, i);
				//if (numBilhetes[i] > 0) printf("%d: %d\n", i, soma);
				if (numBilhetes[i] > 0) printf("%d: %d\n", i, numBilhetes[i]);
			}
		}
		
		printf("\n");
	}
	
	return 0;
}

