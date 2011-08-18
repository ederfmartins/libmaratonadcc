#include <stdio.h>

using namespace std;

int main()
{
	int n, cnt = 1;
	
	while (1)
	{
		scanf("%d", &n);
		if (n == 0) break;

		bool maioZero = false;
		int maxSum = -1;
		int inicio, fim;
		
		int atualSum = 0;
		int ainicio = 1;
		int afim = 1;

		for (int i = 1; i <= n; i++)
		{
			int afavor, contra;
			scanf("%d %d", &afavor, &contra);
			int saldo = afavor - contra;
			atualSum += saldo;
			
			//printf("bla %d %d %d %d", atualSum, maxSum, ainicio, afim);

			if (atualSum >= 0)
			{
				afim = i;
				if (atualSum > maxSum || (atualSum == maxSum && afim - ainicio > fim - inicio))
				{
					maxSum = atualSum;
					inicio = ainicio;
					fim = afim;
				}
			}
			else if (atualSum < 0)
			{
				atualSum = 0;
				ainicio = i + 1;
				afim = i + 1;
			}
			if (saldo > 0) maioZero = true;
		}

		if (maioZero) printf("Teste %d\n%d %d\n\n", cnt++, inicio, fim);
		else printf("Teste %d\nnenhum\n\n", cnt++);
	}
	return 0;
}

