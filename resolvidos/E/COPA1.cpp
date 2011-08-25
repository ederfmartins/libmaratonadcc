#include <iostream>
using namespace std;

int main()
{
	char times[20] = "ABCDEFGHIJKLMNOP";
	char quartas[8];
	char semi[4];
	char final[2];
	int a, b;
	
	for (int i = 0; i < 8; i++)
	{
		cin >> a >> b;
		if (a > b) quartas[i] = times[2*i];
		else quartas[i] = times[2*i + 1];
	}
	
	for (int i = 0; i < 4; i++)
	{
		cin >> a >> b;
		if (a > b) semi[i] = quartas[2*i];
		else semi[i] = quartas[2*i + 1];
	}
	
	for (int i = 0; i < 2; i++)
	{
		cin >> a >> b;
		if (a > b) final[i] = semi[2*i];
		else final[i] = semi[2*i + 1];
	}
	
	cin >> a >> b;
	if (a > b) cout << final[0] << endl;
	else cout << final[1] << endl;
	
	return 0;
}

