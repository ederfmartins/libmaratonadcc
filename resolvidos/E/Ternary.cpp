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

/**  */

using namespace std;


int main()
{
	int n;
	char ternary[50];
	int idx;

	while (1)
	{
		cin >> n;
		if (n < 0) break;

		idx = 0;

		do
		{
			ternary[idx++] = '0' + n%3;
			n /= 3;
		} while (n > 0);

		for (int i = idx -1; i >= 0; i--)
			cout << ternary[i];

		cout << endl;
		
	}
	return 0;
}

