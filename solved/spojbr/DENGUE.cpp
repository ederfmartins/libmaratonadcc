#include <iostream>
#include <queue>
using namespace std;
#define TAM 100
#define INF 100000000
int n;
int grafo[TAM][TAM];
int grau[TAM];
int dist[TAM];

void dijkstra(int source)
{
	for (int i = 0; i < n; i++)
	{
		dist[i] = INF;
	}

	dist[source] = 0;
	priority_queue<pair<int, int> > heap;
	heap.push(make_pair(0, source));

	while (!heap.empty())
	{
		int u = heap.top().second;
		heap.pop();

		// para cada vizinho de u
		//for (map<int,int>::iterator i = grafo[u].begin(); i != grafo[u].end(); i++)
		for (int i = 0; i < grau[u]; i++)
		{
			int v = grafo[u][i];
			int totalDist = dist[u] + 1;
			if (totalDist <= dist[v])
			{
				dist[v] = totalDist;
				heap.push(make_pair(totalDist, v));
			}
		}
	}
}

int main()
{
	int a, b, t = 0;
	while (cin >> n)
	{
		if (n == 0) break;
		
		for (int i = 0; i < n; i++)
			grau[i] = 0;
		
		for (int i = 0; i < n -1; i++)
		{
			cin >> a >> b;
			grafo[a-1][grau[a-1]] = b-1;
			grau[a-1]++;
			
			grafo[b-1][grau[b-1]] = a-1;
			grau[b-1]++;
		}
		
		int vila, menorMaiorCaminho = INF;
		
		for (int i = 0; i < n; i++)
		{
			dijkstra(i);
			int max = 0;
			
			for (int j = 0; j < n; j++)
			{
				//cout << dist[j] << " ";
				if (dist[j] > max)
					max = dist[j];
			}
			//cout << endl;
			
			if (menorMaiorCaminho > max)
			{
				menorMaiorCaminho = max;
				vila = i + 1;
			}
		}
		
		cout << "Teste " << ++t << endl;
		cout << vila << endl;
		cout << endl;
	}
	return 0;
}

