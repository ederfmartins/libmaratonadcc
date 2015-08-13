#include <stdio.h>

int main()
{
    int p, r;
    scanf("%d %d", &p, &r);
    if (!p) printf("C\n");
    else if (r) printf("A\n");
    else printf("B\n");
    return 0;
}