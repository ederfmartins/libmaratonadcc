#include <stdio.h>
using namespace std;

int balas[1010];

int main()
{
	int n, m, tipo, min = 1<<30;
	
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i <= m; i++) balas[i] = 0;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &tipo);
		balas[tipo]++;
	}
	
	for (int i = 1; i <= m; i++)
		if (balas[i] < min)
			min = balas[i];
	
	printf("%d\n", min);
	
	return 0;
}

