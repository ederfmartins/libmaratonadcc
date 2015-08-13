#include <stdio.h>
#include <set>
using namespace std;

int n;
set<int> numbers;

//subset sum - bem difícil...
int main()
{
	int tmp;
	bool finded = false;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0) break;
		
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &tmp);
			numbers.insert(tmp);
		}
	}
	return 0;
}

