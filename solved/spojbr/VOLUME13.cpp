#include <stdio.h>

using namespace std;

int main()
{
    int v, t;
    scanf("%d %d\n", &v, &t);

    for (int i = 0; i < t; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        v += tmp;

        if (v < 0) v = 0;
        else if (v > 100) v = 100;
    }

    printf("%d\n", v);
    return 0;
}