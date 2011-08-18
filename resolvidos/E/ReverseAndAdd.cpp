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

/** 10018 - Reverse and Add */

using namespace std;

uint32_t reverse(uint32_t number)
{
	uint32_t rev = 0;
	int digits[100];
	int pos = 0, power = 1;
	
	memset(digits, 0, 100);
	
	while (number > 0)
	{
		digits[pos++] = number % 10;
		number = number / 10;
	}

	for (int i = pos-1; i >= 0; i--)
	{
		rev += power * digits[i];
		power *= 10;
	}
	
	return rev;
}

int main()
{
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		uint32_t num;
		int cnt = 0;
		cin >> num;

		while (true)
		{
			if (reverse(num) == num) break;
			else
			{
				num += reverse(num);
				cnt++;
			}
		}

		//cout << num << " " << cnt << endl;
		cout << cnt << " " << num << endl;
	}

	return 0;
}

