#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

/** 382 - Perfection */

using namespace std;

int countFactors(int num)
{
	if (num == 1) return 0;

	int res = 1;

	for (int i = 2; i < num/2; i++)
	{
		if (num % i == 0) res += i;
	}

	return res;
}

int main()
{
	int num;

	printf("PERFECTION OUTPUT\n");

	while (1)
	{
		scanf("%i", &num);

		if (num == 0) break;

		int fcount = countFactors(num);

		if (fcount == num) printf("%5d  PERFECT\n", num);
		else if (fcount > num) printf("%5d  ABUNDANT\n", num);
		else if (fcount < num) printf("%5d  DEFICIENT\n", num);
	}

	printf("END OF OUTPUT\n");
	return 0;
}

