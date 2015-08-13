#include <iostream>
using namespace std;

int busca(int low, int upper, int k)
{
	if (low > upper) return 0;
	if (k == 1) return (upper - low)/2;
	
	int m = low + (upper - low)/2;
	int l = busca(low, m, k-1);
	int u = busca(m, upper, k-1);
	
	//cout << low << " " << upper << " " << m << " " << max(l, u) + 1 << endl;
	return max(l, u) + 1;
}

int main()
{
	int n, k, cnt = 0;
	cin >> n >> k;
	
//	while (k > 1 && n > 0)
//	{
//		n = n/2;
//		cnt++;
//		k--;
//	}
//	if (n != 0) cnt += n;
//	cout << cnt << endl;
	cout << busca(1, n, k) << endl;
	return 0;
}

