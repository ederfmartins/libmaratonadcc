#include <iostream>
using namespace std;
#define TAM 300
int n;
int grafo[TAM][TAM];
int visitado[TAM];
int contado[TAM];
int pred[TAM];

void dfs(int no)
{
	visitado[no] = 1;
	
	for (int i = 0; i < n; i++)
		if (!visitado[i] && grafo[no][i] != 0)
		{
			pred[i] = no;
			dfs(i);
		}
}

int conta(int no)
{
	int cnt = 0;
	int noA = no;
	
	while (1)
	{
		if (noA == -1) break;
		if (contado[noA]) break;
		contado[noA] = 1;
		cnt += 2;
		noA = pred[noA];
	}
	
	return cnt;
}

int main()
{
	int c, v, t = 0;
	int x, y;
	
	while (cin >> c >> v)
	{
		if (c == 0 && v == 0) break;
		n = c;
		
		for (int i = 0; i < c; i++)
		{
			visitado[i] = 0;
			pred[i] = -1;
			contado[i] = 0;
			for (int j = 0; j < c; j++)
				grafo[i][j] = 0;
		}
		
		for (int i = 0; i < c -1; i++)
		{
			cin >> x >> y;
			grafo[x-1][y-1] = 1;
			grafo[y-1][x-1] = 1;
		}

		dfs(0);
		
		int cnt = 0;
		for (int i = 0; i < v; i++)
		{
			cin >> x;
			cnt += conta(x-1);
		}
		
		cout << "Teste " << ++t << endl;
		cout << cnt-2 << endl;
		cout << endl;
	}
	return 0;
}

