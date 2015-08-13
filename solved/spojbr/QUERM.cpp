#include <stdio.h>

using namespace std;

int main()
{
	int n, cnt = 1, num;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &num);
			if (num == i)
			{
				printf("Teste %d\n%d\n\n", cnt++, i);
			}
		}
	}
	return 0;
}

