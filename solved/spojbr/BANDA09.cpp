#include <stdio.h>

#define TAM 100
int n;
int grau[TAM];
int adj[TAM][TAM];
int score[TAM][TAM];

void print(int x, int y, int z)
{
    int menor = x;
    int maior = x;
    if (y < menor) menor = y;
    else if (y > maior) maior = y;

    if (z < menor) menor = z;
    else if (z > maior) maior = z;

    printf("%d %d %d\n", menor, x+y+z-menor-maior, maior);
}

int main()
{
    int m, a, b, s;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) grau[i] = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &s);
        a--; b--;
        adj[a][grau[a]] = b;
        adj[b][grau[b]] = a;
        score[a][b] = s;
        score[b][a] = s;
        grau[a]++;
        grau[b]++;
    }

    int smax = -1;
    int x = 0, y = 1, z = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < grau[i]; j++) {
            a = adj[i][j];
            for (int k = 0; k < grau[a]; k++) {
                b = adj[a][k];
                if (i != a && i != b) {
                    s = score[i][a] + score[i][b] + score[a][b];
                    if (s > smax) {
                        smax = s;
                        x = i;
                        y = a;
                        z = b;
                    }
                }
            }
        }
    }

    print(x+1, y+1, z+1);
    return 0;
}