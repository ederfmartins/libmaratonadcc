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

/** 575 - Skew Binary */

using namespace std;

int main()
{
	string num;

	while (1)
	{
		cin >> num;

		if (num == "0") break;

		int res = 0;

		for (int i = num.size()-1, j=1; i >= 0; i--, j++)
		{
			int fator = pow(2, j) - 1;
			int digit = num[i] - '0';
			res += digit * fator;
		}

		cout << res << endl;
	}
	return 0;
}

