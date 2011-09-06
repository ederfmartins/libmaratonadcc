#include <stdio.h>
#include <map>
#include <math.h>
using namespace std;

typedef map<int, int> prime_map;

void squeeze(prime_map& M, int& n, int p)
{
	for (; n%p == 0; n/=p) M[p]++;
}

void factor(int n, prime_map& M)
{
	if (n < 2) return;
	
	squeeze(M, n, 2);
	squeeze(M, n, 3);
	
	int maxP = sqrt(n) + 2;
	
	for (int p = 5; p < maxP; p+=6)
	{
		squeeze(M, n, p);
		squeeze(M, n, p+2);
	}
	
	if (n > 1) M[n]++;
}

int main()
{
	int n;
	
	while (scanf("%d", &n) == 1 && n != 0)
	{
		prime_map pm;
		prime_map::iterator it;
		
		if (n == -1) {
			it = pm.begin();
			printf("-1 = -1 x 1");
		}
		else if (n < 0)
		{
			factor(-n, pm);
			printf("%d = -1", n);
			it = pm.begin();
		}
		else if (n == 1) {
			it = pm.begin();
			printf("1 = 1");
		}
		else {
			factor(n, pm);
			printf("%d = ", n);
			it = pm.begin();
			
			if (pm.size() > 0)
			{
				printf("%d", (*it).first);
				for (int i = 1; i < (*it).second; i++) printf(" x %d", (*it).first);
				it++;
			}
		}
		
		for (; it != pm.end(); it++)
		{
			for (int i = 0; i < (*it).second; i++) printf(" x %d", (*it).first);
		}
		
		printf("\n");
	}

	return 0;
}

