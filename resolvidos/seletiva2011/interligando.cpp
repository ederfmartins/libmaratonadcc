#include <stdio.h>
#include <math.h>
#include <utility>
#include <limits.h>

using namespace std;
#define MAX_NODES 1000

int n;
double dquadrado;
double maxDist;
double X[MAX_NODES];
double Y[MAX_NODES];
bool pass[MAX_NODES];
double grafo[MAX_NODES][MAX_NODES];

const double EPS = 1e-4;
inline int cmp (double x, double y = 0, double tol = EPS)
{
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

void dsf(int no)
{
	pass[no] = true;
	
	for (int i = 0; i < n; i++)
	{
		if (cmp(grafo[no][i], dquadrado) <= 0 && !pass[i])
			dsf(i);
	}
}

void binarySearch()
{
	double l = 0.0, u = maxDist;
	
	while (cmp(l, u) != 0)
	{
		dquadrado = l + (u-l)/2.0;
		
		//if (n == 6) printf("DEBUG antes: %lf %lf %lf %lf\n", sqrt(dant), sqrt(dquadrado), sqrt(l), sqrt(u));
		
		for (int i = 0; i < n; i++) pass[i] = false;
		dsf(0);
		bool conectado = true;
		
		for (int i = 0; i < n; i++) {
			if (!pass[i]) {
				conectado = false;
				break;
			}
		}
		
		if (conectado) u = dquadrado;
		else l = dquadrado;
		
		//if (n == 6) printf("DEBUG: %d %lf %lf %lf %lf\n", conectado, sqrt(dant), sqrt(dquadrado), sqrt(l), sqrt(u));
	}
}

int main()
{
	while (scanf("%d", &n) == 1)
	{
		if (n == 0) break;
		maxDist = 0.0;
		
		for (int i = 0; i < n; i++) {
			scanf("%lf %lf", &X[i], &Y[i]);
			grafo[i][i] = 0.0;
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++)
			{
				double dx = X[j] - X[i];
				double dy = Y[j] - Y[i];
				//grafo[i][j] = sqrt(dx*dx + dy*dy);
				grafo[i][j] = dx*dx + dy*dy;
				grafo[j][i] = grafo[i][j];
				
				if (cmp(maxDist, grafo[i][j]) == -1) maxDist = grafo[i][j];
			}
		}
		
		binarySearch();
		printf("%.4f\n", sqrt(dquadrado));
		//printf("%.4f\n", dquadrado);
	}
	
	return 0;
}

