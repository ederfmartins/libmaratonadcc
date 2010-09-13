const int VT = 100;
const int AR = VT * VT;

struct grafo
{
	// lista de adjacencias representada na forma de vetor
	int nvt, nar;
	int dest[2 * AR];
	int adj[VT][2 * VT];
	int nadj[VT];

	int cap[AR]; // capacidade do arco
	int fluxo[AR];
	int ent[VT];

	int padj[VT], lim[VT], nivel[VT], qtd[VT];

	int inv(int a) { return a ^ 0x1; }
	int orig(int a) { return dest[inv(a)]; }
	int capres(int a) { return cap[a] - fluxo[a]; }

	void inic(int n = 0)
	{
		nvt = n;
		nar = 0;
		memset(nadj, 0, sizeof(nadj));
	}

	//////////////////////////////////////////////////////////////////////////////
	// Adiciona uma aresta ao grafo.
	//
	// "int u" apenas para Fluxos;
	//
	int aresta(int i, int j, int u = 0)
	{
		int ar = nar;
		cap[nar] = u;
		dest[nar] = j;
		adj[i][nadj[i]] = nar++;
		nadj[i]++;

		cap[nar] = 0;
		dest[nar] = i;
		adj[j][nadj[j]] = nar++;
		nadj[j]++;
		return ar;
	}

	void revbfs(int ini, int fim)
	{
		int i, no, viz, ar;
		queue<int> fila;
		
		memset(nivel, NULO, sizeof(nivel));
		memset(qtd, 0, sizeof(qtd));
		
		nivel[fim] = 0;
		fila.push(fim);
		
		while (!fila.empty()) 
		{
			no = fila.front();
			fila.pop();
			qtd[nivel[no]]++;
			
			for (i = 0; i < nadj[no]; i++) 
			{
				ar = adj[no][i];
				viz = dest[ar];

				if (cap[ar] == 0 && nivel[viz] == NULO)
				{
					nivel[viz] = nivel[no] + 1;
					fila.push(viz);
				}
			}
		}
	}

	int admissivel(int no)
	{
		while (padj[no] < nadj[no])
		{
			int ar = adj[no][padj[no]];
			if (nivel[no] == nivel[dest[ar]] + 1 && capres(ar) > 0) return ar;
			padj[no]++;
		}
		
		padj[no] = 0;
		return NULO;
	}
	
	int retrocede(int no)
	{
		int i, ar, viz, menor = NULO;
		
		if (--qtd[nivel[no]] == 0) return NULO;
		
		for (i = 0; i < nadj[no]; i++)
		{
			ar = adj[no][i]; viz = dest[ar];
			if (capres(ar) <= 0) continue;
			if (menor == NULO || nivel[viz] < nivel[menor]) menor = viz;
		}

		if (menor != NULO) nivel[no] = nivel[menor];
		qtd[++nivel[no]]++;

		return ((ent[no] == NULO) ? no : orig(ent[no]));
	}

	int avanca(int no, int ar)
	{
		int viz = dest[ar];
		ent[viz] = ar;
		lim[viz] = min(lim[no], capres(ar));
		return viz;
	}
	
	int aumenta(int ini, int fim) 
	{
		int ar, no = fim, fmax = lim[fim];
		
		while (no != ini)
		{
			fluxo[ar = ent[no]] += fmax;
			fluxo[inv(ar)] -= fmax;
			no = orig(ar);
		}

		return fmax;
	}

	int maxflow(int ini, int fim)
	{
		int ar, no = ini, fmax = 0;
		
		memset(fluxo, 0, sizeof(fluxo));
		memset(padj, 0, sizeof(padj));
		
		revbfs(ini, fim);
		
		lim[ini] = INF;
		ent[ini] = NULO;
		
		while (nivel[ini] < nvt && no != NULO)
		{
			if ((ar = admissivel(no)) == NULO)
			{
				no = retrocede(no);
			}
			else if ((no = avanca(no, ar)) == fim) 
			{
				fmax += aumenta(ini, fim);
				no = ini;
			}
		}
		return fmax;
	}
};
