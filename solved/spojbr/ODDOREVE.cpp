#include <stdio.h>
using namespace std;

#define min(a, b) ((a) < (b)? (a) : (b))

void computa(int* par, int* impar, int n, int k)
{
	int tmp;
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		if (tmp %2 == 0) par[k]++;
		else impar[k]++;
	}
}

int main()
{
	int n;
	int impar[2];
	int par[2];
	
	while (1)
	{
		scanf("%d", &n);
		if (n == 0) break;
		
		impar[0] = impar[1] = par[0] = par[1] = 0;
		
		computa(par, impar, n, 0);
		computa(par, impar, n, 1);
		
		int maxSomasImpares = min(par[0], impar[1]) + min(par[1], impar[0]);
		printf("%d\n", n - maxSomasImpares);
	}
	
	return 0;
}
