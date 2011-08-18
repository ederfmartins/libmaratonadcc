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

/** 10004 - Bicoloring */

using namespace std;

#define TAM 200

bool matrix[TAM][TAM];
int pass[TAM];
int n;

bool dfs(int v, int color = 1)
{
	pass[v] = color;
	int thisColor = color;
	bool ret = true;

	color = color == 1 ? 2 : 1;

	for (int i = 0; i < n; i++)
	{
		if (matrix[v][i])
		{
			if (!pass[i]) ret = dfs(i, color);
			else if (pass[i] == thisColor) return false;

			if (!ret) return false;
		}
	}

	return ret;
} 

int main()
{
	int l, a, b;

	while (cin >> n)
	{
		if (n == 0) break;
		cin >> l;

		for (int i = 0; i < n; i++) memset(matrix[i], 0, n*sizeof(int));
		memset(pass, 0, n*sizeof(int));

		for (int i = 0; i < l; i++)
		{
			cin >> a >> b;
			matrix[a][b] = matrix[b][a] = true;
		}

		bool isBicoloring = dfs(0);

		if (isBicoloring) cout << "BICOLORABLE." << endl;
		else cout << "NOT BICOLORABLE." << endl;		
	}
	return 0;
}

