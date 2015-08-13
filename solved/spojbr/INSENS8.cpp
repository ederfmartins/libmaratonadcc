#include <stdio.h>

int main()
{
    int n, x1,x2,y1,y2;
    int d = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        d += (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
    }
    printf("%d\n", d);
    return 0;
}