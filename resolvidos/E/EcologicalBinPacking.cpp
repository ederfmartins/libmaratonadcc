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

/** 102 - Ecological Bin Packing */

using namespace std;

int main()
{
	int g1, g2, g3, c1, c2, c3, b1, b2, b3;
	int s[6];
	int idx;
	int total;

	char c[6][5] = {"BCG ", "BGC ", "CBG ", "CGB ", "GBC ", "GCB "};

	while (cin >> b1 >> g1 >> c1 >> b2 >> g2 >> c2 >> b3 >> g3 >> c3)
	{
		idx = 0;

		total = b1 + g1 + c1 + b2 + g2 + c2 + b3 + g3 + c3;
		s[0] = b1 + g3 + c2;
		s[1] = b1 + g2 + c3;
		s[2] = b2 + g3 + c1;
		s[3] = b3 + g2 + c1;
		s[4] = b2 + g1 + c3;
		s[5] = b3 + g1 + c2;

		for (int i = 1; i < 6; i++)
		{
			if (s[i] > s[idx]) idx = i;
		}

		cout << c[idx] << total - s[idx] << endl;

	}
	return 0;
}

