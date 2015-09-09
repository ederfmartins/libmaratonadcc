#include <stdio.h>
#include <algorithm> 

using namespace std;

#define SIZE 100010

long long int raios[SIZE];

int main()
{
    int c, t;
    long long int x, y, r2;
    long long int cnt = 0;

    scanf("%d %d", &c, &t);
    for (int i = 0; i < c; i++)
    {
        scanf("%lld", &raios[i]);
        raios[i] *= raios[i];
    }

    // sort(raios, raios + c);

    for (int i = 0; i < t; i++)
    {
        scanf("%lld %lld", &x, &y);
        r2 = x*x + y*y;
        long long int* pos = lower_bound(raios, raios + c, r2);
        int points = c - (pos - raios);
        cnt += points;
    }

    printf("%lld\n", cnt);
    return 0;
}
