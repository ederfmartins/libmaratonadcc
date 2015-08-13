#include <iostream>
using namespace std;

int main()
{
	int n, m, v, max = 0;
	int somaL[100], somaC[100];
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) somaL[i] = 0;
	for (int i = 0; i < m; i++) somaC[i] = 0;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v;
			somaL[i] += v;
			somaC[j] += v;
		}
	}
	
	for (int i = 0; i < n; i++)
		if (somaL[i] > max) max = somaL[i];
	
	for (int i = 0; i < m; i++)
		if (somaC[i] > max) max = somaC[i];
		
	cout << max << endl;
	
	return 0;
}
