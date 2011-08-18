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

/** 264 - Count on Cantor
 * uma pequena adaptacao de uma bserch()
 */

using namespace std;

int main()
{
	int n, n1;
	int linha, coluna;

	while (cin >> n)
	{
		int an = 1;
		n1 = n;

		while (n - an > 0)
		{
			n -= an;
			an++;
		}

		if (an%2 == 0)
		{
			//impar subindo tenho que descer
			//cout << n << " " << an << endl;
			linha = 1; coluna = an;
			while (n > 1) {linha++; coluna--; n--;}
		}
		else
		{
			//par descendo tenho que subir
			//cout << n << " " << an << endl;
			linha = an; coluna = 1;
			while (n > 1) {linha--; coluna++; n--;}
		}

		cout << "TERM " << n1 << " IS " << linha << "/" << coluna << endl;
	}
	return 0;
}

