#include <stdio.h>

using namespace std;

int main()
{
	int maior, a, b, r;
	char op;
	
	scanf("%d\n%d %c %d\n", &maior, &a, &op, &b);
	switch (op)
	{
		case '+': r = a + b; break;
		case '*': r = a * b; break;
	}
	
	if (r > maior) printf("OVERFLOW\n");
	else printf("OK\n");
	
	return 0;
}

