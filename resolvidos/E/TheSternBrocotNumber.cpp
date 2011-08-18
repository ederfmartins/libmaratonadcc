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

/** 10077 - The Stern-Brocot Number System */


using namespace std;


int main()
{
	int m, n;

	while (cin >> m >> n)
	{
		if (m == 1 && n == 1) break;

		int a1 = 0, a2 = 1, b1 = 1, b2 = 0;

		while (1)
		{
			int m1 = a1 + b1;
			int m2 = a2 + b2;

			/*
			m   m1   mm2  m1n
			n   m2   nm2  nm2
			*/

			if (m*m2 > m1*n) 
			{
				cout << "R";
				a1 = m1; a2 = m2;
			}
			else if (m*m2 < m1*n)
			{
				cout << "L";
				b1 = m1; b2 = m2;
			}
			else break;
		}

		cout << endl;
	}
	return 0;
}

