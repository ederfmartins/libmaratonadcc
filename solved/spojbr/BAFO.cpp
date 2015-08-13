#include <stdio.h>
using namespace std;

int main()
{
	int teste = 1;
	while (1)
	{
		int n, figurinhasAldo, figurinhasBeto, a = 0, b = 0;
		
		scanf("%d", &n);
		if (n == 0) break;
		
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &figurinhasAldo, &figurinhasBeto);
			a+= figurinhasAldo;
			b += figurinhasBeto;
		}
		
		printf("Teste %d\n", teste++);
		if (a > b) printf("Aldo\n");
		else printf("Beto\n");
		printf("\n");
		
	}
	
	return 0;
}
