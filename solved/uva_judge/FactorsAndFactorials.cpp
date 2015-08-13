#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <inttypes.h>
#include <ctype.h>

#include <algorithm>
#include <utility>
#include <iostream>

#include <map>
#include <set>
#include <vector>
#include <sstream>

/** 160 - Factors and Factorials */

using namespace std;

/*fatoracao da apostila do site da maratona adaptado*/
typedef map<int, int> prime_map;

void squeeze(prime_map& M, int& n, int p)
{
	for (; n % p == 0; n /= p) M[p]++;
}

prime_map factor(int n)
{
	prime_map M;

	if (n < 0) return factor(-n);
	if (n < 2) return M;

	squeeze(M, n, 2); squeeze(M, n, 3);

	int maxP = sqrt(n) + 2;

	for (int p = 5; p < maxP; p += 6)
	{
		squeeze(M, n, p);
		squeeze(M, n, p+2);
	}

	if (n > 1) M[n]++;

	return M;
}

int main()
{
	int n;

	while (cin >> n)
	{
		prime_map fators;

		if (n == 0) break;

		for (int i = 2; i <= n; i++)
		{
			prime_map nfators = factor(i);

			for (prime_map::iterator facIt = nfators.begin(); facIt != nfators.end(); facIt++)
			{
				fators[(*facIt).first] += (*facIt).second;
			}
		}

		printf("%3d! =", n);
		prime_map::iterator it = fators.begin();

		for (int i = 0; i < fators.size(); i++)
		{
			if (i % 15 == 0 && i != 0) printf("\n      ");
			printf("%3d", (*it).second );
			it++;
		}
		printf("\n");
	}
	return 0;
}

