#include <stdio.h>
#include <list>
using namespace std;

int main()
{
	int P, R, p, n, ordem, acao, teste = 1;
	
	while (1)
	{
		scanf("%d %d", &P, &R);
		if (P == 0 && R == 0) break;
		
		list<int> participantes;
		
		for (int i = 0; i < P; i++) {
			scanf("%d", &p);
			participantes.push_back(p);
		}
		
		for (int i = 0; i < R; i++)
		{
			scanf("%d %d", &n, &ordem);
			list<int>::iterator elemento = participantes.begin();
			for (int k = 0; k < n; k++) {
				scanf("%d", &acao);
				if (acao == ordem) elemento++;
				else {
					list<int>::iterator toRemove = elemento++;
					//elemento = elemento+1;
					participantes.erase(toRemove);
				}
			}
		}
		
		printf("Teste %d\n%d\n\n", teste++, *participantes.begin());
	}
	
	return 0;
}

