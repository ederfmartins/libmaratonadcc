#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

#define SIZE 500

struct dsf
{
    int element_count;
    int parent[SIZE];
    int rank[SIZE];
};
typedef struct dsf * disjoint_set_forest_p;
typedef struct dsf disjoint_set_forest;

void dsf_init(disjoint_set_forest_p forest, int element_count)
{
	forest->element_count = element_count;
	memset(forest->parent, 0, element_count*sizeof(int));
	memset(forest->rank, 0, element_count*sizeof(int));

	for (int i = 0; i < element_count; ++i)
		forest->parent[i] = i;
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

bool edge_compare(const edge& e1, const edge& e2)
{
    return e1.weight < e2.weight;
}

int kruskal(vector<edge>& edges, int n)
{    
    sort(edges.begin(), edges.end(), edge_compare);

    disjoint_set_forest dsf;
	dsf_init(&dsf, n);
	int mstSize = 0;

    for (int i = 0; i < edges.size(); ++i)
    {
        struct edge e = edges[i];
        int uset = dsf_find_set(&dsf, e.u);
        int vset = dsf_find_set(&dsf, e.v);
        if (uset != vset)
        {
            mstSize += e.weight;
            dsf_union(&dsf, uset, vset);
        }
    }

    return mstSize;
}

int main() {
	int n, m;
	edge e;
	vector<edge> edges;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &e.u, &e.v, &e.weight);
		edges.push_back(e);
	}
	
	printf("%d\n", kruskal(edges, n+1));
	
	return 0;
}

