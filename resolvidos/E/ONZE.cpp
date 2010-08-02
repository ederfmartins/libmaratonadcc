#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

/** 2844.Você pode dizer 11 */

int main()
{
	//string n;
	char n[1001];
	bool para;

	while (1)
	{
		long int si = 0, sp = 0;

		cin.getline(n, 1001);
		int tam = strlen(n);
		para = true;

		for (int i = 0; i < tam; i++)
		{
			if (n[i] != '0') { para = false; break; }
		}

		if (para == true) break;

		for (int i = tam - 1; i >= 0; i = i - 2)
		{
			si += n[i] - '0';
		}

		for (int i = tam - 2; i >= 0; i = i - 2)
		{
			sp += n[i] - '0';
		}

		if ((si - sp) % 11 == 0) cout << n << " is a multiple of 11." << endl;
		else cout << n << " is not a multiple of 11." << endl;
	}

	return 0;
}

