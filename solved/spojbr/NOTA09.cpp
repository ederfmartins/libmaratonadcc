#include <stdio.h>

using namespace std;


int main()
{
	int n;
	char nota;
	scanf("%d", &n);
	
	if (n == 0) nota = 'D';
	if (n <= 35) nota = 'D';
	else if (n <= 60) nota = 'C';
	else if (n <= 85) nota = 'B';
	else nota = 'A';
	
	printf("%c\n", nota);
	return 0;
}

