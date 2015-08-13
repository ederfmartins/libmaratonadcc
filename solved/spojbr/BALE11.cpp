#include <stdio.h>
#include <algorithm>
using namespace std;

#define min(a, b) (a) > (b) ? (b) : (a)

struct Dancarina
{
	int id;
	int habilidade;
};

int cnt;

bool comp(const Dancarina& d1, const Dancarina& d2)
{
	if (d1.habilidade < d2.habilidade) cnt++;
	
	return d1.habilidade > d2.habilidade;
}

Dancarina d[100000];

int main()
{
	int n;
	int a1;
	cnt = 0;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		d[i].id = n-1 -i;
		scanf("%d", &d[i].habilidade);
	}
	
	stable_sort(d, d+n, comp);
		
	printf("%d\n", n*(n-1)/2 - cnt);
	
	return 0;
}

