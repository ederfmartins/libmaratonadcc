#include <stdio.h>
#include <math.h>

using namespace std;

const double EPS = 1e-10;
#define _inline(f...) f() __attribute__((always_inline)); f
_inline(int cmp)(double x, double y = 0, double tol = EPS)
{
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int px[1000];
int py[1000];
int n;

/*1364. Cubra os furos geometria ad hoc muito fácil. Existe um erro de arredondamento de ponto flutuante nesse programa se não comparar com cmp não passa.*/
int main()
{
	int t = 0;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0) break;
		
		for (int i = 0; i < n; i++) scanf("%d %d", &px[i], &py[i]);
		
		double menorR = 1000000000;
		for (int i = 0; i < n; i++) {
			double maiorR = 0;
			for (int j = 0; j < n; j++) {
				int dx = px[i] - px[j];
				int dy = py[i] - py[j];
				double dist = sqrt(dx*dx + dy*dy) + 2.5;
				if (dist > maiorR) maiorR = dist;
			}
			if (maiorR < menorR) menorR = maiorR;
		}
		
		menorR *= 2;
		int d = menorR;
		if(cmp(menorR - d) > 0) d++;
		
		printf("Teste %d\n%d\n\n", ++t, d);
	}
	return 0;
}

