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

/** 494 - Kindergarten Counting Game */

using namespace std;

#define abs(a) ((a) > 0 ? (a) : -(a))

int main()
{
	string line;

	while (getline(cin, line))
	{
		int cnt = 0;
		bool inicio = false, fim = false;
		line = line + "\n\n";

		for (int i = 0; i < line.size(); i++)
		{
			if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z')) inicio = true;
			else if (inicio) fim = true;

			if(inicio && fim)
            {
                cnt++;
                inicio = false;
                fim = false;
            }
		}

		cout << cnt << endl;
	}
	return 0;
}

