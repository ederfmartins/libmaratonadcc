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

/** 10300 - Ecological Premium */

using namespace std;

#define abs(a) ((a) > 0 ? (a) : -(a))

int main()
{
	int n, f, a, b, c, s;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> f;
		s = 0;
		for (int j = 0; j < f; j++)
		{
			cin >> a >> b >> c;
			s += a*c;
		}
		cout << s << endl;
	}

	return 0;
}

