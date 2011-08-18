#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

/** 10370 - Above Average */

using namespace std;

int main() 
{
	int cnt;
	cin >> cnt;

	while (cnt--)
	{
		int sum=0, res=0;
		int num;
		long double avg;
		vector <int> nums;

		cin >> num;

		for (int i = 0; i < num; i++)
		{
			int cur;
			cin >> cur;
			sum += cur;
			nums.push_back(cur);
		}

		avg = (long double)sum/num;

		for (int i = 0; i < num; i++)
		{
			if (nums[i] > avg) 
			{
				res++;
			}
		}

		printf("%0.3lf%%\n", (double)res*100/num);
	}

	return 0;
}

