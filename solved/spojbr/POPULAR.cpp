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

/** 2839. Popularidade - ad hoc muito facil */

using namespace std;

#define abs(a) ((a) > 0 ? (a) : -(a))

int main()
{
	int n;
	int valores[1000];
	int voto, maior;

	while (cin >> n)
	{
		if (n == 0) break;

		for (int i = 0; i < n; i++)
		{
			valores[i] = 0;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> voto;
				valores[j] += voto;
			}
		}

		maior = 0;

		for (int i = 0; i < n; i++)
		{
			if (valores[i] > maior) maior = valores[i];
		}

		cout << maior << endl;
	}
	return 0;
}
