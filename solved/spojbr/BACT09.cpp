#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;

int main()
{
	double maior;
	int n, a, b, melhor = 0;
	
	scanf("%d\n", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d\n", &a, &b);
		double atual = log(a)*b;
		
		if (atual > maior) {
			melhor = i;
			maior = atual;
		}
	}
	
	printf("%d\n", melhor);
	
	return 0;
}

