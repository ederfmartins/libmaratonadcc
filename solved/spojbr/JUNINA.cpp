#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <inttypes.h>
#include <ctype.h>

#include <algorithm>
#include <utility>
#include <iostream>

#include <map>
#include <set>
#include <vector>
#include <sstream>

/** 1353. Festa Junina - Clique maxima em grafos nao direcionados */

using namespace std;

#define abs(a) ((a) > 0 ? (a) : -(a))
#define MAX 20

char grafo[MAX][MAX];
int tam;
char pass[MAX];

bool canInclude(int n)
{
	for (int i = 0; i < tam; i++)
	{
		if (pass[i] && grafo[i][n] == 1)
		{
			return false;
		}
	}

	return true;
}

int clique(int n)
{
	int max = 0;

	if (n >= tam) return 0;

	max = clique(n + 1);

	if (canInclude(n))
	{
		pass[n] = 1;
		int max1 = 1 + clique(n + 1);
		pass[n] = 0;
		max = max1 > max ? max1 : max;
	}

	return max;
}


int main()
{
	int n, teste = 1;

	while (cin >> n)
	{
		if (n == 0) break;
		tam = n;

		for (int i = 0; i < n; i++)
		{
			int t;
			memset(grafo[i], 0, n);

			while (cin >> t)
			{
				if (t == 0) break;
				grafo[i][t-1] = 1;
				grafo[t-1][i] = 1;
			}
		}

		cout << "Teste " << teste++ << endl;
		cout << clique(0) << endl;
		cout << endl;
	}
	return 0;
}

