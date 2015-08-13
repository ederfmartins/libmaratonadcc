#include <stdio.h>
#include <inttypes.h>
using namespace std;

uint64_t vetor[100000];

int main()
{
	int T, n;
	scanf("%d", &T);
	
	for (int t = 0; t < T; t++) {
		scanf("%d", &n);
		uint64_t soma = 0;
		uint64_t total = 0;
		
		for (int i = 0; i < n; i++) {
			scanf("%lld", &vetor[i]);
		}
		
		for (int i = n-1 ; i >= 0 ; i--) {
			soma += vetor[i];
			if (soma >= 1300031) soma %= 1300031;
	 
			total += vetor[i] * soma;
			if (total >= 1300031) total %= 1300031;
		}
		
		printf("%lld\n", total);
	}
	
	return 0;
}

