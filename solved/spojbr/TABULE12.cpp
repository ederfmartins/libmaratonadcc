#include <stdio.h>

int main()
{
    int n, m;
    int x = 4;
    int y = 3;
    int cnt = 0;
    int xinc[] = {0,1,2, 2, 1,-1,-2,-2,-1};
    int yinc[] = {0,2,1,-1,-2,-2,-1, 1, 2};

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        cnt += 1;
        x += xinc[m];
        y += yinc[m];
        if ((x == 1 && y == 3) || (x == 2 && y ==  3) || (x == 2 && y ==  5) || (x == 5 && y ==  4))
            break;
    }

    printf("%d\n", cnt);
    return 0;
}