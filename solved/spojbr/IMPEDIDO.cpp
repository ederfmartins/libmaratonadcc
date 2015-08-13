#include <stdio.h>
using namespace std;

#define MAX_DIST 10000

int main()
{
	int jogadores[11];
	int a, d;
	
	while (1)
	{
		scanf("%d %d", &a, &d);
		if (a == 0 && d == 0) break;
		
		int ultimo = MAX_DIST + 1;
		int penultimo = MAX_DIST + 1;
		for (int i = 0; i < a; i++) scanf("%d", &jogadores[i]);
		
		for (int i = 0; i < d; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			if (tmp < penultimo) {
				penultimo = tmp;
			}
			
			if (penultimo < ultimo) {
				tmp = penultimo;
				penultimo = ultimo;
				ultimo = tmp;
			}
		}
		
		bool impedido = false;
		
		for (int i = 0; i < a; i++) {
			if (jogadores[i] < penultimo) {
				impedido = true;
				break;
			}
		}
		
		printf("%c\n", (impedido? 'Y' : 'N'));
	}
	
	return 0;
}

