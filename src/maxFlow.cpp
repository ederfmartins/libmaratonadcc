#define TAM 1000
#define MAX_INT 1000000

int grafo[TAM][TAM];
int pred[TAM];
int f[TAM][TAM];
bool visitados[TAM];
int fila[TAM];

bool bfs(int n, int ini, int fim)
{
	int no, s = 0, e = 0;
	fila[e++] = ini;

	while (s != e)
	{
		no = fila[s++];

		if (visitados[no] == 2) continue; 
		visitados[no] = 2;

		for (int i = 0; i < n; i++) 
		{
			if (visitados[i] < 2)
			{
				if(grafo[no][i] - f[no][i] > 0)
				{
					pred[i] = no;
					if (i == fim) return true;
					if(visitados[i] == 0)
					{
						fila[e++] = i;
						visitados[i] = 1;
					}
				}
			}
		}
	}

	return false;
}

bool dfs(int s, int t, int size)
{
	visitados[s] = true;
	if(s == t) return true;

	for(int v = 0; v < size; v++)
	{
		if(!visitados[v] && grafo[s][v] - f[s][v] > 0)
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
	pred[s] = s;
	// Aqui pode ser usado tanto busca em largura quanto em profundidade.
	// busca em largura geralmente apresenta tempos de execucao bem menores.
	return bfs(size, s, t);
	//return dfs(s, t, size);
}

int maxFlow(int size, int s, int t)
{
	int delta;

	for(int i = 0; i < size; i++)
	{
		memset(f[i], 0, sizeof(int)*size);
	}

	while(1)
	{
		bool path = findPath(s, t, size);
		if (!path) break;

		delta = MAX_INT;
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

