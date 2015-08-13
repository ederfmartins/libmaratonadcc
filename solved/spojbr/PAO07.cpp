#include<stdio.h>
#include <algorithm>
using namespace std;

int valores[10000];

int conta(int k, int m)
{
	int p = 0;
	for (int i = 0; i < k; i++) {
		p += valores[i]/m;
	}
	
	return p;
}

bool verifica(int k, int m, int n)
{
	return conta(k, m) >= n;
}

int main()
{
	int n, k, s;
	int low = 1, high = 0, m, p = 0, p1 = 0;
	
	scanf("%d %d", &n, &k);
	
	for (int i = 0; i < k; i++) {
		scanf("%d", &valores[i]);
		
		if (high < valores[i]) high = valores[i];
	}
	
	for (int i = 0; i < k; i++) {
		p += valores[i];
		p1 += valores[i]/high;
	}
	
	if (p == n) printf("1\n");
	else if (p1 == n) printf("%d\n", k);
	else {
		s = 0;
		while (low <= high) {
			m = low + (high - low)/2;
			p = conta(k, m);
			
			if (verifica(k, m, n)) {
				low = m + 1;
				s = m;
      		}
      		else { 
				high = m - 1;
    		}
		}
		
		printf("%d\n", s);
	}
	
	return 0;
}

