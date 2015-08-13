#include <stdio.h>
#include <algorithm>

using namespace std;

#define TAM 100000
#define LIM (1<<31 -1)

int main()
{
    int k, n;
    int dists[TAM];
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &dists[i]);
    }

    sort(dists, dists+n);
    //for (int i = 0; i < n; i++) printf("%d ", dists[i]);
    //printf("\n");

    int min_dist = LIM;

    for (int i = 0; i < n; i++)
    {
        int idx_end = i+(n-k) -1;
        if (idx_end < n)
        {
            if (dists[idx_end] - dists[i] < min_dist)
            {
                min_dist = dists[idx_end] - dists[i];
            }
        }
    }

    printf("%d\n", min_dist);

    return 0;
}