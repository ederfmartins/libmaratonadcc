#include <stdio.h>

#define max(a, b) ((a) > (b)? (a) : (b))

int main()
{
    int x, y, a1, a2, b1, b2;
    scanf("%d %d %d %d %d %d", &x, &y, &a1, &a2, &b1, &b2);

    if      (max(a1, b1) <=x && a2+b2 <= y) printf("S\n");
    else if (max(a1, b2) <=x && a2+b1 <= y) printf("S\n");
    else if (a1+b1 <=x && max(a2, b2) <= y) printf("S\n");
    else if (a1+b2 <=x && max(a2, b1) <= y) printf("S\n");

    else if (max(a2, b1) <=x && a1+b2 <= y) printf("S\n");
    else if (max(a2, b2) <=x && a1+b1 <= y) printf("S\n");
    else if (a2+b1 <=x && max(a1, b2) <= y) printf("S\n");
    else if (a2+b2 <=x && max(a1, b1) <= y) printf("S\n");

    else printf("N\n");
    return 0;
}