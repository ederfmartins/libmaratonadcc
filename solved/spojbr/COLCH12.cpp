#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int c[3];
    int d[2];

    scanf("%d %d %d", &c[0], &c[1], &c[2]);
    scanf("%d %d", &d[0], &d[1]);

    sort(c, c+3);
    sort(d, d+2);

    int i = 0;
    for (; i < 3; i++)
    {
        if (c[i] <= d[0])
            break;
    }

    if (i < 3)
    {
        i++;
        for (; i < 3; i++)
        {
            if (c[i] <= d[1])
            {
                printf("S\n");
                return 0;
            }
        }
    }

    printf("N\n");
    return 0;
}