#include <queue>

typedef vector<map<int, int> > AdjList;
typedef AdjList Grafo;

int dist[MAX_VERTICES];
int prev[MAX_VERTICES]; // para recuperar o caminho usando um dijoint forest set

void dijkstra(Grafo& grafo, int source)
{
	for (int i = 0; i < grafo.size(); i++)
	{
		dist[i] = INF;
		prev[i] = -1;
	}

	dist[source] = 0;
	priority_queue<pair<int, int> > heap;
	heap.push(make_pair(0, source));

	while (!heap.empty())
	{
		int u = heap.top().second;
		heap.pop();

		// para cada vizinho de u
		for (map<int,int>::iterator i = grafo[u].begin(); i != grafo[u].end(); i++)
		{
			int totalDist = dist[u] + (*i).second;
			if (totalDist <= dist[(*i).first])
			{
				dist[(*i).first] = totalDist;
				heap.push(make_pair(totalDist, (*i).first));
				prev[(*i).first] = u;
			}
		}
	}
}
