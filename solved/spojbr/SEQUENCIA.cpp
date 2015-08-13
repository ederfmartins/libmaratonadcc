#include <stdio.h>

/** 2845. Sequencia A - programacao dinamica recursao*/

char lookupDinamico[30][2001];
int seq[30];

char expansaoDinamica(int left, int nivel)
{
	if(lookupDinamico[nivel][left]!=0)
	{
		return nivel+1;
	}
	else 
	{
		if(nivel==0)
		{
			return 0;
		}
		int i=nivel-1;
		while(i>0 && seq[i]+seq[nivel] > left)
		{
			i--;
		}
		if(i==0&&(seq[0]+seq[nivel] > left))
		{ // Sem chances
			return 0;
		}
		// Primeiro: Tenta com meu valor
		char comigo = expansaoDinamica(left-seq[nivel], i);
		if(comigo!=0)
		{
			if(comigo > 0) lookupDinamico[nivel][left]=-1;
			return nivel+1;
		}
		else
		{
			// Agora, tenta sem meu valor
			char semigo = expansaoDinamica(left, nivel-1);
			if(semigo!=0)
			{
				lookupDinamico[nivel][left] = semigo; // semigo contem o nivel do ultimo numero que deu match :)
			}
			return semigo;
		}
	}
}

int main() {
	int n;
	int caso=1;
	while(scanf("%d", &n)==1)
	{
		int i=0, j;
		char isA=1;
		while(i<n)
		{
			scanf("%d", seq+i);
			if(i>0&&seq[i]<=seq[i-1])isA=0;
			i++;
		}

		if(isA)
		{ // Passou ateh aqui...
			for(j=0;j<n;j++)
			{
				for(i=0; i<=seq[n-1]; i++)
				{
					lookupDinamico[j][i]=0;
				}
				lookupDinamico[j][seq[j]]=-1;
			}
			lookupDinamico[0][0]=-1; // nivel 0 (valor 1) faltando 0 -> achou soma

			for(i=2;i<n;i++)
			{
				isA=(expansaoDinamica(seq[i], i-1)==0);
				if(!isA) break;
			}
		}

		printf("Case #%d:", caso);
		for(i=0;i<n;i++)
		{
			printf(" %d", seq[i]);
		}
		printf("\n");

		if(isA!=0) printf("This is an A-sequence.\n");
		else printf("This is not an A-sequence.\n");
		caso++;
	}
	return 0;
}


