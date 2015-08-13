#include <iostream>
#include <queue>
using namespace std;
#define TAM 100
#define INF 1000000
int grafo[TAM][TAM];

int dist[TAM];

void dijkstra(int n, int source)
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
		for (int v = 0; v < n; v++)
		{
			if (grafo[u][v] != INF)
			{
				int totalDist = dist[u] + grafo[u][v];
				if (totalDist <= dist[v])
				{
					dist[v] = totalDist;
					heap.push(make_pair(totalDist, v));
				}
			}
		}
	}
}

int main()
{
	int n, m, u, v, w;
	int maiorMenorDist = INF;
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			grafo[i][j] = INF;
	
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		if (grafo[u][v] > w) grafo[u][v] = w;
		if (grafo[v][u] > w) grafo[v][u] = w;
	}
	
	for (int i = 0; i < n; i++)
	{
		dijkstra(n, i);
		int maxDist = 0;
		for (int j = 0; j < n; j++)
			if (maxDist < dist[j]) maxDist = dist[j];
			
		if (maxDist < maiorMenorDist) maiorMenorDist = maxDist;
	}

	cout << maiorMenorDist << endl;
	return 0;
}
