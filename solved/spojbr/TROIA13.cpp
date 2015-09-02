#include <stdio.h>
#include <string.h>

#define SIZE 50000

template<int max_size>
class dsf
{
    int element_count;
    int num_sets;
    int parent[max_size];
    int rank[max_size];

 public:
    dsf(int element_count)
    {
        this->element_count = element_count;
        num_sets = element_count;
        memset(parent, 0, element_count*sizeof(int));
        memset(rank, 0, element_count*sizeof(int));

        for (int i = 0; i < element_count; ++i)
            parent[i] = i;
    }

    int find(int set)
    {
        if (set != parent[set])
        {
            parent[set] = find(parent[set]);
        }
        return parent[set];
    }

    void union_set(int set1, int set2)
    {
        int x = find(set1);
        int y = find(set2);

        if (rank[x] > rank[y])
        {
            parent[y] = x;
        }
        else
        {
            parent[x] = y;
            if (rank[x] == rank[y])
            {
                rank[y]++;
            }
        }

        if (x != y)
            num_sets--;
    }

    int size() { return num_sets; }
};

int main()
{
    int n, m, x, y;

    scanf("%d %d", &n, &m);
    dsf<SIZE> familias(n);

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &x, &y);
        familias.union_set(x-1, y-1);
    }

    printf("%d\n", familias.size());
    return 0;
}