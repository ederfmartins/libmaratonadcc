#include <stdio.h>

using namespace std;

int main()
{
	int a, b, c, tmp;
	
	scanf("%d %d %d", &a, &b, &c);
	
	if (a >= b+c || b >= a+c || c >= a+b) printf("n\n");
	else {
		if (a < b) {tmp = a; a = b; b = tmp;}
		if (a < c) {tmp = a; a = c; c = tmp;}
		
		if (a*a == b*b + c*c) printf("r\n");
		else if (a*a > b*b + c*c) printf("o\n");
		else printf("a\n");
	}
	
	return 0;
}
