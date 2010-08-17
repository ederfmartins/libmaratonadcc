#define TAM 1000

int grafo[TAM][TAM];
int pred[TAM];
int f[TAM][TAM];
bool visitados[TAM];

bool dfs(int s, int t, int size)
{
	visitados[s] = true;
	if(s == t) return true;

	for(int v = 0; v < size; v++)
	{
		if(grafo[s][v] - f[s][v] > 0 && !visitados[v])
		{
			pred[v] = s;
			if(dfs(v, t, size)) return true;
		}
	}

	return false;
}

bool findPath(int s, int t, int size)
{
	memset(visitados, false, sizeof(bool)*size);
	return dfs(s, t, size);
}

int maxFlow(int size, int s, int t)
{
	int delta;

	for(int i = 0; i < size; i++)
	{
		memset(f[i], 0, sizeof(int)*size);
	}

	pred[s] = s;

	while(findPath(s, t, size))
	{
		delta = INT_MAX;
		for(int c = t; pred[c] != c; c = pred[c])
		{
			delta = min(delta, grafo[pred[c]][c] - f[pred[c]][c]);	
		}

		for(int c = t; pred[c] != c; c = pred[c])
		{
			f[pred[c]][c] += delta;
			f[c][pred[c]] -= delta;
		}
	}

	int soma = 0;

	for(int i = 0; i < size; i++)
	{
		soma += f[i][t];
	}

	return soma;
}
