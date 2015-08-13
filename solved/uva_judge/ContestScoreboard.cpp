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

/** 10258 - Contest Scoreboard */

using namespace std;
class competidor
{
public:
	int tempo;
	int tentativas[10];
	bool s[10];
	int id;
	int solved;
	bool tentou;
	competidor()
	{
		for (int i = 0; i < 10; i++)
		{
			tentativas[i] = 0;
			s[i] = false;
		}
		tempo = 0; solved = 0; tentou = false;
	}
};

bool cmpCompetidores(const competidor& c1, const competidor& c2)
{
	if (c1.solved == c2.solved)
	{
		if (c1.tempo == c2.tempo) return c1.id < c2.id;
		else if (c1.tempo < c2.tempo) return true;
		else return false;
	}
	else if (c1.solved > c2.solved) return true;
	else return false;
}

int main()
{
	int n;
	string line;

	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.ignore(numeric_limits<streamsize>::max(), '\n');	

	for (int i = 0; i < n; i++)
	{
		map<int, competidor > competidores;
		int c, p, t;
		char status;

		while (getline(cin, line))
		{
			if (!line.empty())
			{
				stringstream ss(line);
				ss >> c >> p >> t >> status;
				competidores[c].tentou = true;
				competidores[c].id = c;

				if (status == 'C')
				{
					competidores[c].id = c;
					if (! competidores[c].s[p])
					{
						competidores[c].solved++;
						competidores[c].s[p] = true;
						competidores[c].tempo = competidores[c].tempo + competidores[c].tentativas[p] * 20 + t;
					}
				}
				else if (status == 'I')
				{
					competidores[c].id = c;
					competidores[c].tentativas[p]++;
				}
			}
			else break;
		}

		vector<competidor> all;
		for (map<int, competidor>::iterator it = competidores.begin(); it != competidores.end(); it++)
		{
			if ((*it).second.tentou) all.push_back((*it).second);
		}

		sort (all.begin(), all.end(), cmpCompetidores);

		for (int j = 0; j < all.size(); j++)
			cout << all[j].id << " " << all[j].solved << " " << all[j].tempo << endl;

		if (i != (n -1)) cout << endl;
	}

	return 0;
}
