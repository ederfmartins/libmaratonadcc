#include <stdio.h>
#include <set>

using namespace std;

#define TAM 50000
int fila[TAM];

int main()
{
    int n, m, t;
    set<int> saiu;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) scanf("%d", &fila[i]);

    scanf("%d\n", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &t);
        saiu.insert(t);
    }

    for (int i = 0; i < n; i++) {
        if (saiu.count(fila[i]) == 0) {
            if (i == n-1) printf("%d", fila[i]);
            else printf("%d ", fila[i]);
        }
    }
    
    printf("\n");
    return 0;
}