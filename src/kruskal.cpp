typedef vector<map<int, int> > AdjList;
struct Grafo
{
	int edgeCnt;
	AdjList adj;
};

struct edge
{
    int u;
    int v;
    int weight;
};

int edge_compare(const void * e1, const void * e2)
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

struct edge * get_edge_list(Grafo& graph)
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

void kruskal(Grafo& graph, Grafo& mst)
{
    // Obtain a list of edges and sort it by weight in O(E lg E) time
    int edge_count = graph.edgeCnt;
    struct edge *edges = get_edge_list(graph);
    qsort(edges, edge_count, sizeof(struct edge), edge_compare);

    disjoint_set_forest dsf;
	dsf_init(&dsf, edge_count);

    for (int i = 0; i < edge_count; ++i)
    {
        struct edge e = edges[i];
        int uset = dsf_find_set(&dsf, e.u);
        int vset = dsf_find_set(&dsf, e.v);
        if (uset != vset)
        {
            mst.adj[e.u][e.v] = e.weight;
			mst.edgeCnt++;
            dsf_union(&dsf, uset, vset);
        }
    }

    free(edges);
}
