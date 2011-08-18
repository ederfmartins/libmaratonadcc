#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

/** 10252 - Common Permutation */

int main()
{
	string a, b;
	
	while (getline(cin,a))
	{
		getline(cin,b); //cout << a << " " << b << endl;
		map<char, int> multSetA;
		map<char, int> multSetB;
		set<char> comuns;
		
		for (int i = 0; i < a.size(); i++) multSetA[a[i]]++;
		for (int i = 0; i < b.size(); i++)
		{
			multSetB[b[i]]++;
			if (multSetA.count(b[i]) > 0) comuns.insert(b[i]);
		}
		
		vector<char> allcomuns;
		for (set<char>::iterator ch = comuns.begin(); ch != comuns.end(); ch++)
		{	
			int menor = multSetA[(*ch)] < multSetB[(*ch)] ? multSetA[(*ch)] : multSetB[(*ch)];
			
			for (int i = 0; i < menor; i++) allcomuns.push_back(*ch);
		}

		sort(allcomuns.begin(), allcomuns.end());
		for ( int i = 0; i < allcomuns.size(); i++) cout << allcomuns[i];
		cout << endl;
	}
	return 0;	
}
