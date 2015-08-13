#include<stdio.h>
#include<map>
#include<math.h>

using namespace std;

typedef map<int, int> prime_map;
void squeeze(prime_map& M, int& n, int p)
{
	for (; n % p == 0; n /= p) M[p]++;
}
void factor(int n, prime_map& M)
{
	if (n < 0) { factor(-n, M); return; }
	if (n < 2) return;

	squeeze(M, n, 2);
	squeeze(M, n, 3);

	int maxP = sqrt(n) + 2;
	for (int p = 5; p < maxP; p += 6)
	{
		squeeze(M, n, p);
		squeeze(M, n, p+2);
	}
	if (n > 1) M[n]++;
}

int main()
{
	int n;
	
	while (1)
	{
		scanf("%d", &n);
		if (n == 0) break;
		prime_map primeMap;
		factor(n, primeMap);
		printf("%d : %d\n", n, primeMap.size());
	}
	
	return 0;
}

