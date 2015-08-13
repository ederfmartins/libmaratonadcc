#include <iostream>
#include <set>

using namespace std;
/*
 * 10050 - Hartals
 */
int main()
{
	int t, n, p, tmp;
	char bitSet[3651];

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		set<int> hartals;
		set<int> h;

		cin >> n >> p;

		int totalHartals = 0;
		memset(bitSet, 0, n+1);

		for (int j = 0; j < p; j++)
		{
			cin >> tmp;
			h.insert(tmp);
		}

		for (set<int>::iterator it = h.begin(); it != h.end(); it++)
		{
			tmp = (*it);

			for (int k = tmp; k <= n; k = k + tmp)
			{
				if (k % 7 != 6 && k % 7 != 0)
				{
					if (!bitSet[k]) totalHartals++;
					bitSet[k] = 1;
					//cout << k << " ";
				}
			}
		}
		//cout << endl;
		cout << totalHartals << endl;
	}
	return 0;
}

