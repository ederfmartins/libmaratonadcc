#include <iostream>
using namespace std;

int main()
{
	int n, l, c, cnt = 0;
	
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> l >> c;
		if (l > c) cnt += c;
	}

	cout << cnt << endl;
	return 0;
}
