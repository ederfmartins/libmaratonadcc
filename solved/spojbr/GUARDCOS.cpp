#include <stdio.h>
#include <math.h>

#define LIMITE 144

int main()
{
    int d, f, g;

    while(scanf("%d %d %d", &d, &f, &g) == 3)
    {
        double h = sqrt(144 + d*d);
        if (h*f <= 12*g) printf("S\n");
        else printf("N\n");
    }

    return 0;
}
