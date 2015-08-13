#include<stdio.h>
#include <algorithm>
using namespace std;

struct Pais{
	int id;
	int ouro;
	int prata;
	int bronze;
};

bool comp(const Pais& a, const Pais& b)
{
	if (a.ouro > b.ouro) return true;
	else if (a.ouro < b.ouro) return false;
	else {
		if (a.prata > b.prata) return true;
		else if (a.prata < b.prata) return false;
		else {
			if (a.bronze > b.bronze) return true;
			else if (a.bronze < b.bronze) return false;
			else {
				return a.id <= b.id;
			}
		}
	}
}

Pais paises[101];

int main()
{
	int n, m, o, p, b;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		paises[i].id = i + 1;
		paises[i].ouro = 0;
		paises[i].prata = 0;
		paises[i].bronze = 0;
	}
	
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &o, &p, &b);
		paises[o-1].ouro++;
		paises[p-1].prata++;
		paises[b-1].bronze++;
	}
	
	sort(paises, paises+n, comp);
	for (int i = 0; i < n -1; i++) printf("%d ", paises[i].id);
	printf("%d\n", paises[n-1].id);
	
	return 0;
}

