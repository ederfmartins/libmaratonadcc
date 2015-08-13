#include <stdio.h>

using namespace std;

int main()
{
	int n;
	int resp[100], minas[100];
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) scanf("%d", &minas[i]);
	
	if (n == 1) resp[0] = minas[0];
	else if (n == 2) {
		resp[0] = resp[1] = minas[0] + minas[1];
	}
	else {
		resp[0] = minas[0] + minas[1];
		resp[n-1] = minas[n-1] + minas[n-2];
		for (int i = 1; i < n-1; i++) {
			resp[i] = minas[i-1] + minas[i] + minas[i+1];
		}
	}
	
	for (int i = 0; i < n; i++) printf("%d\n", resp[i]);
	
	return 0;
}
