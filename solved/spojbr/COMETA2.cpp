#include <iostream>
using namespace std;

int main()
{
	int ano;
	cin >> ano;
	
	//cout << ano - 1976 << " " << (ano - 1976)%76 << endl;
	cout << ano + 76 - (ano - 1986)%76 << endl;
	
	return 0;
}
