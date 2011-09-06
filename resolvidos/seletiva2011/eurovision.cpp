#include <iostream>
#include <string>
#include <map>
#include <set>


using namespace std;
map<int, set<int> > ini;
int cnt;
int totalPaises;

void conta(int num, int paises[9], bool usados[9]){

	if (num == totalPaises)
	{
		cnt++;
//		for (int i = 0; i < ini.size(); i++) cout << paises[i];
//		cout << endl;
		return;
	}

	for (int i = 0; i < totalPaises; i++){
		if (!usados[i] && (num == 0 || (ini[paises[num -1]].count(i) == 0 && ini[i].count(paises[num-1]) ==0)))
		{
			paises[num] = i;
			usados[i] = true;
			conta (num + 1, paises, usados);
			usados[i] = false;
		}
	}
	
}

int main(){
	std::cout.sync_with_stdio(false);
	int n;

	cin >> n;
	for (int t = 1; t <= n; t++){
		int nPaises;
		bool  paisesUsados[9];
		int listaPaises[9];
		int ppp = 0;
		cnt = 0;
		map <string, int> paises;
		map<int , set<int> > inimigos;
		cin >> nPaises;

		for ( int i = 0; i < nPaises; i++){
			string pais; int ni; string tmp;
			paisesUsados[i] = false;
			listaPaises[i] = -1;

			cin >> pais >> ni;
			if (paises.count(pais) == 0)
			{
				paises[pais] = ppp++;
			}

			for (int j = 0; j < ni; j++){
				cin >> tmp;
				if (paises.count(tmp) == 0) paises[tmp] = ppp++;

				inimigos[paises[pais]].insert(paises[tmp]);
			}
		}

		totalPaises = ppp;
		ini = inimigos;	
		conta(0, listaPaises, paisesUsados);
		int numPer = cnt;
		cout << "Teste #" << t << ": " << numPer << endl;
	}
	return 0;
}

