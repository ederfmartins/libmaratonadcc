int findMajority(int vec[], int n)
{
	int cnt = 0;
	int maior;
	for (int i = 0; i < n; i++)
	{
		if (cnt == 0) {maior = v; cnt = 1;}
		else if (v == maior) cnt++;
		else cnt--;
	}
	
	return maior;
}

