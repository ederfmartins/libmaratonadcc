#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define MAX 201

typedef struct {
int x, y;
} Point;

typedef Point Polygon[MAX];


void sort(Polygon p, int n)
{
	int i, j, min = 0;
	Point aux;
	for (i=1; i < n; i++)
	{
		if (p[i].x < p[min].x || (p[i].x == p[min].x && p[i].y > p[min].y))
			min = i;
	}
	
	if (min != 0) aux = p[0], p[0] = p[min], p[min] = aux;
	
	xmin = p[0].x, ymax = p[0].y;
	qsort(&p[1],n−1,sizeof(Point),(void*)cmp_sort);
	
	for (i=n−1; i > 0 && prod_vet(p[i].x−p[0].x,p[i].y−p[0].y,p[i−1].x−p[0].x, p[i−1].y−p[0].y) == 0; i−−);
	for (j=0; j < (n−i)/2; j++) aux = p[i+j], p[i+j] = p[n−j−1], p[n−j−1] = aux;
}


int convex_hull(Polygon p, int n, Polygon hull)
{
	int qtdepontos = 2, i;
	double x1, y1, x2, y2;
	sort(p, n);
	hull[0] = p[0], hull[1] = p[1];
	for (i=2; i <= n; i++)
	{
		do {
			x1 = p[i%n].x − hull[qtdepontos−1].x;
			y1 = p[i%n].y − hull[qtdepontos−1].y;
			x2 = hull[qtdepontos−2].x − hull[qtdepontos−1].x;
			y2 = hull[qtdepontos−2].y − hull[qtdepontos−1].y;
			if (prod_vet(x1,y1,x2,y2) <= 0 && i != n) qtdepontos−−;
			else break;
		}
		while (qtdepontos > 1);
		if (i != n) hull[qtdepontos++] = p[i];
	}

	return qtdepontos;
}

int main()
{
	int n, a, b;
	Polygon p, hull;
	
	while (cin >> n)
	{
		if (n == 0) break;
		
		
		for (int i = 1; i <= n; i++)
		{
			
		}
	}
	return 0;
}


