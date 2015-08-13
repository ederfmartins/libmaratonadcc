#include <stdio.h>
#include <math.h>
#include <map>

using namespace std;

typedef map<int, int> PrimeMap;

void computaExpoente(PrimeMap& M, int& n, int p)
{
	for (; n % p == 0; n /= p) M[p]++;
}

void fatora(int n, PrimeMap& M)
{
	if (n < 0) { fatora(-n, M); return; }
	if (n < 2) return;

	computaExpoente(M, n, 2);
	computaExpoente(M, n, 3);

	int maxP = sqrt(n) + 2;
	for (int p = 5; p < maxP; p += 6)
	{
		computaExpoente(M, n, p);
		computaExpoente(M, n, p+2);
	}
	
	if (n > 1) M[n]++;
}

int main()
{
	int t = 1;
	int n;
	
	while (scanf("%d\n", &n) == 1)
	{
		PrimeMap fatores;
		fatora(n, fatores);
		
		int expMaiorIgual2 = 0;
		int maiorExp = 0;
		
		for (PrimeMap::iterator it = fatores.begin(); it != fatores.end(); it++)
		{
			if (it->second > 1) expMaiorIgual2++;
			
			if (it->second > maiorExp) maiorExp = it->second;
		}
		
		if (fatores.size() >= 4) printf("Instancia %d\nsim\n\n", t);
		else if (fatores.size() == 3 && expMaiorIgual2 > 0) printf("Instancia %d\nsim\n\n", t);
		else if (fatores.size() == 2 && (expMaiorIgual2 > 1 || maiorExp >= 5)) printf("Instancia %d\nsim\n\n", t);
		else if (fatores.size() == 1 && maiorExp >= 8) printf("Instancia %d\nsim\n\n", t);
		else printf("Instancia %d\nnao\n\n", t);
		
		t++;
	}
	
	return 0;
}

