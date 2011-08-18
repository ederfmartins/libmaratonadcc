#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

/** 2284. Palavras primas */

bool isPrime(int n)
{
	if (n < 0) return isPrime(-n);
	if (n == 1) return true;
	if (n < 5 || n % 2 == 0 || n % 3 == 0) return (n == 2 || n == 3);

	int maxP = sqrt(n) + 2;

	for (int p = 5; p < maxP; p += 6)
	{
		if (n % p == 0 || n % (p+2) == 0) return false;
	}
	return true;
}

int main()
{
	string word;

	while (cin >> word)
	{
		int cnt = 0;

		for (int i = 0; i < word.size(); i++)
		{
			if (word[i] >= 'a' && word[i] <= 'z') cnt += word[i] - 'a' + 1;
			else cnt += word[i] - 'A' + 27;
		}

		if (isPrime(cnt)) cout << "It is a prime word." << endl;
		else  cout << "It is not a prime word." << endl;
	}

	return 0;
}
