#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cubo
{
	int verticesLabels[6];
	int arestas[6];
	
	friend Cubo& operator>>(Cubo& c1, Cubo& c2)
	{
		for (int i = 0; i < 6; i++) {
			c1.verticesLabels[i] = c2.verticesLabels[i];
			c1.arestas[i] = c2.arestas[i];
		}
	}
	
	friend istream& operator>>(istream& in, Cubo& c)
	{
		for (int i = 0; i < 6; i++) in >> c.verticesLabels[i];
		
		c.arestas[0] = 5; c.arestas[5] = 0;
		c.arestas[1] = 3; c.arestas[3] = 1;
		c.arestas[2] = 4; c.arestas[4] = 2;
	}
};

bool isomorfo(Cubo c1, Cubo c2)
{
	int indices[] = {0, 1, 2, 3, 4, 5};

	do
	{
		bool isIsomorfo = true;
		
		for (int i = 0; i < 6; i++)
		{
			if (c1.verticesLabels[i] != c2.verticesLabels[indices[i]]) {
				isIsomorfo = false;
				break;
			}
			
			if (indices[c1.arestas[i]] != c2.arestas[indices[i]]) {
				isIsomorfo = false;
				break;
			}
		}
		
		if (isIsomorfo) return true;
		
	} while ( next_permutation (indices, indices+6) );
	
	return false;
}

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0) break;
		vector <Cubo> cubos;
		
		for (int i = 0; i < n; i++)
		{
			Cubo c;
			cin >> c;
			
			if (cubos.size() == 0) cubos.push_back(c);
			else
			{
				bool igual = false;
				
				for (int j = 0; j < cubos.size(); j++)
				{
					bool b = isomorfo(c, cubos[j]);
					if (b)
					{
						igual = true;
						break;
					}
				}
				
				if (!igual) cubos.push_back(c);
			}
		}
		
		cout << cubos.size() << endl;
	}
	return 0;
}

