#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    int max = a/2;
    if (b/3 < max) max = b/3;
    if (c/5 < max) max = c/5;
    printf("%d\n", max);
    
    return 0;
}