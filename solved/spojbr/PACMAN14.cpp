#include <stdio.h>

using namespace std;

#define TAM 101

int main()
{
    int n;
    int maxPontos = 0;
    int pontos = 0;
    char linha[TAM];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", linha);
        for (int j = 0; j < n; j++)
        {
            int idx = i%2 == 0? j : (n-1-j);
            if (linha[idx] == 'o') {
                pontos++;
                if (pontos > maxPontos) maxPontos = pontos;
            }
            else if (linha[idx] == 'A') {
                pontos = 0;
            }
        }
    }
    if (pontos > maxPontos) maxPontos = pontos;

    printf("%d\n", maxPontos);

    return 0;
}