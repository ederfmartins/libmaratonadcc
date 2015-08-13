#include <stdio.h>

using namespace std;

int tv[1000][1000];
int tv1[1000][1000];

int main()
{
	int n, m, x, y, xTot, yTot, teste = 1;
	
	while (1) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;
		
		xTot = 0; yTot = 0;
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &tv[i][j]);
		
		while (1) {
			scanf("%d %d", &x, &y);
			if (x == 0 && y == 0) break;
			xTot += x;
			yTot += y;
		}
		
		xTot %= m;
		yTot %= n;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int a = (i - yTot + n)%n;
				int b = (j + xTot + m)%m;
				//printf("(%d %d) ", a, b);
				tv1[a][b] = tv[i][j];
			}
			//printf("\n");
		}
		
		printf("Teste %d\n", teste++);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("%d", tv1[i][j]);
				
				if (j != m-1) printf(" ");
			}
			
			printf("\n");
		}
		
		printf("\n");
	}
	return 0;
}

