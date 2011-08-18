#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#define abs(a) ((a) > 0 ? (a) : -(a))

int main()
{
	int n, p;
	std::cout.sync_with_stdio(false);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int v;
		string line, lixo;
		vector<int> nVisinhos;
		cin >> p;
		getline(cin, lixo);
		
		for (int j = 0; j < p; j++)
		{
			getline(cin, line);
			stringstream ss(line);
			int cnt = 0;

			while (ss >> v) cnt++;
			nVisinhos.push_back(cnt);
		}

		v = 0;
		for (int j = 1; j < nVisinhos.size(); j++)
		{
			if (nVisinhos[j] < nVisinhos[v]) v = j;
		}
		cout << v+1;
		
		for (int j = 0; j < nVisinhos.size(); j++)
		{
			if (j != v && nVisinhos[v] == nVisinhos[j])
				cout << " " << j+1;
		}
		cout << endl;
	}

	return 0;
}
