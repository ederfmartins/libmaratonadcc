#include <stdio.h>
using namespace std;

int main()
{
	int t = 0, x, y, w, h;
	int n, a, b;
	
	while (scanf("%d %d %d %d", &x, &y, &w, &h) == 4)
	{
		if (x == 0 && y == 0 && w == 0 && h == 0) break;
		scanf("%d", &n);
		int cnt = 0;
		
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &a, &b);
			
			if (a >= x && a <= w && b <= y && b >= h)
				cnt++;
		}
		
		printf("Teste %d\n%d\n\n", ++t, cnt);
	}
	return 0;
}

