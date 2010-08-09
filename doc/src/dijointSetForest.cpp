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

