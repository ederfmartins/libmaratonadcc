#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

bool topologicalSort(vector< vector< int > > &g, vector< int > &r)
{
	vector< int > deg(g.size());
	for (vector< vector< int > >::iterator node = g.begin(); node != g.end(); node++){
		for (vector<int>::iterator ngb = (*node).begin(); ngb != (*node).end(); ngb++){
			deg[*ngb]++;
		}
	}

	priority_queue< int, vector< int >, greater< int > > q;
	for (int i = 0; i < g.size(); i++)
		if(0 == deg[i]) q.push(i);

	while(not q.empty()){
		int node = q.top();
		q.pop();
		r.push_back(node);
		for (vector<int>::iterator ngb = g[node].begin(); ngb != g[node].end(); ngb++){
			if(--deg[*ngb] == 0) q.push(*ngb);
		}
	}

	return r.size() == g.size();
}

int main()
{
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	
	vector< vector< int > > grafo(n);
	vector<int> sorted;
	
	
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		grafo[a].push_back(b);
	}
	
	if (topologicalSort(grafo, sorted)) {
		for (int i = 0; i < sorted.size(); i++) printf("%d\n", sorted[i]);
	}
	else printf("*\n");
	
	return 0;
}

