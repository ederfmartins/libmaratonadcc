#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <inttypes.h>
#include <ctype.h>
#include <limits.h>

#include <algorithm>
#include <utility>
#include <iostream>

#include <map>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <sstream>

using namespace std;

#define abs(a) ((a) > 0 ? (a) : -(a))

int main()
{
	int n;
	int dist = 0;
	int v,t;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> t >> v;
		dist += t*v;
	}

	cout << dist << endl;
	return 0;
}
