#include <stdio.h>
#include <map>
using namespace std;

int main()
{
	int n, voto, vencedor = 0;
	map<int, int> votos;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &voto);
		votos[voto] += 1;
	}
	
	for (map<int, int>::iterator it = votos.begin(); it != votos.end(); it++)
	{
		if (it->second > votos[vencedor]) vencedor = it->first;
	}
	
	printf("%d\n", vencedor);
	return 0;
}

