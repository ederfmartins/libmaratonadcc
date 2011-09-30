#include <iostream>
using namespace std;
/*8700. Escada muito facil ad hoc*/

int main()
{
	int n, ant, atual, cnt = 0;
	cin >> n;
	if (n > 0) cin >> ant;
	
	for (int i = 1; i < n; i++)
	{
		cin >> atual;
		if (atual - ant > 10) cnt += 10;
		else cnt += atual - ant;
		
		ant = atual;
	}
	
	cout << cnt + 10 << endl;
	return 0;
}

