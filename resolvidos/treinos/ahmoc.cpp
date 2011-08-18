#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <inttypes.h>
#include <ctype.h>

#include <algorithm>
#include <utility>
#include <iostream>

#include <map>
#include <set>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
        int h = 1;
	string n, arte;
	bool first = true;

        while (getline(cin, n))
        {
		if (n[0] == '0') break;

		if (!first) cout << endl;
		first = false;

		getline(cin, arte);

		cout << "Instancia " << h++ << endl;
		if (arte.find(n) != string::npos) cout << "verdadeira" << endl;
		else  cout << "falsa" << endl;
        }
        return 0;
}
