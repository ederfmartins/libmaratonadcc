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

/** 5474. Alarme Despertador - ad hoc muito facil
*/

using namespace std;

#define abs(a) ((a) > 0 ? (a) : -(a))

int main()
{
	int h1, h2, m1, m2;
	int diff;

	while (cin >> h1 >> m1 >> h2 >> m2)
	{
		if ((h1 | m1 | h2 | m2) == 0) break;

		h1 = h1*60 + m1;
		h2 = h2*60 + m2;
		if (h1 < h2) diff = h2 - h1;
		else diff = h2 + (24*60 - h1);
		cout << diff << endl;
	}
	return 0;
}
