#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <inttypes.h>
#include <ctype.h>
#include <limits.h>

#include <algorithm>
#include <utility>
#include <iostream>

#include <map>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <sstream>

using namespace std;

#define abs(a) ((a) > 0 ? (a) : -(a))

int main()
{
	int n, m;
	int cnt = 1;
	int temperaturas[10000];

	while (scanf("%d %d", &n, &m) == 2)
	{
		if (n == 0 && m == 0) break;
		int max = -1000;
		int min = 1000;
		int media = 0;
		
		
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &temperaturas[i]);
			
			media += temperaturas[i];
			
			//printf("--->%d %d %d %d\n", temperaturas[i], media,  max, min);
			if (i >= m - 1)
			{
				if (media/m > max) max = media/m;
				if (media/m < min) min = media/m;
				
				media -= temperaturas[i - m + 1];
			}
			//printf("->%d %d %d %d\n", temperaturas[i], media,  max, min);
		}
		
		printf("Teste %d\n%d %d\n\n", cnt++, min, max);
	}
	return 0;
}

