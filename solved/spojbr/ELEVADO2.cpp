#include <iostream>
using namespace std;

int main()
{
	int n, c, s, e, cnt = 0;
	char bla = 'N';
	
	cin >> n >> c;
	
	for (int i = 0; i < n; i++)
	{
		cin >> s >> e;
		cnt += e - s;
		if (cnt > c) bla = 'S';
	}

	cout << bla << endl;
	return 0;
}
