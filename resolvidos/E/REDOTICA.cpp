#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>
#include <queue>

/** 810. Rede ótica - arvores geradoras minimas algoritmo de kruskal*/

using namespace std;

#define MAX_VERTICES 110
#define INF (-((1<<31)+1))

typedef vector<map<int, int> > AdjList;
struct Grafo
{
	int edgeCnt;
	AdjList adj;
};

struct dsf
{
    int element_count;
    int *parent;
    int *rank;
};
typedef struct dsf * disjoint_set_forest_p;

disjoint_set_forest_p dsf_alloc(int element_count)
{
    disjoint_set_forest_p forest = (disjoint_set_forest_p) malloc(sizeof(struct dsf));

    forest->element_count = element_count;
    forest->parent = (int*) calloc(element_count, sizeof(int));
    forest->rank = (int*) calloc(element_count, sizeof(int));

    for (int i = 0; i < element_count; ++i)
        forest->parent[i] = i;

    return forest;
}

void dsf_free(disjoint_set_forest_p forest)
{
    if (forest)
    {
        free(forest->parent);
        free(forest->rank);
        forest->element_count = 0;
        forest->parent = NULL;
        forest->rank = NULL;
        free(forest);
    }
}

int dsf_find_set(disjoint_set_forest_p forest, int i)
{
    if (i != forest->parent[i])
    {
        forest->parent[i] = dsf_find_set(forest, forest->parent[i]);
    }
    return forest->parent[i];
}

void dsf_union(disjoint_set_forest_p forest, int i, int j)
{
    int x = dsf_find_set(forest, i);
    int y = dsf_find_set(forest, j);

    if (forest->rank[x] > forest->rank[y])
    {
        forest->parent[y] = x;
    }
    else
    {
        forest->parent[x] = y;
        if (forest->rank[x] == forest->rank[y])
        {
            forest->rank[y]++;
        }
    }
}

struct edge
{
    int u;
    int v;
    int weight;
};

static int edge_compare1(const void * e1, const void * e2)
{
    struct edge * p1 = (struct edge *) e1;
    struct edge * p2 = (struct edge *) e2;

	int f = p1->u - p2->u;
    if (f < 0)
    {
       return -1;
    }
    else  if (f == 0)
    {
        if (p1->v - p2->v < 0) return -1;
		else return 1;
    }
    else
    {
        return 1;
    }
}

static int edge_compare(const void * e1, const void * e2)
{
    struct edge * p1 = (struct edge *) e1;
    struct edge * p2 = (struct edge *) e2;
    int f = p1->weight - p2->weight;
    if (f < 0)
    {
       return -1;
    }
    else  if (f == 0)
    {
        return edge_compare1(e1, e2);
    }
    else
    {
        return 1;
    }
}

static struct edge * get_edge_list(Grafo& graph)
{
    int edge_count = graph.edgeCnt;
    struct edge *edges = (struct edge*) malloc(edge_count * sizeof(struct edge));

    int current_edge = 0;

    for (int i = 0; i < graph.adj.size(); ++i)
    {
        for (map<int, int>::iterator j = graph.adj[i].begin(); j != graph.adj[i].end(); j++)
        {
            struct edge e;
            e.u = i < (*j).first ? i : (*j).first;
            e.v = i > (*j).first ? i : (*j).first;
            e.weight = (*j).second;
            edges[current_edge++] = e;
        }
    }

    return edges;
}

void mst_kruskal(Grafo& graph, Grafo& mst)
{
    // Obtain a list of edges and sort it by weight in O(E lg E) time
    int edge_count = graph.edgeCnt;
    struct edge *edges = get_edge_list(graph);
    qsort(edges, edge_count, sizeof(struct edge), edge_compare);

    disjoint_set_forest_p dsf = dsf_alloc(edge_count);

    for (int i = 0; i < edge_count; ++i)
    {
        struct edge e = edges[i];
        int uset = dsf_find_set(dsf, e.u);
        int vset = dsf_find_set(dsf, e.v);
        if (uset != vset)
        {
            mst.adj[e.u][e.v] = e.weight; mst.edgeCnt++;
            dsf_union(dsf, uset, vset);
        }
    }

    dsf_free(dsf);
    free(edges);
}

int main()
{
    int n, m;
	int teste = 1;

    while(cin >> n >> m)
	{
        if(n==0 && m==0) return 0;

        Grafo g;
		g.edgeCnt = 0;
		g.adj.resize(MAX_VERTICES);

        for (int cnt = 0; cnt < m; cnt++)
		{
            int i,j,t;
            cin >> i >> j >> t;
            g.adj[i-1][j-1] = t;
			g.edgeCnt++;
        }

		Grafo mst;
		mst.edgeCnt = 0;
		mst.adj.resize(MAX_VERTICES);

        mst_kruskal(g, mst);
        cout << "Teste " << teste++ << endl;
		struct edge *edges = get_edge_list(mst);
		qsort(edges, mst.edgeCnt, sizeof(struct edge), edge_compare1);
		for (int i = 0; i < mst.edgeCnt; i++)
		{
			cout << edges[i].u + 1 << " " << edges[i].v + 1 << endl;
		}
		free(edges);
		cout << endl;
    }
    return 0;
}

