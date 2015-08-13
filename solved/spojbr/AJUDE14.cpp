#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int n, tmp;
    int soma, somaD;

	scanf("%d\n", &n);
	soma = 0;
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d\n", &tmp);
        soma += tmp;
	}
	
	scanf("%d", &somaD);
	
	if (soma == somaD) printf("Acertou\n");
	else printf("Errou\n");
	
	return 0;
}

