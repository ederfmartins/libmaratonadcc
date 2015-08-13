#include <stdio.h>

using namespace std;

int main()
{
	int n, dMax, ant, atual;
	bool ok = true;
	scanf("%d %d %d", &n, &dMax, &ant);
	
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &atual);
		
		if (atual - ant > dMax) {
			ok = false;
			break;
		}
		ant = atual;
	}
	
	if (ok && 42195 - ant <= dMax) printf("S\n");
	else printf("N\n");
	
	return 0;
}

