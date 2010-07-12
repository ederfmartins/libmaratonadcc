#include <iostream>
#include <vector>
#include <map>
#include <queue>

/** 2840. Engarrafamento - caminho minimo dijkstra*/

using namespace std;

#define MAX_VERTICES 110
#define INF (-((1<<31)+1))

typedef vector<map<int, int> > AdjList;
typedef AdjList Grafo;

int dist[MAX_VERTICES];
//int prev[MAX_VERTICES]; // para recuperar o caminho usando um dijoint forest set


#define IDX(i) (i-1)

void dijkstra(Grafo& grafo, int source)
{
	for (int i = 0; i < grafo.size(); i++)
	{
		dist[i] = INF;
//		prev[i] = -1;
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
				//prev[(*i).first] = u;
			}
		}
	}
}

/*
int main()
{
    int n, m;

    while(cin >> n >> m)
	{
        if(n==0 && m==0) return 0;

        Grafo vias;
		vias.resize(MAX_VERTICES);

        for (int cnt = 0; cnt < m; cnt++)
		{
            int i,j,t;
            cin >> i >> j >> t;
            vias[i-1][j-1] = t;
        }

		int s, d;
		cin >> s >> d;

        dijkstra(vias, s-1);
        if (dist[d-1] != INF) cout << dist[d-1] << endl;
		else cout << "-1" << endl;
    }
    return 0;
}
*/

int main() {
	int n, m;
    while(scanf("%d %d", &n, &m)==2) {
        if(n==0 && m==0) {
            return 0;
        }
        Grafo locais;
		locais.resize(MAX_VERTICES);

        for(int rua=0; rua < m; rua++) { // Le arestas
            int i, j, t;
            scanf("%d %d %d", &i, &j, &t);
            locais[IDX(i)][IDX(j)] = t;
        }

        int orig, dest;

        scanf("%d %d", &orig, &dest);
        dijkstra(locais, IDX(orig));

        if(dist[IDX(dest)] != INF) {
            printf("%d\n", dist[IDX(dest)]);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}


