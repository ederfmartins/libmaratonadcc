#define TAM 100
#define BRANCO 0
#define CINZA 1
#define PRETO 2
bool grafo[TAM][TAM];
int pass[TAM];

bool dfs(int v)
{
	pass[v] = CINZA;

	for (int i = 0; i < TAM; i++)
	{
		if (grafo[v][i])
		{
			if (pass[i] == CINZA) return false;
			if (pass[i] == BRANCO && !dfs(i)) return false;
		}
	}

	pass[v] = PRETO;
	return true;
}

bool aciclico()
{
	memset(pass, BRANCO, TAM*sizeof(int));

	for (int i = 0; i < TAM; i++)
	{
		if (pass[i] == BRANCO)
		{
			if (!dfs(i)) return false;
		}
	}

	return true;	
}
