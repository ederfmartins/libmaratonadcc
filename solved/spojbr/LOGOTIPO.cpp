#include <stdio.h>
#include <vector>

using namespace std;

int tl, tc, pl, pc;
int P[10][10];
int T[350][250];


bool verifyMatch(int r, int c)
{
	for (int i = 0; i < pl; i++)
	{
		for (int j = 0; j < pc; j++)
		{
			if (T[r+i][c+j] != P[i][j])
			{
				return false;
			}
		}
	}
	
	return true;
}

#define MAX_PATTERN_SIZE 10010
int F[MAX_PATTERN_SIZE];
void build_failure_function(int pattern[], int patternSize)
{
	F[0] = -1;
	for (int i = 0; i < patternSize; i++)
	{
		F[i+1] = F[i] + 1;
		while ( F[i+1] > 0 && pattern[i] != pattern[ F[i+1]-1 ] )
			F[i+1] = F[ F[i+1]-1 ] + 1;
	}
}

// retorna a posicao inicial de cada ocorrencia de pattern em text
vector<int> KMP(int text[], int textSize, int pattern[], int patternSize)
{
	build_failure_function(pattern, patternSize);
	vector<int> start_positions;
	int j = 0, m = patternSize, n = textSize;
	
	for (int i = 0; i < n; i++) 
	{
		while ( true )
		{
			if ( text[i] == pattern[j] )
			{
				if ( ++j == m )
				{
					start_positions.push_back( i - m + 1 );
					j = F[j];
				}
				break;
			}
		
			if ( j == 0 ) break;
			j = F[j];
		}
	}

	return start_positions;
}

int match1()
{
	int cnt = 0;
	for (int i = 0; i <= tl-pl; i++) {
		vector<int> colunas = KMP(T[i], tc, P[0], pc);
		for (int j = 0; j < colunas.size(); j++) {
			if (verifyMatch(i, colunas[j])) {
				cnt++;
			}
		}
	}
	
	return cnt;
}

int main()
{	
	int teste = 1;
	while (1)
	{
		scanf("%d %d", &pl, &pc);
		if (pl == 0 && pc == 0) break;
		
		for (int i = 0; i < pl; i++)
			for (int j = 0; j < pc; j++)
				scanf("%d", &P[i][j]);
				
		int K;
		printf("Logotipo %d\n", teste++);
		scanf("%d %d %d", &K, &tl, &tc);
		int cnt = 0;
		
		for (int k = 0; k < K; k++)
		{
			for (int i = 0; i < tl; i++)
				for (int j = 0; j < tc; j++)
					scanf("%d", &T[i][j]);
			
			cnt += match1();
		}
		
		printf("%d\n\n", cnt);
	}
	
	return 0;
}

