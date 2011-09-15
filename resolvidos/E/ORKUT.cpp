#include <iostream>
#include <map>
#include <string>
#include <string.h>
using namespace std;

#define UNVISITED -1
#define SIZE 30
#define BRANCO 0
#define CINZA 1
#define PRETO 2

string nomes[SIZE];
map<string, int> invnomes;
int n;
int grafo[SIZE][SIZE];
int pass[SIZE];
int prof[SIZE];
int sorted[SIZE];
int nordem;

bool dfs(int v)
{
	pass[v] = CINZA;

	for (int i = 0; i < n; i++)
	{
		if (grafo[v][i])
		{
			if (pass[i] == CINZA) return false;
			if (pass[i] == BRANCO && !dfs(i)) return false;
		}
	}

	pass[v] = PRETO;
	return true;
}

bool aciclico()
{
	memset(pass, BRANCO, n*sizeof(int));

	for (int i = 0; i < n; i++)
	{
		if (pass[i] == BRANCO)
		{
			if (!dfs(i)) return false;
		}
	}

	return true;
}

void dfsTopsort(int no)
{
	for (int viz = 0; viz < n; viz++)
	{
		if (grafo[no][viz])
		{
			if (prof[viz] == UNVISITED)
			{
				prof[viz] = prof[no] + 1;
				dfsTopsort(viz);
			}
		}
	}

	sorted[nordem--] = no;
}

void topSort(int nvt)
{
	memset(prof, UNVISITED, nvt*sizeof(int));
	nordem = nvt - 1;

	for (int i = 0; i < nvt; i++)
	{
		if (prof[i] == UNVISITED)
		{
			prof[i] = 0;
			dfsTopsort(i);
		}
	}
}

int main()
{
	int m, t = 0;
	string a, b;
	
	while (cin >>n)
	{
		if (n == 0) break;
		for (int i = 0; i < n; i++)
		{
			cin >> nomes[i];
			invnomes[nomes[i]] = i;
			
			memset(grafo[i], 0, sizeof(int)*n);
		}
		
		for (int i = 0; i < n; i++)
		{
			cin >> a >> m;
			for (int j = 0; j < m; j++)
			{
				cin >> b;
				//grafo[invnomes[a]][invnomes[b]] = 1;
				grafo[invnomes[b]][invnomes[a]] = 1;
			}
		}
		
		cout << "Teste " << ++t << endl;
		if (!aciclico())
		{
			cout << "impossivel" << endl;
		}
		else 
		{
			topSort(n);
		
			for (int i = 0; i < n; i++)
			{
				cout << nomes[sorted[i]] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}

