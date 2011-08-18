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
#include <stack>

/** 101 The Blocks Problem
 * Brute force, simulacao
 */

using namespace std;

int block[25];
stack<int> s[25], tmp;

void swap(int a)
{
	int t = s[block[a]].top();
	s[t].push(t);
	block[t] = t;
	s[block[a]].pop();
}

void move_onto(int a, int b)
{
	while(s[block[a]].top() != a) swap(a);


	while(s[block[b]].top() != b) swap(b);

	s[block[b]].pop();
	block[b] = b;
	s[b].push(b);

	s[b].push(s[block[a]].top());
	s[block[a]].pop();
	block[a] = b;
}

void move_over(int a, int b)
{
	while(s[block[a]].top() != a) swap(a);

	s[block[b]].push(s[block[a]].top());
	s[block[a]].pop();
	block[a] = block[b];
}

void pile_onto(int a, int b)
{
	while(s[block[b]].top() != b) swap(b);

	s[block[b]].pop();
	block[b] = b;
	s[b].push(b);

	while(s[block[a]].top() != a)
	{
		tmp.push(s[block[a]].top());
		s[block[a]].pop();
	}

	tmp.push(s[block[a]].top());
	s[block[a]].pop();   

	while(!tmp.empty())
	{
		s[block[b]].push(tmp.top());
		block[tmp.top()] = block[b];
		tmp.pop();
	}
}

void pile_over(int a, int b)
{
	while(s[block[a]].top() != a)
	{
		tmp.push(s[block[a]].top());
		s[block[a]].pop();
	}

	tmp.push(s[block[a]].top());
	s[block[a]].pop();

	while(!tmp.empty())
	{
		s[block[b]].push(tmp.top());
		block[tmp.top()] = block[b];
		tmp.pop();
	}
}

int main()
{
	int n, a, b;
	char ar_1[10], ar_2[10];

	while(cin >> n)
	{
		for(int i = 0; i < n; i++)
		{
			s[i].push(i);
			block[i] = i;
		}

		while(cin >> ar_1)
		{
			if(ar_1[0] == 'q')
			break;

			cin >> a >> ar_2 >> b;

			if(a != b && block[a] != block[b])
			{
				if(ar_1[0] == 'm')
				{
					if(ar_2[1] == 'n') move_onto(a,b);
					else move_over(a,b);
				}
				else
				{
					if(ar_2[1] == 'n') pile_onto(a,b);
					else pile_over(a,b);
				}
			}
		}

		for(int i = 0; i < n; i++)
		{
			cout << i << ":";

			if(s[i].empty()) cout << endl;
			else
			{
				while(!s[i].empty())
				{
					tmp.push(s[i].top());
					s[i].pop();
				}

				while(!tmp.empty())
				{
					cout << " " << tmp.top();
					tmp.pop();
				}

				cout << endl;
			}
		}
	}

    return 0;
}

