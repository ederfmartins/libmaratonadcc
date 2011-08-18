#include <iostream>

using namespace std;

int main()
{
	int n, t = 1;
	int i, j, k, l;

	while (cin >> n)
	{
		if (n == 0) break;

		i = n/50; n %= 50;
		j = n/10; n %= 10;
		k = n/5; n %= 5;
		l = n;

		cout << "Teste " << t++ << endl;
		cout << i << " " << j << " " << k << " " << l << endl;
	}
	return 0;
}
