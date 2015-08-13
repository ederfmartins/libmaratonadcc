#include <stdio.h>
using namespace std;

int main()
{
	int n, j, z, J, Z;
	int teste = 0;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0) break;
		
		printf("Teste %d\n", ++teste);
		J = 0; Z = 0;
		
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &j, &z);
			J += j;
			Z += z;
			printf("%d\n", J-Z);
		}
		
		printf("\n");
	}
	return 0;
}
