//soma maxima dos elementos do vetor
#define MAX_SUM 10000
int n;
int vet[TAM];
bool m[MAX_SUM];

//M->soma maxima dos elementos do vetor c->soma procurada
bool subSetSum(int M, int c)
{
	for (int i = 0; i <= M; i++) m[i] = false;
	m[0] = true;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = M; j >= vet[i]; j--)
		{
			m[j] |= m[j - vet[i]];
		}
	}
	
	return m[c];
}
