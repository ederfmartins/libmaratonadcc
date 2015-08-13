#include <stdio.h>
using namespace std;

#define VALOR_MAXIMO 50001
#define MAX_MOEDAS 101
int n;
int valores[MAX_MOEDAS];
int numMoedas[VALOR_MAXIMO];

int minMoedasFocaBruta(int valor, int moeda)
{
	if (valor < 0) return -1;
	if (valor == 0) return 0;
	else if (moeda >= n) return -1;
	
	int min = -1;
	int i = 0;
	
	while (i*valores[moeda] <= valor)
	{
		int tmp = minMoedasFocaBruta(valor - i*valores[moeda], moeda + 1);
		if (tmp != -1 && (tmp+i < min || min == -1)) {
			min = tmp + i;
		}
		
		i++;
	}
	
	return min;
}

int minMoedasDP(int valor, int moedas)
{
	int min = valores[0];
	for (int i = 0; i < moedas; i++) {
		if (min > valores[i]) min = valores[i];
	}
	
	numMoedas[0] = 0;
	//já que o menor valor de moeda seria 1 tostão então eu preciso de no máximo "valor" moedas para formar o valor desejado.
	//assim posso usar valor+1 como flag para impossivel.
	for (int i = 1; i < min; i++) numMoedas[i] = valor+1;
	
	for (int i = min; i <= valor; i++)
	{
		int min = valor+1;
		for (int m = 0; m < moedas; m++)
		{
			if (i - valores[m] >= 0) {
				int tmp = 1 + numMoedas[i-valores[m]];
				if (tmp < min) min = tmp;
			}
		}
		
		numMoedas[i] = min;
	}
		
	
	return numMoedas[valor];
}

int main()
{
	int m;
	
	while (1)
	{
		scanf("%d", &m);
		if (m == 0) break;
		
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &valores[i]);
		
		int cnt = minMoedasDP(m, n);
		if (cnt > m) printf("Impossivel\n");
		else printf("%d\n", cnt);
	}
	
	return 0;
}

