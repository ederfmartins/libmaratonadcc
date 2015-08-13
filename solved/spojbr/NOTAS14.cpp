#include <stdio.h>

int main()
{
    int n, tmp, notas[101];
    scanf("%d", &n);
    for (int i = 0; i <= 100; i++) notas[i] = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        notas[tmp]++;
    }
    tmp = 0;
    int nota;

    for (int i = 0; i <= 100; i++) {
        if (tmp <= notas[i]) {
            tmp = notas[i];
            nota = i;
        }
    }
    printf("%d\n", nota);
    
    return 0;
}