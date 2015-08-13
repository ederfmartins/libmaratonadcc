#include <stdio.h>
#include <math.h>
#include <inttypes.h>

using namespace std;

bool isPrime(uint64_t n)
{
	if (n == 1) return true;
	if (n < 5 || n % 2 == 0 || n % 3 == 0) return (n == 2 || n == 3);

	uint64_t maxP = sqrt(n) + 2;
	for (uint64_t p = 5; p < maxP; p += 6)
	{
		if (n % p == 0 || n % (p+2) == 0) return false;
	}
	return true;
}

int main()
{
	uint64_t n;
	scanf("%lld", &n);
	
	if (isPrime(n)) printf("N\n");
	else printf("S\n");
	
	return 0;
}

