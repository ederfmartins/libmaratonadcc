// F[i] - size of the largest prefix of pattern[0..i] that is also a
// suffix of pattern[1..i]. Ex: pattern = {a,b,a,c,a,b}, F = {0,0,1,0,1,2}
#define MAX_PATTERN_SIZE 10010
int F[MAX_PATTERN_SIZE];
void build_failure_function( const string & pattern )
{
	int m = pattern.size();
	F[0] = -1;
	for (int i = 0; i < m; i++)
	{
		F[i+1] = F[i] + 1;
		while ( F[i+1] > 0 && pattern[i] != pattern[ F[i+1]-1 ] )
			F[i+1] = F[ F[i+1]-1 ] + 1;
	}
}

// retorna a posicao inicial de cada ocorrencia de pattern em text
vector<int> KMP( const string & text, const string & pattern )
{
	build_failure_function( pattern );
	vector<int> start_positions;
	int j = 0, m = pattern.size(), n = text.size();
	
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
