#include <stdio.h>
#include <map>
using namespace std;

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

int main()
{
	int n, v;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0) break;
		
		int cnt = 0;
		int maior = 0;
		
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &v);
			if (cnt == 0) {maior = v; cnt = 1;}
			else if (v == maior) cnt++;
			else cnt--;
		}
		
		printf("%d\n", maior);
		
	}
	return 0;
}

