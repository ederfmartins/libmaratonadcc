#include <iostream>
#include <string>
#include <set>
#include <map>

/*
 * 200 - Rare Order
 */

using namespace std;
map<char, set<char> > listaAdj; // armazena os elementos que precedem o elemento no grafo direcionado.

void topSort()
{
	while (listaAdj.size() > 0)
	{
		for (map<char, set<char> >::iterator mapIt = listaAdj.begin(); mapIt != listaAdj.end(); mapIt++)
		{
			set<char>& adj = (*mapIt).second;
			if ( adj.size() == 0)
			{
				char removed = (*mapIt).first;
				cout << removed;
				for (map<char, set<char> >::iterator it = listaAdj.begin(); it != listaAdj.end(); it++)
				{
					set<char>& c = (*it).second;
					if (c.count(removed) > 0) c.erase(removed);
				}
				listaAdj.erase(removed);
				break;
			}
		}
	}
	cout << endl;
}

int main()
{
	string word;
	string lastWord;
	
	cin >> lastWord;
	
	if (lastWord[0] != '#')
	{
		while( cin >> word)
		{
			if (word[0] == '#') break;
			
			int menor = word.size() < lastWord.size() ? word.size() : lastWord.size();
			for ( int i = 0; i < menor; i++)
			{
				if (word[i] != lastWord[i])
				{
					if (listaAdj.count(lastWord[i]) == 0) listaAdj[lastWord[i]] = set<char>();
					listaAdj[word[i]].insert(lastWord[i]);
					break;
				}
			}
			
			lastWord = word;
		}
		topSort();
		//system("pause");
	}
	
	return 0;
}
