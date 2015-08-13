#include<stdio.h>
using namespace std;

char estrada[1000000];
int main()
{
	int n, cnt = 0;
	scanf("%d\n%s", &n, estrada);
	
	for (int i = 0; estrada[i] != '\0'; i++) {
		switch (estrada[i]) {
			case 'P':
			case 'C': cnt += 2; break;
			case 'A': cnt++; break;
			//case 'D': break;
		}
	}
	
	printf("%d\n", cnt);
	
	return 0;
}

