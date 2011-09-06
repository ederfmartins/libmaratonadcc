#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define TAM 10000
#define INF 1000000000
int c[TAM];
int A[TAM];
int H[TAM];

void ssctf(int n)
{
	for (int m = 1; m <= n; m++)
	{
		c[m] = H[m];
		for (int i = m -1; i > 0; i--)
		{
			if (A[i] < A[m] && c[i] + H[m] > c[m])
			{
				c[m] = c[i] + H[m];
			}
		}
	}
}

void ssdtf(int n)
{
	for (int m = 1; m <= n; m++)
	{
		c[m] = H[m];
		//printf("c[%d] = %d ", m, c[m]);
		for (int i = m -1; i > 0; i--)
		{
			if (A[i] > A[m] && c[i] + H[m] > c[m])
			{
				c[m] = c[i] + H[m];
				//printf("(%d, %d, c[i]=%d, h[m]=%d) ", i, c[m], c[i], H[m]);
			}
		}
		//printf("\n");
	}
}

int lis1d(int n, bool inc = true)
{
	if (inc) ssctf(n);
	else ssdtf(n);

	int max = 0;

	for (int i = 1; i <= n; i++)
		if (max < c[i])
			max = c[i];

	return max;
}

// Longest Increasing Subsequence − LIS O(n log n)
#define fori(i, n) for ( int i = 0; i < (n); ++i )
void lis( const vector< int > & v, vector< int > & asw )
{
	vector<int> pd(v.size(),0), pd_index(v.size()), pred(v.size());
	int maxi = 0, x, j, ind;

	fori(i,v.size())
	{
		x = v[i];
		j = lower_bound( pd.begin(), pd.begin() + maxi, x ) - pd.begin();
		pd[j] = x;
		pd_index[j] = i;
		if( j == maxi ) { maxi++; ind = i; }
		pred[i] = j ? pd_index[j-1] : -1;
	}
	// return maxi; se a sequencia nao precisa ser refeita
	
	int pos = maxi-1, k = v[ind];
	asw.resize( maxi );
	
	while ( pos >= 0 )
	{
		asw[pos--] = k;
		ind = pred[ind];
		k = v[ind];
	}
}


int main()
{
	int t, n;
	
	scanf("%d", &t);
	
	for (int i = 1; i <= t; i++)
	{
		scanf("%d", &n);
		for (int j = 1; j <= n; j++) scanf("%d", &A[j]);
		for (int j = 1; j <= n; j++) scanf("%d", &H[j]);
		
		int inc = lis1d(n, true);
		int dec = lis1d(n, false);
		
		if (inc >= dec) printf("Case %d. Increasing (%d). Decreasing (%d).\n", i, inc, dec);
		else printf("Case %d. Decreasing (%d). Increasing (%d).\n", i, dec, inc);
	}
	
	return 0;
}

