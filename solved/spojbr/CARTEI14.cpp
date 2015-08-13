#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;

int main()
{
    map<int, int> numeros;
    int n, m, tmp, cnt = 0, atual = 0;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        numeros[tmp] = i;
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &tmp);
        cnt += abs(atual - numeros[tmp]);
        atual = numeros[tmp];
    }

    printf("%d\n", cnt);
    return 0;
}
