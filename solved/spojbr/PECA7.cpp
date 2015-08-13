#include <stdio.h>

int main()
{
    int n, tmp, cnt = 0;
    scanf("%d", &n);

    for (int i = 1; i < n; i++) {
        scanf("%d", &tmp);
        cnt += tmp;
    }

    printf("%d\n", (1+n)*n/2 - cnt);
    
    return 0;
}