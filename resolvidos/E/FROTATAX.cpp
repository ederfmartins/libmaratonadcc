#include <iostream>
using namespace std;

int main()
{
	double a, g, ra, rg;
	
	cin >> a >> g >> ra >> rg;
	if (ra/a > rg/g) cout << "A" << endl;
	else cout << "G" << endl;
	
	return 0;
}
