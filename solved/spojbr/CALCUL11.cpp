#include <stdio.h>
#include <inttypes.h>

using namespace std;

int main()
{
	int n, v;
	char op;
	int espoentes[10];
	for (int i = 0; i < 10; i++) espoentes[i] = 0;
	
	scanf("%d", &n);
	uint64_t mult = 1;
	uint64_t div = 1;
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d %c", &v, &op);
		
		if (op == '*') espoentes[v]++;
		else espoentes[v]--;
	}
	
	espoentes[2] += 2*espoentes[4];
	espoentes[4] = 0;
	
	espoentes[2] += espoentes[6];
	espoentes[3] += espoentes[6];
	espoentes[6] = 0;
	
	espoentes[2] += 3*espoentes[8];
	espoentes[8] = 0;
	
	espoentes[3] += 2*espoentes[9];
	espoentes[9] = 0;
	
	for (int i = 1; i < 10; i++)
	{
		uint64_t tmp = 1;
		if (espoentes[i] > 0) {
			for (int j = 0; j < espoentes[i]; j++) tmp *= i;
			mult *= tmp;
		}
		else {
			for (int j = 0; j < -espoentes[i]; j++) tmp *= i;
			div *= tmp;
		}
	}
	
	printf("%lld\n", mult/div);
	
	return 0;
}

