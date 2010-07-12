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

/** 10035 Primary Arithmetic */

using namespace std;

int main()
{
	uint64_t a, b, carry;

	while (cin >> a >> b)
	{
		int ncarry = 0;
		carry = 0;

		if (a == 0 && b == 0) break;

		while ( a > 0 || b > 0)
		{
			int sum = a%10 + b%10 + carry;

			if (sum > 9)
			{
				ncarry++;
				carry = 1;
			}
			else carry = 0;

			a = a/10;
			b = b/10;
		}

		if (ncarry == 1) cout << ncarry << " carry operation." << endl;
		else if (ncarry != 0) cout << ncarry << " carry operations." << endl;
		else cout << "No carry operation." << endl;
	}
	return 0;
}
