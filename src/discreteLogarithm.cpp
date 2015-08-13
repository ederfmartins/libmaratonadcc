#define inv_mult( a, n ) axbmodc(a, 1, n)

long long discreteLlogarithm( long long b, long long n, long long p )
{
	if ( n == 1 ) return 0;
	
	map < long long, int > table;
	long long m = sqrt(p) + 1, pot = 1, pot2 = 1;
	
	for (int j = 0; j < m; j++)
	{
		if ( pot == n ) return j;
		table[( n * inv_mult( pot, p ) ) % p] = j;
		pot = ( pot * b ) % p;
	}
	
	for (int i = 0; i < m; i++)
	{
		if ( table.find( pot2 ) != table.end() ) return i * m + table[pot2];
		pot2 = ( pot * pot2 ) % p;
	}

	return -1;
}

