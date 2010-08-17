#define SIZE 100

struct dsf
{
    int element_count;
    int parent[SIZE];
    int rank[SIZE];
};
typedef struct dsf * disjoint_set_forest_p;

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

