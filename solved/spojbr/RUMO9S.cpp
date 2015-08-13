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

/** 2281. Rumo aos 9s - ad hoc recursivo */

using namespace std;

#define abs(a) ((a) > 0 ? (a) : -(a))

int degree9(int n)
{
	if (n == 9) return 1;
	if (n % 9 == 0)
	{
		int r = 0;
		while (n > 0)
		{
			r += n%10;
			n /= 10;
		}
		return 1 + degree9(r);
	}
	else return 0;
}

int degree9(vector<int>& s)
{
	int m9 = 0;

	if (s.size() == 0) return 0;

	for (int i = 0; i < s.size(); i++)
	{
		m9 += s[i];
	}

	if (m9 % 9 == 0) return degree9(m9);
	else return 0;
}

int main()
{
	string n;

	while (cin >> n)
	{
		if (n[0] == '0') break;
		vector<int> number;

		for (int i = 0; i < n.size(); i++)
			number.push_back(n[i] - '0');

		int d9 = degree9(number);

		if (d9 == 0) cout << n << " is not a multiple of 9." << endl;
		else cout << n << " is a multiple of 9 and has 9-degree " << d9 << "." << endl;
	}
	return 0;
}

