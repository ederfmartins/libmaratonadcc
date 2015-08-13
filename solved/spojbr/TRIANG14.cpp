#include <stdio.h>

using namespace std;

int main()
{
    int varetas[4];
    for (int i = 0; i < 4; i++)
        scanf("%d", &varetas[i]);

    for (int i = 0; i < 4; i++)
        for (int j = i+1; j < 4; j++)
            for (int k = j+1; k < 4; k++)
                if (varetas[i] < varetas[j] + varetas[k] &&
                    varetas[j] < varetas[i] + varetas[k] &&
                    varetas[k] < varetas[j] + varetas[i]) {
                    printf("S\n");
                    return 0;
                }
    printf("N\n");
    return 0;
}