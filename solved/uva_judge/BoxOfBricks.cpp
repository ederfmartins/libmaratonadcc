#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

/** 591 - Box of Bricks*/

using namespace std;

int main()
{
	int num, kase=0;

 	while (1) 
	{
		kase++;
		cin >> num;

		if (num == 0) break;

		int sum=0, res = 0;
		int avg;

		vector <int> nums;

		for (int i = 0; i < num; i++)
		{
			int t;
			cin >> t;
			nums.push_back(t);
			sum += t;
 		}

 		avg = sum/num;

 		for (int i = 0; i < num; i++)
		{
 			if (nums[i] > avg) res += (nums[i]-avg);
 		}

 		cout << "Set #" << kase << endl;
		cout << "The minimum number of moves is " << res << "." << endl;
		cout << endl;
	}

	return 0;
}

