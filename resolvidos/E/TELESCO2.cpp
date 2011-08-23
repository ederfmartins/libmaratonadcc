#include <iostream>
using namespace std;

int main()
{
	int a, n, f, cnt = 0;
	
	cin >> a >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> f;
		if (a*f >= 40000000 ) cnt++;
	}

	cout << cnt << endl;
	return 0;
}
