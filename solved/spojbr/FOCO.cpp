#include <stdio.h>
#include <algorithm>
using namespace std;

#define TAM 1000000

int main()
{
    int n;
    pair<int, int> pos_imagens[TAM];
    
    while (scanf("%d", &n) == 1)
    {
        for (int i = 0; i < n; i++) scanf("%d %d", &pos_imagens[i].second, &pos_imagens[i].first);

        sort(pos_imagens, pos_imagens+n);
        int foco = 0;
        int d = 0;
    
        for (int i = 0; i < n; i++)
        {
            //overlap do nothing
            //else increase
            if (pos_imagens[i].second > d) 
            {
                foco += 1;
                d = pos_imagens[i].first;
            }
        }

        printf("%d\n", foco);
    }

    return 0;
}
