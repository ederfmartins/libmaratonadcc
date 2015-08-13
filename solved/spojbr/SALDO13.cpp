#include <stdio.h>

int main()
{
    int n, s, t, m;
    bool asc = true, desc = true;
    scanf("%d %d", &n, &s);
    m = s;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        s += t;
        if (s < m) m = s;
    }
    printf("%d\n", m);
    return 0;
}