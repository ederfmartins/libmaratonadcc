#include <stdio.h>
#include <inttypes.h>
#include <list>

using namespace std;

#define SIZE 102

char campo[SIZE][SIZE];
int n, m;

inline bool dentro(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

inline bool agua(int x, int y)
{
	if (!dentro(x, y)) return true;
	else return campo[x][y] == '.';
}

inline bool navio(int x, int y)
{
	if (!dentro(x, y)) return true;
	else return campo[x][y] == '*';
}

void imprime()
{
	for (int i = 0; i < n; i++) printf("%s\n", campo[i]);
}


int conta()
{	
	int cnt = 0;
	//imprime();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (campo[i][j] == '*') {
				//printf("campo[%d][%d]\n", i, j);
				
				list<pair<int, int> > vizinhos;
				int ok = 1;
				
				vizinhos.push_back(make_pair<int, int>(i, j));
				
				while (vizinhos.size() > 0)
				{
					pair<int, int> pedaco = vizinhos.front();
					vizinhos.pop_front();
					
					if (! dentro(pedaco.first, pedaco.second)) continue;
					
					if (campo[pedaco.first][pedaco.second] == '#') {ok = 0;}
					else if (campo[pedaco.first][pedaco.second] == '*') {
						campo[pedaco.first][pedaco.second] = 'v';
						
						vizinhos.push_back(make_pair<int, int>(pedaco.first-1, pedaco.second));
						vizinhos.push_back(make_pair<int, int>(pedaco.first+1, pedaco.second));
						vizinhos.push_back(make_pair<int, int>(pedaco.first, pedaco.second-1));
						vizinhos.push_back(make_pair<int, int>(pedaco.first, pedaco.second+1));
					}
				}
				
				//if (ok) campo[i][j] = 'x';
				
				cnt += ok;
			}
		}
	}
	//printf("\n");
	//imprime();
	
	return cnt;
}

int main()
{
	int k, x, y;
	
	scanf("%d %d\n", &n, &m);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%s\n", campo[i]);
	}
	
	scanf("%d\n", &k);
	
	for (int i = 0; i < k; i++)
	{
		scanf("%d %d\n", &x, &y);
		x--; y--;
		if (campo[x][y] == '#') campo[x][y] = '*';
	}

	printf("%d\n", conta());
	
	return 0;
}

