#include <iostream>
using namespace std;

int main()
{
	int l, d, k, p;
	
	cin >> l >> d >> k >> p;
	int custo = l/d * p + l*k;
	cout << custo << endl;
	return 0;
}
