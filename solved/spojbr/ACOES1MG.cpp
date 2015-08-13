#include <stdio.h>

using namespace std;

int conta(int n, int k) {
	if (n <= k) return 1;
	
	if (n > k) {
		if (n%2 == 0) return 2*conta(n/2, k);
		else return conta(n/2, k) + conta(n/2 + 1, k);
	}
}

int main()
{
	int n, k;
	
	while (1) {
		scanf("%d %d", &n, &k);
		if (n == 0 && k == 0) break;
		
		printf("%d\n", conta(n, k));
	}
	return 0;
}

