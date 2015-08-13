#include <iostream>
using namespace std;

int main()
{
	int v;
	cin >> v;
	
	if (v <= 10) cout << "7" << endl;
	else if (v <= 30) cout << v-10 + 7 << endl;
	else if (v <= 100) cout << (v-30)*2 + 20 + 7 << endl;
	else cout << 5*(v-100) + 140 + 20 + 7 << endl;
	
	return 0;
}
