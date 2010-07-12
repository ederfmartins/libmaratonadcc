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

/** 3244. Divisão da Nlogonia - posicoes relativas de pontos*/

using namespace std;

#define abs(a) ((a) > 0 ? (a) : -(a))

int main()
{
	int n, x0, y0, xp, yp;

	while (cin >> n)
	{
		if (n == 0) break;

		cin >> x0 >> y0;

		for (int i = 0; i < n; i++)
		{
			cin >> xp >> yp;
			if (x0 == xp || y0 == yp) cout << "divisa";
			else
			{
				if (yp > y0) cout << "N";
				else cout << "S";

				if (xp > x0) cout << "E";
				else cout << "O";
			}

			cout << endl;
		}
	}
	return 0;
}
