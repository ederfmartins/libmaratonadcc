#include <stdio.h>

int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    
    //ab + (a-1)*(b-1) = 2ab -a -b + 1 = n
    //2ab - b = n + a - 1
    //b = (n + a - 1)/(2a - 1)

    //mas a <= b => a <= (n + a - 1)/(2a - 1)
    //donde 2*a^2 - 2*a + 1 <= n

    for (int i = 2; 2*i*i - 2*i + 1 <= n; i++) {
        if ((n+i-1)%(2*i-1) == 0) {
            cnt++;
            //printf("%d\n", i);
        }
            
    }

    printf("%d\n", cnt);
    
    return 0;
}
