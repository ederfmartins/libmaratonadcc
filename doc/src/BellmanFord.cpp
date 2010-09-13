#define TAM 100

int nvertices, narestas;
int nadj[TAM];
bool dest[TAM][TAM];
double peso[TAM][TAM];

double dist[TAM];
int prev[TAM]; // para recuperar o caminho

/*retorna true se nao encontrar ciclo negativo e false em caso contrario*/
void bellmanFord(int source)
{
	bool achei;
	for (int i = 0; i < nvertices; i++)
	{
		dist[i] = INF;
		prev[i] = -1;
	}

	dist[source] = 0;

	for (int i = 0; i < nvertices -1; i++)
	{
		achei = false;

		for (int u = 0; u < nvertices; u++)
		{
			for (int v = 0; v < nadj[u]; v++)
			{
				if (dist[u] + peso[u][dest[u][v]] < dist[v])
				{
					achei = true;
					dist[v] = dist[u] + peso[u][dest[u][v]];
					prev[dest[u][v]] = u;
				}
			}
		}
		
		if (!achei)
		{
			return true;
		}
	}

	for (int u = 0; u < nvertices; u++)
	{
		for (int v = 0; v < nadj[u]; v++)
		{
			if (dist[u] + peso[u][dest[u][v]] < dist[v])
			{
				return false;
			}
		}
	}
	
	return true;
}
