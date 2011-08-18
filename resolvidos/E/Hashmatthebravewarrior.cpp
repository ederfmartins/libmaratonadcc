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

/** 10055 - Hashmat the Brave Warrior */

using namespace std;

#define abs(a) ((a) > 0 ? (a) : -(a))

int main()
{
	uint64_t n, m;

	while (cin >> n >> m)
	{
		uint64_t diff;
		if (n > m) diff = n - m;
		else diff = m - n;

		cout << diff << endl;
	}
	return 0;
}

