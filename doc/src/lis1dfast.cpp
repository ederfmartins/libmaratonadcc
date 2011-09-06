// Longest Increasing Subsequence - LIS O(n log n)
#define fori(i, n) for ( int i = 0; i < (n); ++i )
void lis( const vector< int > & v, vector< int > & asw )
{
	vector<int> pd(v.size(),0), pd_index(v.size()), pred(v.size());
	int maxi = 0, x, j, ind;

	fori(i,v.size())
	{
		x = v[i];
		j = lower_bound( pd.begin(), pd.begin() + maxi, x ) - pd.begin();
		//j = upper_bound( pd.begin(), pd.begin() + maxi, x ) - pd.begin(); para lds
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
