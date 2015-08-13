#include<stdio.h>
using namespace std;

bool quemJogaGanha[1000010];

int resolveNim(int n, int m)
{
	for (int i = 1; i <= n; i++) {
		if (i <= m) quemJogaGanha[i] = true;
		else {
			quemJogaGanha[i] = false;
		
			for (int j = 1; j <= m; j++)
			{
				if (i - j > 0) {
					if (!quemJogaGanha[i-j]) {
						quemJogaGanha[i] = true;
						break;
					}
				}
			}
		}
		
		//printf("%d\n", quemJogaGanha[i]);
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	//resolveNim(n, m);
	
	if (m >= n) quemJogaGanha[n] = true;
	else {
		quemJogaGanha[n] = n % (m+1) != 0;
	}
	
	if (quemJogaGanha[n]) printf("Paula\n");
	else printf("Carlos\n");
	
	return 0;
}

