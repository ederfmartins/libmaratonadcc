#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// 273 TeX Quotes

int main()
{
	char c;
	bool opened = false;

	while( cin.get(c) )
	{
		if (c == '"')
		{
			if (opened) { cout << "''"; opened = false;}
			else { cout << "``"; opened = true;}
		}
		else cout << c;
	}
	return 0;
}

