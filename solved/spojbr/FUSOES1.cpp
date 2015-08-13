#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define SIZE 100001

struct DijointSet
{
    int element_count;
    int parent[SIZE];
    int rank[SIZE];
    
    DijointSet(int element_count)
	{
		this->element_count = element_count;
		memset(parent, 0, element_count*sizeof(int));
		memset(rank, 0, element_count*sizeof(int));

		for (int i = 0; i < element_count; ++i) parent[i] = i;
	}
	
	int find(int i)
	{
		if (i != parent[i])
		{
		    parent[i] = find(parent[i]);
		}
		return parent[i];
	}
  
	void fusion(int i, int j)
	{
		int x = find(i);
		int y = find(j);

		if (rank[x] > rank[y])
		{
		    parent[y] = x;
		}
		else
		{
		    parent[x] = y;
		    if (rank[x] == rank[y])
		    {
		        rank[y]++;
		    }
		}
	}
};

int main()
{
	int n, m, a, b;
	char c, r;
	
	scanf("%d %d\n", &n, &m);
	
	DijointSet bancos(n);
	
	for (int i = 0; i < m; i++)
	{
		scanf("%c %d %d\n", &c, &a, &b);
		a--; b--;
		
		if (c == 'F') bancos.fusion(a, b);
		else {
			r = bancos.find(a) == bancos.find(b)?'S':'N';
			printf("%c\n", r);
		}
	}
	
	return 0;
}

