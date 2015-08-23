#include <stdio.h>
#include <stdlib.h>

#define TAM 1000

int main()
{
    int n, m;
    int cnt = 0, acum = 0;
    int alturas[TAM];

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &alturas[i]);

    for (int i = 0; i < n; i++)
    {
        int diff = m - (alturas[i] + acum);
        cnt += abs(diff);
        acum = diff;
    }

    printf("%d\n", cnt);
    return 0;
}