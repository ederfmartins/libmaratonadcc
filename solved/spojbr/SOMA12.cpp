#include <stdio.h>
#include <set>

using namespace std;

int main()
{
	int n;
	int soma;
	int numeros[100000];
	set<int> nset;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &numeros[i]);
		nset.insert(numeros[i]);
	}
	scanf("%d", &soma);
	for (int i = 0; i < n; i++)
	{
		if (nset.count(soma - numeros[i]))
		{
			printf("%d %d\n", numeros[i], soma -numeros[i]);
			return 0;
		}
	}
	return 0;
}
