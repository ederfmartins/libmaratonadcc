#include <iostream>
#include <map>
#include <string>
using namespace std;

#define min(a, b) ((a) < (b) ? (a) : (b))

#define TAM 1001
map<string, int> nomes;
string invnomes[TAM];
int pred[TAM];
int n;

int grau(int a, int b)
{
	if (a == -1 || b == -1) return 1000000000;
	if (a == b) return 0;
	else
	{
		int g1 = grau(pred[a], b);
		int g2 = grau(a, pred[b]);
		return 1 + min(g1, g2);
	}
}

int main()
{
	string pai, filho;
	int no = 0;
	cin >> n;

	for (int i = 0; i < n+1; i++) pred[i] = -1;

	for(int i = 0; i < n; i++)
	{
		cin >> pai >> filho;
		
		if (nomes.count(pai) == 0)
		{
			nomes[pai] = no;
			invnomes[no] = pai;
			no++;
		}
		if (nomes.count(filho) == 0)
		{
			nomes[filho] = no;
			invnomes[no] = filho;
			no++;
		}
		
		pred[nomes[filho]] = nomes[pai];
	}

	int maiorGrau = 0, a, b;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			//cout << "g " << invnomes[i] << " " << invnomes[j];
			int g = grau(i, j);
			//cout << " " << g << endl;
			
			if (g > maiorGrau)
			{
				maiorGrau = g;
				a = i;
				b = j;
			}
		}
	}
	
	if (invnomes[a] < invnomes[b]) cout << invnomes[a] << " " << invnomes[b] << " " << maiorGrau << endl;
	else cout << invnomes[b] << " " << invnomes[a] << " " << maiorGrau << endl;
	
	return 0;
}

