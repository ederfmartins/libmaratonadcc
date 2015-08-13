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


/** 10008 - What's Cryptanalysis? */

using namespace std;

class Termo
{
public:
	char t;
	int cnt;
	Termo (char a, int i) : t(a), cnt(i){};
};

bool myfunction (Termo i, Termo j)
{
	if (i.cnt == j.cnt) return i.t < j.t;
	else return i.cnt > j.cnt;
}

int main()
{
	int n;
	map<char, int> termCnt;
	string line;

	getline(cin, line);

	stringstream ss(line);
	ss >> n;

	for (int i = 0; i < n; i++)
	{
		getline(cin, line);

		for (int j = 0; j < line.size(); j++)
		{
			if ((line[j] >= 'a' && line[j] <= 'z') || (line[j] >= 'A' && line[j] <= 'Z'))
			{
				if (termCnt.count(toupper(line[j])) > 0 ) termCnt[toupper(line[j])]++;
				else termCnt[toupper(line[j])] = 1;
			}
		}
	}

	vector<Termo> resp;
	for (map<char, int>::iterator it = termCnt.begin(); it != termCnt.end(); it++)
		resp.push_back(Termo((*it).first, (*it).second));

	sort(resp.begin(), resp.end(), myfunction);

	for (int i = 0; i < resp.size(); i++)
		cout << resp[i].t << " " << resp[i].cnt << endl;


	return 0;
}

