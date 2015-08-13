#include <stdio.h>
#include <inttypes.h>

using namespace std;

uint64_t linha[1000];
uint64_t coluna[1000];
uint64_t diagonal1;
uint64_t diagonal2;

void imp(uint64_t vec[], int n)
{
	for (int i = 0;i < n; i++) printf("%lld ", vec[i]);
	printf("\n");
}

int numeros[1000000];

int main()
{
	int n, n2;
	uint64_t tmp;
	bool ok = true;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		linha[i] = 0;
		coluna[i] = 0;
		diagonal1 = 0;
		diagonal2 = 0;
	}
	
	n2 = n*n;
	
	for (int i = 0; i < n2; i++) numeros[i] = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%lld", &tmp);
			
			if (tmp < 1 || tmp > (uint64_t)n2) {
				ok = false;
				break;
			}
			
			numeros[tmp-1] = 1;
			
			linha[i] += tmp;
			coluna[j] += tmp;
			if (i == j) diagonal1 += tmp;
			if (i == n-1-j) diagonal2 += tmp;
		}
	}
	
	for (int i = 0; i < n2; i++)
		if (numeros[i] == 0) {
			ok = false;
			break;
		}
	
	if (diagonal1 != diagonal2) ok = false;
	
	if (ok)
	for (uint64_t i = 0; i < n; i++) {
		if (linha[i] != diagonal1 || coluna[i] != diagonal1) {
			ok = false;
			break;
		}
	}
	
	if (ok) printf("%lld\n", linha[0]);
	else printf("0\n");
	return 0;
}

