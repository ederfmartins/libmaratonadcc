#include <stdio.h>

using namespace std;

#define TAM 1002

int incX[] = {0, 0, 1, -1};
int incY[] = {1, -1, 0, 0};
int grid[TAM][TAM];

int main()
{
    int l, c;
    int x, y;
    scanf("%d %d", &l, &c);
    scanf("%d %d", &x, &y);

    // flags para facilitar caminhar sobre a matriz
    for (int i = 0; i <= l; i++) {
        grid[i][0] = 0;
        grid[i][c+1] = 0;
    }

    for (int i = 0; i <= c; i++) {
        grid[0][i] = 0;
        grid[l+1][i] = 0;
    }

    // read input
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= c; j++)
            scanf("%d", &grid[i][j]);
    }

    // 'bsf' sobre a matriz
    bool ok = true;
    while (ok)
    {
        grid[x][y] = 0;
        ok = false;

        for (int i = 0; i < 4; i++)
        {
            if (grid[x+ incX[i]][y+ incY[i]] == 1)
            {
                x = x + incX[i];
                y = y + incY[i];
                ok = true;
                break;
            }
        }
    }

    printf("%d %d\n", x, y);

    return 0;
}