#include <stdio.h>
#include <algorithm>

using namespace std;

struct Pessoa
{
	int x;
	int y;
};

bool compare(const Pessoa& i, const Pessoa& j)
{
	if (i.y == j.y) return i.x < j.y;
	return i.y < j.y;
}

Pessoa tempos[10000];

int main()
{
	int n, tempoFim = 0, cnt = 0;

	scanf("%d\n", &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &tempos[i].x, &tempos[i].y);
	}
	
	sort(tempos, tempos+n, compare);
	
	for (int i = 0; i < n; i++)
	{
		if (tempos[i].x  >= tempoFim)
		{
			cnt++;
			tempoFim = tempos[i].y;
		}
		//printf("%d\n", tempos[i].idx);
	}
	
	printf("%d\n", cnt);
	
	return 0;
}
