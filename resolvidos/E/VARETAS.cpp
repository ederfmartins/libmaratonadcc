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

/** 1894. Jogo de Varetas - ad hoc muito facil*/

using namespace std;

#define abs(a) ((a) > 0 ? (a) : -(a))

int main()
{
	int n, dirty, cnt;

	while (cin >> n)
	{
		int sum = 0;
		if (n == 0) break;

		for (int i = 0; i < n; i++)
		{
			cin >> dirty >> cnt;
			sum += cnt/2;
		}
		cout << sum/2 << endl;
	}
	return 0;
}

