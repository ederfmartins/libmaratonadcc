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

/** 1885. Posiçoes Livres - ad hoc muito facil*/

using namespace std;

#define abs(a) ((a) > 0 ? (a) : -(a))
#define MAX 501

int main()
{
	int w,h,n, x1, x2, y1, y2, xMin, xMax, yMin, yMax;
	char posLivre[MAX][MAX];
	//posLivre[w][h]


	while (cin >> w >> h >> n)
	{
		if (!(w | h | n)) break;

		for (int i = 1; i <= w; i++)
			memset(posLivre[i], 1, h + 1);

		for (int i = 0; i < n; i++)
		{
			cin >> x1 >> y1 >> x2 >> y2;

			if (x1 < x2) { xMin = x1; xMax = x2; }
			else { xMin = x2; xMax = x1; }

			if (y1 < y2) { yMin = y1; yMax = y2; }
			else { yMin = y2; yMax = y1; }

			for (int j = xMin; j <= xMax; j++)
			{
				for (int k = yMin; k <= yMax; k++)
				{
					posLivre[j][k] = 0;
				}
			}
		}

		int cnt = 0;
		for (int i = 1; i <= w; i++)
			for (int j = 1; j <= h; j++)
				if (posLivre[i][j])
					cnt++;

		if (cnt == 0) cout << "There is no empty spots." << endl;
		else if(cnt == 1) cout << "There is one empty spot." << endl;
		else cout << "There are " << cnt << " empty spots." << endl;
	}
	return 0;
}

