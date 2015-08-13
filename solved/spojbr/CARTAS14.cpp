#include <stdio.h>

int main()
{
    int x, y;
    bool asc = true, desc = true;
    scanf("%d", &x);

    for (int i = 0; i < 4; i++) {
        scanf("%d", &y);
        asc &= (x < y);
        desc &= (x > y);
        x = y;
    }

    if (asc && !desc) printf("C\n");
    else if (!asc && desc) printf("D\n");
    else printf("N\n");
    return 0;
}