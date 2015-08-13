#include <stdio.h>
using namespace std;

int main()
{
	int h,m,s;
	int meiaNoite = 24*60*60;
	
	while (scanf("%d:%d:%d\n", &h, &m, &s) == 3)
	{
		s += 60*m + 60*60*h;
		printf("%d\n", meiaNoite-s);
	}
	
	return 0;
}

