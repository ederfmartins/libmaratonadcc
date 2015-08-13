#include <iostream>
#include <bitset>
#include <string.h>
#include <stdio.h>

using namespace std;

/** 1353. Festa Junina - Clique maxima */

#define MAX 20

int grafo[MAX];
int n;

bool in(int vertice, int curSet)
{
  return 1<<vertice & curSet;
}

int clique()
{
	int max = 0;

	int numSets = 1<<n;
	
	for (int curSet = 1; curSet < numSets; curSet++)
	{
	  bool validSet = true;
	  
	  for (int i = 0; i < n; i++)
	  {
		//if (curSet == 29) cout << i << " " << in(i, curSet) << " " << (grafo[i] & curSet != 0) << endl;
		if (in(i, curSet) && ((grafo[i] & curSet) != 0))
		{
		  validSet = false;
		  break;
		}
	  }
	  
	  int t = bitset<MAX>(curSet).count();
	  //cout << curSet << " " << bitset<MAX>(curSet) << " " << validSet << " " << t << endl;
	  if (validSet && (max < t))
	  {
		max = t;
	  }
	}

	return max;
}


int main()
{
	int teste = 1;

	while (cin >> n)
	{
		if (n == 0) break;

		memset(grafo, 0, n*sizeof(int));
		
		for (int i = 0; i < n; i++)
		{
			int t;

			while (cin >> t)
			{
				if (t == 0) break;
				grafo[i] |= 1<<(t-1);
				grafo[t-1] |= 1<<i;
			}
			//cout << i << " " << (bitset<8>) grafo[i] << endl;
		}
		
		//for (int i = 0; i < n; i++) cout << (bitset<8>) grafo[i] << endl;

		cout << "Teste " << teste++ << endl;
		cout << clique() << endl;
		cout << endl;
	}
	
	return 0;
}