#include <stdio.h>
using namespace std;

int main()
{
	int n, j, z, J, Z;
	int teste = 0;
	
	int b = 1;
	
	int valor[16];
	for (int i = 0; i < 16; i++)
	{
		//f(i) = (2^i + 1)^2 eh so verificar no papel e observar que a cada divisao cada quadrado eh dividido em 4 e o corte divide em n+1 pedacos.
		int v = b + 1;
		valor[i] = v*v;
		//printf("bla %d %d %d %d\n", i, b, v, valor[i]);
		b *= 2;
	}
	
	while (1)
	{
		scanf("%d", &n);
		if (n == -1) break;
		
		printf("Teste %d\n%d\n\n", ++teste, valor[n]);
	}
	return 0;
}

