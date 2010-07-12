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

/** 445 - Marvelous Mazes */

using namespace std;

#define abs(a) ((a) > 0 ? (a) : -(a))

int main()
{
	char c;
	int n = -1;

	while ((c = cin.get()) != EOF)
	{
		if (c == '\n')
		{
			n = -1;
			cout << endl;
		}
		else if (c == 'b')
		{
			if (n == -1) cout << " ";
			else for (int j = 0; j < n; j++) cout << " ";
			n = -1;
		}
		else if (c == '!')
		{
			if (n == -1) cout << endl;
			else for (int j = 0; j < n; j++) cout << endl;
			n = -1;
		}
		else if (c >= '0' && c <= '9')
		{
			if (n == -1) n = c - '0';
			else n = n + c - '0';
		}
		else
		{
			if (n == -1) cout << c;
			else for (int j = 0; j < n; j++) cout << c;
			n = -1;
		}
	}
	return 0;
}

