#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
using namespace std;

#define SIZE 1000001

int N;
vector<int> grafo[SIZE];
int dist[SIZE];

void dsf(int no, int d)
{
	dist[no] = d;
	
	for (int i = 0; i < grafo[no].size(); i++)
	{
		if (dist[grafo[no][i]] == -1)
		{
			dsf(grafo[no][i], d+1);
		}
	}
}

int bfs(int no)
{
	int d;
	dist[no] = 0;
	queue<pair<int, int> > fila;
	for (int i = 0; i < grafo[no].size(); i++)
		fila.push(make_pair<int, int>(grafo[no][i], 1));
	
	while (fila.size() > 0)
	{
		no = fila.front().first;
		d = fila.front().second;
		fila.pop();
		
		if (dist[no] != -1) continue;
		dist[no] = d;
		
		for (int i = 0; i < grafo[no].size(); i++) {
			if (dist[grafo[no][i]] == -1)
				fila.push(make_pair<int, int>(grafo[no][i], d+1));
		}
	}
	
	d = 0;
	for (int i = 0; i < N; i++) {
		if (dist[i] > d)
			d = dist[i];
	}
	
	return d;
}

int main()
{
	int a, b;
	scanf("%d", &N);
	
	for (int i = 0; i < N-1; i++)
	{
		dist[i] = -1;
		scanf("%d %d", &a, &b);
		a--; b--;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}
	
	
	dist[N-1] = -1;
	
	//dsf implementada sem recurção pq com da estouro de pilha.
	//dsf(a, 0);
	queue<pair<int, int> > pilha;
	pilha.push(make_pair(a, 0));
	
	while(!pilha.empty()){
		int no = pilha.front().first;
		int d = pilha.front().second;
		pilha.pop();
		
		if(dist[no] != -1)continue;
		
		dist[no] = d;
		
		for(int i = 0; i < grafo[no].size(); i++){
			if(dist[grafo[no][i]] == -1)
				pilha.push(make_pair(grafo[no][i], d+1));
		}
	}
	
	
	int maxD = 0;
	int no = a;
	
	for (int i = 0; i < N; i++)
	{
		if (dist[i] > maxD) {
			maxD = dist[i];
			no = i;
		}
		
		//printf("->dist[%d]=%d\n", i, dist[i]);
		
		dist[i] = -1;
	}
	
	//printf("->no=%d\n", no);
	
	printf("%d\n", bfs(no));
	
	return 0;
}

