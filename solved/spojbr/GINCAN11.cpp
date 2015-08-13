#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <inttypes.h>
#include <ctype.h>
#include <limits.h>

#include <algorithm>
#include <utility>
#include <iostream>

#include <map>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <sstream>

using namespace std;

#define SIZE 1001

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

disjoint_set_forest amigos;
int conjuntos[SIZE];

int main()
{
	int n, m, a, b, cnt = 0;
	scanf("%d %d", &n, &m);
	
	dsf_init(&amigos, n+1);
	memset(conjuntos, 0, (n+1)*sizeof(int));
	
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		dsf_union(&amigos, a, b);
	}
	
	for (int i = 1; i <= n; i++)
	{
		conjuntos[dsf_find_set(&amigos, i)] = 1;
	}
	
	for (int i = 1; i <= n; i++)
	{
		cnt += conjuntos[i];
		//printf("%d ", conjuntos[i]);
	}
	
	printf("%d\n", cnt);
	return 0;
}
