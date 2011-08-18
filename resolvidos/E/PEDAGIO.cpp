#include <stdio.h>
#include <queue>
using namespace std;
#define MAX_VERTICES 50
#define INF 100000000

int grafo[MAX_VERTICES][MAX_VERTICES];
int dist[MAX_VERTICES];

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
		for (int i = 0; i < n; i++)
		{
			if (grafo[u][i] == 1 && dist[u] + 1 <= dist[i])
			{
				dist[i] = dist[u] + 1;
				heap.push(make_pair(dist[i], i));
			}
		}
	}
}

int main()
{
	int c, e, l, p, o, d;
	int teste = 0;
	int aeroporto[101];
	
	while (1)
	{
		scanf("%d %d %d %d", &c, &e, &l, &p);
		if (c == 0 && e == 0 && l == 0 && p == 0) break;
		
		for (int i = 0; i < c; i++)
			for (int j = 0; j < c; j++)
				grafo[i][j] = 0;
		
		for (int i = 0; i < e; i++) {
			scanf("%d %d", &o, &d);
			grafo[o-1][d-1] = 1;
			grafo[d-1][o-1] = 1;
		}
		
		dijkstra(c, l-1);
		
		printf("Teste %d\n", ++teste);
		bool primeiro = true;
		for (int i = 0; i < c; i++)
		{
			//printf("d[%d]=%d ", i, dist[i]);
			if (i != l-1 && dist[i] <= p)
			{
				if (primeiro) printf("%d", i+1);
				else printf(" %d", i+1);
				primeiro = false;
			}
		}
		printf("\n\n");
	}
	return 0;
}

