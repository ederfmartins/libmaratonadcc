#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Pessoa
{
	char nome[100];
	int habilidade;
};

bool compare(const Pessoa& i, const Pessoa& j)
{
	if (i.habilidade == j.habilidade) return strcmp(i.nome, j.nome) < 0;
	return i.habilidade > j.habilidade;
}

bool ord(const Pessoa& i, const Pessoa& j)
{
	return strcmp(i.nome, j.nome) < 0;
}

Pessoa pessoas[10000];
vector<Pessoa> times[1000];

int main()
{
	int n, t;

	scanf("%d %d\n", &n, &t);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%s %d\n", pessoas[i].nome, &pessoas[i].habilidade);
	}
	
	sort(pessoas, pessoas+n, compare);
	
	for (int i = 0; i < n; i++) {
		times[i%t].push_back(pessoas[i]);
	}
	
	for (int i = 0; i < t; i++) {
		sort(times[i].begin(), times[i].end(), ord);
		
		printf("Time %d\n", i+1);
		for (int j = 0; j < times[i].size(); j++) {
			printf("%s\n", times[i][j].nome);
		}
		printf("\n");
	}
	
	return 0;
}

