#define UNVISITED -1

int grafo[SIZE][SIZE];
int prof[SIZE];
int sorted[SIZE];
int nordem;

void dfsTopsort(int no)
{
	for (int viz = 0; viz < SIZE; viz++)
	{
		if (grafo[no][viz])
		{
			if (prof[viz] == UNVISITED)
			{
				prof[viz] = prof[no] + 1;
				dfsTopsort(viz);
			}
		}
	}

	sorted[nordem--] = no;
}

void topSort(int nvt)
{
	memset(prof, UNVISITED, nvt*sizeof(int));
	nordem = nvt - 1;

	for (int i = 0; i < nvt; i++)
	{
		if (prof[i] == UNVISITED)
		{
			prof[i] = 0;
			dfsTopsort(i);
		}
	}
}
