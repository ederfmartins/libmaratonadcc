#include <stdio.h>

/** 1821. O Bolo de Apostas - 1D max sum programacao dinamica neles*/

using namespace std;

int main()
{
	int n;

	while (1)
	{
		scanf("%i", &n);

		int sum = 1<<31, aposta;
		int partialSum = 0;

		if (n == 0) break;

		for (int i = 0; i < n; i++)
		{
			scanf("%i", &aposta);

			partialSum += aposta;

			if (partialSum < 0) partialSum = 0;
			if (partialSum > sum) sum = partialSum;
		}

		if (sum > 0) printf("The maximum winning streak is %i.\n", sum);
		else printf("Losing streak.\n");
	}
	return 0;
}
