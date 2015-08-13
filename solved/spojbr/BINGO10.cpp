#include<stdio.h>
#include <stdlib.h>
using namespace std;

#define NUM_BOLAS 100

int main()
{
	int n, b;
	int bolas[NUM_BOLAS];
	int possiveisDiffs[NUM_BOLAS];
	
	while (1)
	{
		scanf("%d %d", &n, &b);
		if (n == 0 && b == 0) break;
		
		for (int i = 0; i <= n; i++) possiveisDiffs[i] = 0;
		
		for (int i = 0; i < b; i++) scanf("%d", &bolas[i]);
		
		for (int i = 0; i < b; i++) 
		{
			for (int j = i; j < b; j++) 
			{
				int diff = abs(bolas[i] - bolas[j]);

				if (diff <= n)
				{
					possiveisDiffs[diff]++;
				}
			}
		}
		
		bool ok = true;
		for (int i = 0; i <= n; i++) 
		{
			if (possiveisDiffs[i] == 0) {
				ok = false;
				break;
			}
		}
		
		printf("%c\n", ok ? 'Y' : 'N');
	}
	
	return 0;
}

