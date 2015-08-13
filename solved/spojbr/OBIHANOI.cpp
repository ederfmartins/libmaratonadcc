#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <inttypes.h>
#include <ctype.h>
#include <limits.h>

#include <algorithm>
#include <utility>
#include <iostream>

#include <map>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <sstream>

using namespace std;

#define abs(a) ((a) > 0 ? (a) : -(a))
#define TAM 50
uint64_t hanoi[TAM];

int main()
{
	int n, t = 1;
	uint64_t base = 1;
	
	for (int i = 0; i <= 30; i++)
	{
		hanoi[i] = base - 1;
		base *= 2;
	}

	while (1)
	{
		cin >> n;
		if (n == 0) break;
		
		cout << "Teste " << t++ << endl << hanoi[n] << endl << endl;
	}

	return 0;
}
