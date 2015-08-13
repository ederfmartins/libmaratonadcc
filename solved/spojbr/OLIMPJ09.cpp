#include<stdio.h>
#include <algorithm>
using namespace std;

struct Pais{
	int id;
	int ouro;
};

bool comp(const Pais& a, const Pais& b)
{
	if (a.ouro > b.ouro) return true;
	else if (a.ouro < b.ouro) return false;
	else return a.id <= b.id;
}

Pais paises[101];

int main()
{
	int n, m, o, p, b;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		paises[i].id = i + 1;
		paises[i].ouro = 0;
	}
	
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &o, &p, &b);
		paises[o-1].ouro++;
		paises[p-1].ouro++;
		paises[b-1].ouro++;
	}
	
	sort(paises, paises+n, comp);
	for (int i = 0; i < n -1; i++) printf("%d ", paises[i].id);
	printf("%d\n", paises[n-1].id);
	
	return 0;
}
