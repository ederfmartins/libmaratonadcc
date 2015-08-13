#include <stdio.h>
using namespace std;

#define TAM 1001
int incX[] = {0, 0, 1, -1};
int incY[] = {1, -1, 0, 0};
char mapa[TAM][TAM];

int main()
{
    int n, m, cnt = 0;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", mapa[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mapa[i][j] == '#')
            {
                for (int k = 0; k < 4; k++)
                {
                    if (i+incX[k] >= 0 && i+incX[k] < n && j+incY[k] >= 0 && j+incY[k] < m)
                    {
                        if (mapa[i+incX[k]][j+incY[k]] == '.')
                        {
                            cnt++;
                            break;
                        }
                    }
                    else
                    {
                        cnt++;
                        break;
                    }
                }
            }
        }
    }

    printf("%d\n", cnt);
    return 0;
}