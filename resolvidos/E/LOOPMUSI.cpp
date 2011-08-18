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

/** 3242. Loop musical - derivadas e pontos limites */

using namespace std;

#define abs(a) ((a) > 0 ? (a) : -(a))

int main()
{
	int n;
	int valores[10000];

	while (cin >> n)
	{
		int loops = 0;
		if (n == 0) break;

		for (int i = 0; i < n; i++)
		{
			cin >> valores[i];
		}

		for (int i = 0; i < n; i++)
		{
			if (valores[(i-1 + n)%n] < valores[i] && valores[(i+1 + n)%n] < valores[i]) loops++;
			else if (valores[(i-1 + n)%n] > valores[i] && valores[(i+1 + n)%n] > valores[i]) loops++;
		}

		cout << loops << endl;
	}
	return 0;
}
