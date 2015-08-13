#define TAM 200

bool grafo[TAM][TAM];
int pass[TAM];
int n;

bool bipartido(int v, int color = 1)
{
	pass[v] = color;
	int thisColor = color;
	bool ret = true;

	color = color == 1 ? 2 : 1;

	for (int i = 0; i < n; i++)
	{
		if (grafo[v][i])
		{
			if (!pass[i]) ret = dfs(i, color);
			else if (pass[i] == thisColor) return false;

			if (!ret) return false;
		}
	}

	return ret;
} 
