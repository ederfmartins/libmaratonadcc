#include <stdio.h>
#include <algorithm>

using namespace std;

struct Pessoa
{
	int idx;
	int tempo;
};

bool compare(const Pessoa& i, const Pessoa& j)
{
	if (i.tempo == j.tempo) return i.idx < j.idx;
	return i.tempo < j.tempo;
}

Pessoa tempos[110];

int main()
{
	int n, m, tmp;

	scanf("%d %d\n", &n, &m);
	
	for (int i = 0; i < n; i++)
	{
		tempos[i].idx = i+1;
		tempos[i].tempo = 0;
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &tmp);
			tempos[i].tempo += tmp;
		}
	}
	
	sort(tempos, tempos+n, compare);
	
	for (int i = 0; i < 3; i++) printf("%d\n", tempos[i].idx);
	
	return 0;
}

