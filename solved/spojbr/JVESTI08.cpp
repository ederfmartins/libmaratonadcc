#include <stdio.h>

int main()
{
    int n, cnt = 0;
    char gab[100], resp[100];
    scanf("%d %s %s", &n, gab, resp);
    for (int i = 0; i < n; i++)
        if (gab[i] == resp[i])
            cnt++;
    printf("%d\n", cnt);
    return 0;
}