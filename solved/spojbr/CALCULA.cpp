#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <inttypes.h>
#include <ctype.h>
#include <limits.h>

#include <algorithm>
#include <utility>
#include <iostream>

#include <map>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <sstream>

using namespace std;

#define abs(a) ((a) > 0 ? (a) : -(a))

int calcula(string& exp)
{
	int ret = 0;
	int sign = 1;
	string temp;
	
	for (int i = 0; i < exp.size(); i++)
	{
	//cout << temp << " " << exp[i] << " " << ret << endl;
		if (exp[i] == '+' && temp.size() > 0)
		{
			ret += atoi(temp.c_str());
			temp = "";
		}
		else if (exp[i] == '-')
		{
			if (temp.size() > 0) ret += atoi(temp.c_str());
			temp = "-";
		}
		else temp += exp[i];
	}
	
	if (temp.size() > 0) ret += atoi(temp.c_str());
	
	return ret;
}

int main()
{
	int n, t = 1;
	string exp;

	while (1)
	{
		cin >> n;
		if (n == 0) break;
		cin >> exp;
		
		cout << "Teste " << t++ << endl << calcula(exp) << endl << endl;		
	}

	return 0;
}
