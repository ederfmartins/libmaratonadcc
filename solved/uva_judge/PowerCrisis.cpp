#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>

/** 151 - Power Crisis
 * http://en.wikipedia.org/wiki/Josephus_problem
 * http://uvatoolkit.com/problemssolve.php
 */

using namespace std;

int josephus(int n, int m)
{
	int res = 0;
	vector <int> people;
	int loc = 0;

	for (int i = 0; i < n; i++) people.push_back(i+1);

	while (people.size() > 1)
	{
		if (loc >= people.size())
			loc %= people.size();

		people.erase(people.begin()+loc);
		loc += (m-1);
	}

	return people[0];
}

int main()
{
	int num;

	while (1)
	{
		cin >> num;

		if (num == 0) break;

		for ( int i = 1; i < num + 1; i++)
		{
			int winner = josephus(num, i);

			if (winner == 13)
			{
				cout << i << endl;
				break;
			}
		}
	}

	return 0;
}

