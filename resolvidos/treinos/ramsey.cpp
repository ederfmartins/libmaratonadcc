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

using namespace std;

/**conjunto independente e/ou clique com 3 elementos*/

class result
{
	public:
	int x, y, z;
	bool amigos;
};

class resp
{
	std::map<string, int>& jogadores;
	vector<result> linhas;
	public:
	resp(std::map<string, int>& j) : jogadores(j) {}
	void add(int x, int y, int z, bool amigos)
	{
		result r;
		r.x = x; r.y = y; r.z = z; r.amigos = amigos;
		linhas.push_back(r);
	}

	friend ostream& operator <<(ostream& o, resp r)
	{
		map<int, string> invj;
		vector<string> resposta;
		for (std::map<string, int>::iterator it = r.jogadores.begin(); it != r.jogadores.end(); it++)
		{
			invj[(*it).second] = (*it).first;
		}
		for (int i = 0; i < r.linhas.size(); i++)
		{
			vector<string> bla;
			bla.push_back(invj[r.linhas[i].x]);
			bla.push_back(invj[r.linhas[i].y]);
			bla.push_back(invj[r.linhas[i].z]);
			sort(bla.begin(), bla.end());

			resposta.push_back(bla[0] + " " + bla[1] + " " + bla[2] + " sao " + (r.linhas[i].amigos? "amigos":"inimigos"));	
		}
		sort(resposta.begin(), resposta.end());
		for (int i = 0; i < resposta.size(); i++) o << resposta[i] << endl;
		return o;
	}

};

int main()
{
        int h = 1;
	int n;
	bool first = true;

        while (cin >> n)
        {
		if (n == -1) break;

		if (!first) cout << endl;
		first = false;

		map<string, int> jogadores;
		resp resposta(jogadores);
		string nome, name;
		int grafo[6][6];
		int visitado[6][6][6];

		for (int i = 0; i < 6; i++)
		{
			cin >> nome;
			jogadores[nome] = i;
			memset(grafo[i], 0, 6*sizeof(int));
			for (int j = 0; j < 6; j++) memset(visitado[i][j], 0, 6*sizeof(int));
		}

		for (int i = 0; i < n; i++)
		{
			cin >> nome >> name;
			grafo[jogadores[nome]][jogadores[name]] = 1;
			grafo[jogadores[name]][jogadores[nome]] = 1;
		}

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				for (int k = 0; k < 6; k++)
				{
					if (i != j && i != k && j != k)
					{
						if (grafo[i][j] & grafo[i][k] & grafo[j][k] & visitado[i][j][k] == 0)
						{
							resposta.add(i, j, k, true);
							visitado[i][j][k] = 1;
							visitado[i][k][j] = 1;
							visitado[j][k][i] = 1;
							visitado[j][i][k] = 1;
							visitado[k][i][j] = 1;
							visitado[k][j][i] = 1;
						}
						else if (grafo[i][j] == 0 && grafo[i][k] == 0 && grafo[j][k] == 0 && visitado[i][j][k] == 0)
						{
							resposta.add(i, j, k, false);
							visitado[i][j][k] = 1;
							visitado[i][k][j] = 1;
							visitado[j][k][i] = 1;
							visitado[j][i][k] = 1;
							visitado[k][i][j] = 1;
							visitado[k][j][i] = 1;
						}
					}
				}
			}
		}

		cout << "Instancia " << h++ << endl;
		cout << resposta;
        }
        return 0;
}

