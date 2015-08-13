#define TAM 10000
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
		for (int i = m -1; i > 0; i--)
		{
			if (A[i] > A[m] && c[i] + H[m] > c[m])
			{
				c[m] = c[i] + H[m];
			}
		}
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
