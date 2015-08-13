#include <stdio.h>
#include <inttypes.h>

using namespace std;

int main()
{
	int n;
	uint64_t m, x = 0, y =0, tmp;
	char dir;
	int saiu = 0;
	
	scanf("%d %lld\n", &n, &m);
	m = m*m;
	
	for (int i = 0; i < n; i++)
	{
		scanf("%c %lld\n", &dir, &tmp);
		
		switch (dir)
		{
			case 'N': y += tmp; break;
			case 'O': x -= tmp; break;
			case 'S': y -= tmp; break;
			case 'L': x += tmp; break;
		}
		
		if (m < x*x + y*y) {
			saiu = 1;
			break;
		}
	}
	
	printf("%d\n", saiu);
	
	return 0;
}

