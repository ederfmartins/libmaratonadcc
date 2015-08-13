#include <iostream>

/** 10019 - Funny Encryption Method */

using namespace std;

int countBits(int N) {
	int result = 0;
	while (N)
	{
		result++;
		N &= N-1;
	}
	return result;
}

int main()
{
	int n, N, b1, b2;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> N;
		b1 = countBits(N);
		b2 = countBits(N%10);

		do
		{
			N /= 10;
			b2 += countBits(N%10);
		} while (N > 0);

		cout << b1 << " " << b2 << endl;
	}

	return 0;
}

