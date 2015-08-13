#include <stdio.h>
using namespace std;

#define TAM 22

int main()
{
	int n, p;
	char poodle[TAM][TAM] = {
		"Poodle",
		"Poodle",
		"Poodle", 
		"Poodle", 
		"Poodle", 
		"Poodle", 
		"Poodle", 
		"Pooodle", 
		"Poooodle", 
		"Pooooodle", 
		"Poooooodle", 
		"Pooooooodle", 
		"Poooooooodle", 
		"Pooooooooodle", 
		"Poooooooooodle", 
		"Pooooooooooodle", 
		"Poooooooooooodle", 
		"Pooooooooooooodle", 
		"Poooooooooooooodle", 
		"Pooooooooooooooodle",
		"Poooooooooooooooodle",
		};
	
	while (1)
	{
		scanf("%d %d", &n, &p);
		if (n == 0 && p == 0) break;
		
		int paginas = n/p;
		if (n%p != 0) paginas++;
		
		if (paginas > 20) paginas = 20;
		
		printf("%s\n", poodle[paginas]);
	}
	
	return 0;
}
