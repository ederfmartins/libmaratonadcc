#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <ctype.h>

using namespace std;

struct Pessoa
{
	char nome[20];
	int total;
};

string lower(const char* str)
{
	string l = "";
	
	for (int i = 0; str[i] != '\0'; i++)
		l += tolower(str[i]);
	
	return l;
}

bool myfunction (const Pessoa& i, const Pessoa& j) {
	if (i.total == j.total) return strcmp(i.nome, j.nome) == -1;
	return i.total > j.total;
}

void ler(Pessoa& p)
{
	int pontuacao[12];
	scanf("%s", p.nome);
	for (int i = 0; i < 12; i++)
		scanf("%d", &pontuacao[i]);
	
	sort (pontuacao, pontuacao+12);
	
	p.total = 0;
	for (int i = 1; i < 11; i++)
		p.total += pontuacao[i];
}

Pessoa competidores[1000];

int main()
{
	int teste=1, n;
	
	while (1)
	{
		scanf("%d", &n);
		if (n == 0) break;
		
		for (int i = 0; i < n; i++)
			ler(competidores[i]);
		
		sort(competidores, competidores+n, myfunction);
		
		printf("Teste %d\n", teste++);
		int posicao = 1;
		for (int i = 0; i < n; i++)
		{
			if (i > 0 && competidores[i].total < competidores[i -1].total)
				posicao = i+1;
			printf("%d %d %s\n", posicao, competidores[i].total, competidores[i].nome);
		}
		printf("\n");
	}
	
	return 0;
}
