#include <stdio.h>
using namespace std;

int main()
{
	int n;
	int a1, a2, tmp, r, r1, cnt = 1;
	scanf("%d", &n);
	
	if (n <= 2) printf("1\n");
	else
	{
		scanf("%d %d", &a1, &a2);
		r = a2 - a1;
		
		for (int i = 2; i < n; i++)
		{
			scanf("%d", &tmp);
			a1 = a2;
			a2 = tmp;
			
			//printf("i=%d r=%d\n", i, a2-a1);
			
			if (a2 - a1 != r) {
				cnt++;
				
				if (++i < n) {
					scanf("%d", &tmp);
					a1 = a2;
					a2 = tmp;			
				}
			}
			
			r = a2 - a1;
		}
		
		printf("%d\n", cnt);
	}
	
	return 0;
}

