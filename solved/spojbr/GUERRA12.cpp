#include <stdio.h>

int main()
{
    int ter[100000];
    int n;
    int total = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &ter[i]);
        total += ter[i];
    }

    total /= 2;

    for (int i = 0; i < n; i++) {
        total -= ter[i];
        if (total == 0) {
            printf("%d\n", i+1);
            break;
        }
    }
    return 0;
}