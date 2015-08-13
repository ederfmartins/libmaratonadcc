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

/** 3742. Feynman - soma de quadrados formula sai por inducao finita*/

using namespace std;

#define abs(a) ((a) > 0 ? (a) : -(a))

int main()
{
	int quad, n;

	while (cin >> n)
	{
		if (n == 0) break;

		quad = 0;
		for (int i = 1; i <= n; i++)
		{
			quad += i*i;
		}
		cout << quad << endl;
	}
	return 0;
}
