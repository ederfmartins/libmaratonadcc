#include <stdio.h>

int main()
{
    int atual, ant = 0, max = 0, rep =0;
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &atual);

        if (atual == ant) rep++;
        else {
            if (rep > max) max = rep;
            ant = atual;
            rep = 1;
        }
    }
    if (rep > max) max = rep;
    printf("%d\n", max);
    return 0;
}